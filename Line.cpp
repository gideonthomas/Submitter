#include <cstring>
#include "Line.h"
#include "colors.h"
#include "debug.h"

namespace sict {
  bool Line::_colored = false;
  Line::Line(const char* line, int highLight):_line(line), _highlightIndex(highLight) {
  }
  std::ostream& Line::display(std::ostream& os)const {
    int i = 0;
    _colored = (&os == &std::cout);
    while (_line[i]) {
      if (i == _highlightIndex && _colored) os << col_red;
      if (_line[i] == '\b') {  // don't think this is needed anymore since all the backspaces are removed!
        os << "\\b";
      }
      else {
        os << _line[i];
      }
      if (i == _highlightIndex && _colored) os << col_end;
      i++;
    }
    if (_highlightIndex >= 0) {
      os << std::endl;
      for (i = 0; i < _highlightIndex; i++) os << " ";
      if (_colored) os << col_red;
      os << "^" ;
      if (_colored) os << col_end;
    }
    return os;
  } 
  const char* Line::operator[](int index){
    _buf[0] = 0;
    if (_colored) copy(_buf, col_red);
      cat(_buf, charName( _line[index]));
    if (_colored) cat(_buf, col_end);
    return _buf;
  }
  void Line::copy(char* des, const char* src) {
    while (bool(*des++ = *src++));
  }
  void Line::cat(char* des, const char* src) {
    while (*des) des++;
    while (bool(*des++ = *src++));
  }
  void Line::cat(char* des, char src) {
    while (*des) des++;
    *des++ = src;
    *des = 0;
  }
  const char* Line::charName(char ch) {
    char chName[34][39] = {
      "NULL",
      "Start Of Heading",
      "Start Of Text",
      "End Of Text",
      "End Of Transmission",
      "Enquiry",
      "Acknoledge",
      "Bell (\\a)",
      "Backspace (\\b)",
      "Tab (\\t)",
      "New Line (\\n)",
      "Vertical Tab",
      "Form Feed (\\f)",
      "Newline (\\n) or Carriage Retrun (\\r)",
      "Shift out",
      "Shift in",
      "Data Link Escape",
      "Device Control 1",
      "Device Control 2",
      "Device Control 3",
      "Device Control 4",
      "Negative Acknoledge",
      "Synchronous Idle",
      "End of Tran. Block",
      "Cancel",
      "End Of Medium",
      "Substitude",
      "Escape",
      "File Separator",
      "Groupu Separator",
      "Record Separator",
      "Unit Separator",
      "Space",
      "Non printable char"
    };
    if (ch >= 33) {
      _chName[0] = ch;
      _chName[1] = '\0';
      ch = 33;
    }
    else {
      copy(_chName, chName[int(ch)]);
    }
    return _chName;
  }
  std::ostream& operator<<(std::ostream& os, const Line& L) {
    return L.display(os);
  }
}