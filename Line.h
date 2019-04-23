#ifndef SICT_LINE_H_
#define SICT_LINE_H_
#include <iostream>


namespace sict {
  class Line {
    const char* m_line;
    int m_highlightIndex;
    char m_buf[81];
    char m_chName[39];
    static bool m_colored;
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