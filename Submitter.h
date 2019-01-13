#ifndef SICT_SUBMITTER_H_
#define SICT_SUBMITTER_H_
#include "debug.h"
#include "Vals.h"
#include "SubVals.h"
#include "Command.h"
#include "Date.h"
// define statements

//  version
#ifdef SUBMITTER_VERSION
# undef SUBMITTER_VERSION
#endif
#define SUBMITTER_VERSION "0.99 colours, due dates, announcements, easy submission"
#ifdef SUBMITTER_DATE
# undef SUBMITTER_DATE
#endif
#define SUBMITTER_DATE "13/Jan/2019"
//    program config file
#ifdef SUB_CFG_FILE
# undef SUB_CFG_FILE
#endif
#define SUB_CFG_FILE "submitter.cfg"


//    program default directory for assignment configuration files
#ifdef SUB_DEF_DIR
# undef SUB_DEF_DIR
#endif
#define SUB_DEF_DIR "submitter_files"

#define isSpace(ch) ((ch) < 33 || (ch) > 126)

namespace sict{
  class Submitter{
    bool _ok2submit;
    bool _late;
    bool _skipSpaces;
    bool _skipNewlines;
    std::string _lateTitle;
    Date _now;
    Date _dueDate;
    Date _cutoffDate;
    Date _rejectionDate;
    int _argc;
    char** _argv;
    std::string _home;
    std::string _submitterDir;
    std::string _configFileName;
    SubVals _asVals;
   /* SubVals _subVals;*/
    Command _cls;
    void setSubmitterDir();
    void clrscr()const;
    bool yes()const;
    bool getAssignmentValues();
    /*bool getSubmitterValues();  for future global config settings like color */
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