#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "questionlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    bool newGame(bool prompt);
    void nextQuestion();
    void refresh();
    bool checkAnswer(QString answer);
    void errorMsg();

    Ui::MainWindow *ui;

    QuestionList *mp_list;
    Page m_current;

private slots:
    void on_nextButton_clicked();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionNew_triggered();

    void on_lineEdit_returnPressed();

    void on_actionConsole_triggered();
    void on_actionAuto_generate_Save_File_triggered();
    void on_actionAdd_triggered();
    void on_actionInsert_triggered();
    void on_actionDelete_triggered();
    void on_actionEdit_triggered();
    void on_actionEdit_All_triggered();
};

#endif // MAINWINDOW_H
