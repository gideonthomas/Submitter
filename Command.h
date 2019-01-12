#ifndef SICT_COMMAND_H_
#define SICT_COMMAND_H_


#include <string>
#include "debug.h"
namespace sict{

  class Command :public std::string{
  public:
    Command(std::string str);
    int run()const;
  };
}
#endif