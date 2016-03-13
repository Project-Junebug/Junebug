#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "questionlist.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>

#define LABEL_MIN 120
#define LABEL_MAX 180
#define DEBUG_MENU_ENABLED true

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    newGame(false);

    ui->lineEdit->setPlaceholderText("Put your answer here...");

    ui->label->setWordWrap(true);
    ui->label->setAlignment(Qt::AlignTop);
    ui->label->setAlignment(Qt::AlignLeft);

    ui->menuDebug->setVisible(DEBUG_MENU_ENABLED);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_nextButton_clicked(){
    bool l_correct=false;
    if(m_current.s_type==PageType::Info){
        l_correct=true;
    } else if(checkAnswer(ui->lineEdit->displayText())){
        l_correct=true;
    }
    if(l_correct){
        nextQuestion();
    } else {
        QMessageBox(QMessageBox::Icon::Critical, "Incorrect Answer", "Incorrect Answer").exec();
    }
}

void MainWindow::nextQuestion(){
    m_current=mp_list->getNextQuestion();
    ui->lineEdit->clear();
    refresh();
    if(m_current.s_type==PageType::Terminator) {
        ui->nextButton->hide();
    }
}

void MainWindow::on_actionSave_triggered(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                    tr("Save Files (*.sav)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
        } else {
            QTextStream stream(&file);
            stream << mp_list->getSaveData();
            stream.flush();
            file.close();
        }
    }
}


void MainWindow::on_actionLoad_triggered(){
    if(!newGame(true)){
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                                    tr("Save Files (*.sav)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        auto l_saveData = in.readAll();

        auto iter = l_saveData.split(SAVE_SPLIT);

        for(QString i: iter){
            if(m_current.s_type==PageType::Terminator){
                break;
            } else if(checkAnswer(i)){
                m_current=mp_list->getNextQuestion();
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Could Not Load Save"));
                break;
            }
        }
        refresh();
        file.close();
    }
}

bool MainWindow::newGame(bool prompt){
    if(!prompt || QMessageBox::Yes == QMessageBox(QMessageBox::Information, "New Save", "This will erase your current save.\n"
                                                  "Are you really sure you want to do this?", QMessageBox::Yes|QMessageBox::No
                                                  ).exec()){
        mp_list = new QuestionList();
        m_current=mp_list->getNextQuestion();
        refresh();
        return true;
    } else {
        return false;
    }
}

void MainWindow::on_actionNew_triggered(){
    newGame(true);
    refresh();
}

void MainWindow::refresh(){
    ui->label->setText(m_current.s_question);
    if(m_current.s_type==PageType::Info||m_current.s_type==PageType::Terminator){
        ui->lineEdit->hide();
        ui->label->setFixedHeight(LABEL_MAX);
        if(m_current.s_type==PageType::Terminator)
            ui->nextButton->hide();
    } else {
        ui->lineEdit->show();
        ui->label->setFixedHeight(LABEL_MIN);
        ui->lineEdit->setPlaceholderText(m_current.s_prompt);
    }
}

bool MainWindow::checkAnswer(QString answer){
    bool l_correct=false;
    if(m_current.s_type==PageType::Info){
        l_correct=true;
    } else if(answer.toLower()==m_current.s_answer.toLower()){
        l_correct=true;
    }
    return l_correct;
}

void MainWindow::on_lineEdit_returnPressed(){
    on_nextButton_clicked();
}

void MainWindow::errorMsg(){
    QMessageBox::critical(this, tr("Error Code 6"), tr("Invalid Permissions"));
}

void MainWindow::on_actionConsole_triggered(){
    errorMsg();
}

void MainWindow::on_actionAuto_generate_Save_File_triggered(){
    errorMsg();
}

void MainWindow::on_actionAdd_triggered(){
    errorMsg();
}

void MainWindow::on_actionInsert_triggered(){
    errorMsg();
}

void MainWindow::on_actionDelete_triggered(){
    errorMsg();
}

void MainWindow::on_actionEdit_triggered(){
    errorMsg();
}

void MainWindow::on_actionEdit_All_triggered(){
    errorMsg();
}
