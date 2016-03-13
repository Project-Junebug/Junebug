#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include <QString>
#include <QDebug>

#include <vector>
#include <cassert>

#define HTML_TAB &#09;
#define SAVE_SPLIT "\u0011"

enum class PageType : char {
    Info,
    Question,
    Terminator
};

struct Page {
    PageType s_type;
    QString s_question;
    QString s_answer;

    QString s_prompt;

    Page(PageType type, QString question, QString answer="", QString prompt="Put your answer here..."){
        s_type=type;
        s_question=question;
        s_answer=answer;
        s_prompt=prompt;
    }
    Page(){
        s_type=PageType::Terminator;
        s_prompt=s_answer=s_question="SOMETHING'S CLEARLY WRONG WITH THIS";

    }

};

class QuestionList {
public:
    QuestionList()=default;

    Page getNextQuestion() const;
    QString getSaveData() const;
private:
    unsigned mutable int m_counter = 0;
    const std::string m_numbers = "1618033988749894848204586834365638117720309179805762862135448622705260462818902449707207204189"
                                  "3911374847540880753868917521266338622235369317931800607667263544333890865959395829056383226613"
                                  "1992829026788067520876689250171169620703222104321626954862629631361443814975870122034080588795";
    const std::vector< Page > m_list = {
        {PageType::Info, "Hello there! If you're reading this, it means that I'm not too lazy to let this project slip into "
         "the endless pit that is my incomplete projects. I suppose I better give a little backstory.\n\n"

         "Back on the 14th of December 2015, made a several posts on a variety of social media sites with only a "
         "single message: \"79 days until March 2nd.\" Many people were obviosly confused and I slowly drip-fed a "
         "variety of conflicting information about \"Project Junebug.\" Over the 2015/16 Christmas holidays I "
         "started developing the application you see before you."},

        {PageType::Question, "To be able to complete the questions, you will need to be able to think outside of the box, make puns "
         "and Google properly. You will need that last one a lot. If you try to cheat or lie about completing it, or try to engineer a"
         "save file, you will fail. If you manage to decompile this, however, you deserve the prize."
         "\n\nOh, and I should have given you a password along with this, unless I am distributing this before March 2nd. "
         "Just plonk it down there for me.", "two-hundred-and-forty-one", "Put the password here..."},

        {PageType::Info, "I've probably promised a prize in one form or another and the first person (or team) to comlete the quiz "
         "will get this prize. Now, enough chat, let's begin with somthing nice and simple."},

        {PageType::Question, "Test question?", "Test answer"},
        {PageType::Info, "Looks like you're going to do well on this. Every now and again I'm going to break up the questions "
         "with some entirely random information (or is it?)."},
        {PageType::Question, "What is the name of the \"#\" character?", "hash"},
        {PageType::Info, "Honestly, how many of you put \"hashtag\"?"},

        {PageType::Question, "On page 265 of volume 9 of shelf 5 of wall 1 of hex 314 in the library of babel, what are the "
         "characters preceeding the first full stop?", "mvlvfkw"},

        {PageType::Info, "What follows is a series of questions concerning fish."},
        {PageType::Question, "What fish, when multiplied by 2, has 4 strings?", "bass"},
        {PageType::Question, "What fish is numbered SS-224?", "Cod"},
        {PageType::Question, "What fish painted the following? \n"
         "pi*((4*arctan(0.2)-arctan(239^-1))^-1)+1", "Pollock"},
        {PageType::Info, "That's enough of that."},

        {PageType::Question, "What letters can flip flop?\n\n"
         "Delimit your answers with a comma and put them in alphabetical order, e.g.:\n"
         "A,B,C,D", "D,JK,T"},
        {PageType::Question, "If 1 is TRUE and 0 is FALSE, what are the following:"
         "Delimit your answers with a comma and put them in alphabetical order, e.g.:\n"
         "0,0,0\n"
         "(0 NAND (1 AND 1)) XNOR ((1 OR 0) XOR (0 NOR 1))\n"
         "((1 XNOR 1) AND ((1 NAND 0) OR (NOT 0)) NOR (0 XOR 1)\n"
         "(((1 OR (1 OR 0)) NOR (0 NOR 0)) XOR (0 XOR 1)) XNOR (1 XNOR 1)",
         "1,0,1"},
        {PageType::Info, "<html><a href=\"goo.gl/ikdrZO\">goo.gl/5PsN72</a></html>"},
        {PageType::Question, "If c is the speed of light, what speed would I be going if I start at 0.5c and accelerate by 0.5c?\n"
         "Give your answer as a multiple of c, e.g.: Your answer is \"2c\", you write \"2\"", "0.8"},
        {PageType::Info, "54 68 69 73 20 69 73 20 63 6f 6d 70 6c 65 74 65 6c 79 20 69 72 72 65 6c 65 76 61 6e 74 20 61 6e 64 20 "
         "79 6f 75 27 76 65 20 77 61 73 74 65 64 20 79 6f 75 72 20 74 69 6d 65 20 6d 61 6e 75 61 6c 6c 79 20 74 79 70 "
         "69 6e 67 20 74 68 69 73 20 6f 75 74 2e"},
        {PageType::Question, "This is not a question.", "This is not an answer"},

        {PageType::Question, "If * is a pointer what is a reference?", "&"},
        {PageType::Question, "Good luck, I'm behind some proxies.\nHow many proxies am I behind?", "7"},
        {PageType::Question, "What kind of bells does the exorcist play?", "tubular"},

        {PageType::Question, "If \"effort\"=70, \"knowledge\"=96, and \"attitude\"=100, what are the following:\n"
         "\"whiskey\", \"alcoholism\", and \"not doing homework\"\n"
         "Delimit your answers with a comma, e.g.: 1,2,3","100,107,206"},
        {PageType::Info, "<html>I used the following Python (3.5.1) function to calculate the answers for that:<br>"
         "<code>def value(inp: str) -> int:<br>"
         "    total=0<br>"
         "    for i in inp:<br>"
         "        try:<br>"
         "            total+=string.ascii_lowercase.index(i)+1<br>"
         "        except: pass<br>"
         "    return total</code><br>"
         "(look, I'm sorry for the non-indentation. HTML inside Qt is hard.)</html>"},
        {PageType::Question, "If \"leopard\"=60, \"three\"=8, and \"qi\"=11, what are the following:\n"
         "\"samba\", \"dribble\", and \"print\"\n"
         "Delimit your answers with a comma, e.g.: 1,2,3", "9,62,7"},

        {PageType::Question, "What is F+A?", "19"},
        {PageType::Question, "<html>Who invented <a href=\"i.imgur.com/qY5NmcW.png\">these</a>?<br> If the link's broken, right "
         "click and copy it manually</html>", "Richard Feynman"},
        {PageType::Question, "What is the most common name for the head of the Catholic Church?", "pope"},
        {PageType::Question, "What kind of encounter is the following from?\n"
         "G A   F C\n"
         "      F", "third"},
        {PageType::Question, "What Shapely algorithm can be used to get a stable marriage?", "gale"},
        {PageType::Question, "Is Valve Time faster or slower than real time?", "slower"},
        {PageType::Question, "When is September 1st, 1998, according to Valve Time?", "October 1997"},
        {PageType::Question, "<html>What is <a href=\"mathurl.com/j9zd87b\">this</a> the n<sup>th</sup> term of?<br> If the link's broken, right "
         "click and copy it manually</html>", "Fibonacci Sequence"},

        {PageType::Question, "What constant has been spelled out in the question numbers?","phi"},
        {PageType::Terminator, "The final challenge is a treasure hunt that will lead you to a phone number. Once you call the number, "
         "announce that you are calling to claim the prize and quote the following password:\n"
         "\"password1234\"\n"
         "Are you ready? Excellent, let's begin:\n"
         "A703OxuIL6U"}//project.junebug.contact@gmail.com
    };
};

#endif // QUESTIONLIST_H
