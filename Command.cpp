#include <cstdlib>
#include "Command.h"

# ifdef SICT_DEBUG
#   include <iostream>
# endif

using namespace std;
namespace sict{
  Command::Command(string str) : string(str){
  }
  int Command::run()const{
# ifdef SICT_DEBUG
    cout <<"RUN: "<< c_str() << endl;
    cin.ignore(1000, '\n');
    return 0;
# else
    return system(c_str());
# endif
  }
}


