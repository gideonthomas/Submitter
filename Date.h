#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
#include <sstream>
namespace sict{
  const int NO_ERROR = 0;
  const int CIN_FAILED = 1;
  const int YEAR_ERROR = 2;
  const int MON_ERROR = 3;
  const int DAY_ERROR = 4;
  const int HOUR_ERROR = 5;
  const int  MIN_ERROR = 6;
  const bool DATE_ONLY = true;
  class Date{
  private:
    int m_year;
    int m_mon;
    int m_day;
    int m_hour;
    int m_min;
    int m_readErrorCode;
    int value()const;
    int curYear()const;
    bool validate();
    void errCode(int);
    void set(int year, int mon, int day, int hour, int min);
  public:
    Date();
    Date(int year, int mon, int day);
    Date(int year, int mon, int day, int hour, int min = 0);
    Date(std::stringstream& theDate);
    void set();
    bool operator==(const Date& D)const;
    bool operator!=(const Date& D)const;
    bool operator<(const Date& D)const;
    bool operator>(const Date& D)const;
    bool operator<=(const Date& D)const;
    bool operator>=(const Date& D)const;
    std::istream& read(std::istream& is = std::cin);
    std::ostream& write(std::ostream& os = std::cout)const;
    int errCode()const;
    bool bad()const;
    int mdays()const;
  };
  std::ostream& operator<<(std::ostream& os, const Date& RO);
  std::istream& operator>>(std::istream& is, Date& RO);
}
#endif