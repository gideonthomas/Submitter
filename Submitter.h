#ifndef SICT_SUBMITTER_H_
#define SICT_SUBMITTER_H_
#include "Vals.h"
#include "SubVals.h"
#include "Command.h"
#include "Date.h"
// define statements

//  version
#ifdef SUBMITTER_VERSION
# undef SUBMITTER_VERSION
#endif
#define SUBMITTER_VERSION "0.98.5 fixed extra long lines"
#ifdef SUBMITTER_DATE
# undef SUBMITTER_DATE
#endif
#define SUBMITTER_DATE "20/Dec/2018"
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

namespace sict{
  class Submitter{
    bool ok2submit;
    bool late;
    bool superlate;
    int _argc;
    Date now;
    Date dueDate;
    Date cutoffDate;
    Date rejectionDate;
    char** _argv;
    std::string _home;
    std::string _submitterDir;
    std::string _configFileName;
    SubVals _AsVals;
    Command _cls;
    void setSubmitterDir();
    void clrscr()const;
    bool yes()const;
    bool getAssignmentValues();
    bool copyProfFiles();
    bool filesExist();
    static bool compare(const char* stdnt, const char* prof, int line);
    static void diff(std::ostream& os, const char* stdnt, const char* prof, int line);
    int compile();
    int execute();
    int checkOutput();
    bool skipLine(int lineNo);
    bool compareOutputs(int from, int to);
    const char* name();
    bool submit(std::string& toEmail, bool Confirmation = false); // if confirmation is ture then work will be submitted to student
    bool removeBS();
    static const char* charName(char ch);
  public:
    Submitter(int argc, char** argv);
    int run();
  };
}
#endif