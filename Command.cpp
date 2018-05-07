#include <cstdlib>
#include "Command.h"

# if defined(SICT_DEBUG) || defined(SHOW_COMMANDS)
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
#ifdef SHOW_COMMANDS
    cout << "Running: " << c_str() << endl;
#endif // DEBUG
    return system(c_str());
# endif
  }
}


