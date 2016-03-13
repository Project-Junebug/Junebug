#include <sstream>
#include <cstring>

#include "questionlist.h"

Page QuestionList::getNextQuestion() const {
    m_counter++;
    assert(m_counter<=m_list.size());

    Page ret = m_list.at(m_counter-1);
    std::stringstream stream;
    stream<<m_numbers.at(m_counter-1)<<") "<<ret.s_question.toStdString();
    ret.s_question=stream.str().c_str();

    return ret;
}

QString QuestionList::getSaveData() const {
    QString ret("");
    for(unsigned int i=0; i<m_counter-1; i++){
        if(m_list.at(i).s_type==PageType::Question){
            ret.append(m_list.at(i).s_answer);
        }
        if(i<m_counter-2){
            ret.append(SAVE_SPLIT);
        }
    }
    return ret;
}
