#ifndef SICT_LINE_H_
#define SICT_LINE_H_
#include <iostream>


namespace sict {
  class Line {
    const char* _line;
    int _highlightIndex;
    char _buf[81];
    char _chName[39];
    static bool _colored;
    static void copy(char* des, const char* src);  
    static void cat(char* des, const char* src); 
    static void cat(char* des, char src); 
    const char* charName(char ch);
  public:
    Line(const char* line, int highLightIndex = -1);
    std::ostream& display(std::ostream& os)const;
    const char* operator[](int index);
  };
  std::ostream& operator<<(std::ostream& os, const Line& L);
}

#endif // !SICT_LINE_H_