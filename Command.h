#ifndef SICT_COMMAND_H_
#define SICT_COMMAND_H_

//#define SICT_DEBUG// uncomment to print the commands instead of executing them
//#define SICT_DEBUG_ON_PC
//#define SICT_DEBUGEMAIL // uncomment to print the email command instead of executing it
//#define SHOW_COMMANDS

#include <string>
namespace sict{

  class Command :public std::string{
  public:
    Command(std::string str);
    int run()const;
  };
}
#endif