#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sict{
  int Date::curYear()const {
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    return lt.tm_year + 1900;
  }
  void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
    errCode(NO_ERROR);
  }
  void Date::set(int year, int mon, int day, int hour, int min){
    m_year = year;
    m_mon = mon;
    m_day = day;
    m_hour = hour;
    m_min = min;
    errCode(NO_ERROR);
  }

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }
  bool Date::validate(){
    errCode(NO_ERROR);
    if (m_year < curYear() || m_year > curYear()+ 1){
      errCode(YEAR_ERROR);
    }
    else if (m_mon < 1 || m_mon > 12){
      errCode(MON_ERROR);
    }
    else if (m_day < 1 || m_day > mdays()){
      errCode(DAY_ERROR);
    } 
    else if (m_hour < 0 || m_hour > 23){
      errCode(HOUR_ERROR);
    }
    else if (m_min < 0 || m_min > 59){
      errCode(MIN_ERROR);
    }
    return !bad();
  }
  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }
  Date::Date(){
    dateOnly(false);
    set();
  }
  Date::Date(int year, int mon, int day){
    dateOnly(true);
    set(year, mon, day, 0, 0);
  }
  Date::Date(int year, int mon, int day, int hour, int min ){
    dateOnly(false);
    set(year, mon, day, hour, min);
  }
  Date::Date(std::stringstream& theDate, bool isDateOnly) {
    dateOnly(isDateOnly);
    read(theDate);
  }
  void Date::errCode(int readErrorCode){
    m_readErrorCode = readErrorCode;
  }
  int Date::errCode()const{
    return m_readErrorCode;
  }
  bool Date::bad()const{
    return m_readErrorCode != 0;
  }
  bool Date::operator==(const Date& D)const{ 
    return value() == D.value();
  }
  bool Date::operator!=(const Date& D)const{ 
    return !operator==(D);                                              
  }
  bool Date::operator<(const Date& D)const{ 
    return value() < D.value();
  }
  bool Date::operator>(const Date& D)const{ 
    return value() > D.value();
  }
  bool Date::operator<=(const Date& D)const{ 
    return !operator>(D);
  }
  bool Date::operator>=(const Date& D)const{ 
    return !operator<(D);
  }
  istream& Date::read(istream& is){
    m_readErrorCode = 0;
    is >> m_year;
    is.ignore();
    is >> m_mon;
    is.ignore();
    is >> m_day;
    if (!dateOnly()){
      is.ignore();
      is >> m_hour;
      is.ignore();
      is >> m_min;
    }
    else{
      m_hour = m_min = 0;
    }
    if (is.fail()){
      errCode(CIN_FAILED);
    }
    else{
      validate();
    }
    return is;
  }
  bool Date::dateOnly()const{
    return m_dateOnly;
  }
  void Date::dateOnly(bool value){
    m_dateOnly = value;
    if (value) m_hour = m_min = 0;
  }
  ostream& Date::write(ostream& os)const{ 
    os << right << m_year << "/" << setw(2) << setfill('0') << m_mon << "/"
      << setw(2) << setfill('0') << m_day;
    if (!dateOnly())
      os <<", " << setw(2) << setfill('0') << m_hour << ":" << setw(2) << setfill('0') << m_min;
    return os;
  }
  ostream& operator<<(ostream& os, const Date& RO){ 
    return RO.write(os);
  }
  istream& operator>>(istream& is, Date& RO){ 
    return RO.read(is);
  }


}
