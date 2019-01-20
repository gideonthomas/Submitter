#ifndef SICT_SUBMITTER_H_
#define SICT_SUBMITTER_H_
#include "debug.h"
#include "Vals.h"
#include "SubVals.h"
#include "Command.h"
#include "Date.h"
#include "User.h"
// define statements

//  version
#ifdef SUBMITTER_VERSION
# undef SUBMITTER_VERSION
#endif
#define SUBMITTER_VERSION "0.99.3 submission location restriction, accommodations, publish date"
#ifdef SUBMITTER_DATE
# undef SUBMITTER_DATE
#endif
#define SUBMITTER_DATE "20/Jan/2019"
//    program config file
#ifdef SUB_CFG_FILE
# undef SUB_CFG_FILE
#endif
#define SUB_CFG_FILE "submitter.cfg"

//    accommodation file
#ifdef SUB_ACC_FILE
# undef SUB_ACC_FILE
#endif
#define SUB_ACC_FILE "accommodations.cfg"

//    program default directory for assignment configuration files
#ifdef SUB_DEF_DIR
# undef SUB_DEF_DIR
#endif
#define SUB_DEF_DIR "submitter_files"

#define isSpace(ch) ((ch) < 33 || (ch) > 126)

namespace sict{
  class Submitter{
    User m_user;
    bool m_ok2submit;
    bool m_late;
    bool m_skipSpaces;
    bool m_skipNewlines;
    std::string m_lateTitle;
    int m_accommExtension;
    std::string m_accommTitle;
    Date m_now;
    Date m_dueDate;
    Date m_rejectionDate;
    Date m_publishDate;
    int m_argc;
    char** m_argv;
    std::string m_home;
    std::string m_submitterDir;
    std::string m_configFileName;
    SubVals m_asVals;
    SubVals m_accom; 
    Command m_cls;
    void setSubmitterDir();
    void clrscr()const;
    bool yes()const;
    bool getAssignmentValues();
    bool assignmentMatch(std::string assignmentName)const;
    bool getAccommodation();
    bool copyProfFiles();
    bool filesExist();
    bool compareOutputs(int from, int to);
    bool lineCompare(const char *student, const char* professor,int& stdUnmatchedIndex, int& profUnmatchedIndex);
    bool compare(const char* stdnt, const char* prof, int line);
    void diff(std::ostream& os, const char* stdnt, const char* prof, int line, int stdUnmatchedIndex, int profUnmatchedIndex);
    int compile();
    int execute();
    int checkOutput();
    bool skipLine(int lineNo);
    const char* name();
    bool submit(std::string& toEmail, bool Confirmation = false); // if confirmation is ture then work will be submitted to student
    bool removeBS(const char* filename);
    void printCommandSyntaxHelp()const;
    bool checkAndSetOption(std::string option);
    static bool isEmptyLine(const char* line);
  public:
    Submitter(int argc, char** argv);
    int run();
  };
}
#endif