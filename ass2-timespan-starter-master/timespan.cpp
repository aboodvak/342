//
// Created by Yusuf Pisan on 4/2/18.
//
/**
 * @file timespan.cpp
 * 
 * @brief implementation of timespan class
 * 
 * @author Abood Vakil on 4/22/2021
 * 
 **/

#include "timespan.h"

ostream &operator<<(ostream &out, const TimeSpan &ts) { 
  if (ts.isPos) {
    out << "";
  } else {
    out << "-";
  }
  out << ts.hours << ":" << ts.minutes << ":" << ts.seconds;
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
TimeSpan::TimeSpan(double hour, double minute, double second) {
  seconds = hour * 3600 + minute * 60 + second;
  if (seconds >= 0) {
    isPos = true;
  } else {
    isPos = false;
  }
  minutes = seconds / 60;
  seconds %= 60;
  hours = minutes / 60;
  minutes %= 60;
}

// constructor with only minutes and seconds as parameters
TimeSpan::TimeSpan(double hour, double minute) {
  minutes = minute + hour * 60;
  if (minutes >= 0) {
    isPos = true;
  } else {
    isPos = false;
  }
  minutes = abs(minutes);
  hours = minutes / 60;
  minutes %= 60;
  seconds = 0;
}

// constructor with only seconds as parameter
TimeSpan::TimeSpan(double hour) {
  hours = hour;
  minutes = 0;
  seconds = 0;

  if (hours >= 0) {
    isPos = true;
  } else {
    isPos = false;
  }
  hours = abs(hours);
}

// default constructor with no parameters
TimeSpan::TimeSpan() {
  seconds = 0;
  minutes = 0;
  hours = 0;
}

// function to convert current time to seconds
int TimeSpan::toSeconds() const {
  if (isPos) {
    return (hours * 3600 + minutes * 60 + seconds);
  } else {
    return -1 * (hours * 3600 + minutes * 60 + seconds);
  }

}

// hour component
int TimeSpan::getHour() const { return hours; }

// minute component
int TimeSpan::getMinute() const { return minutes; }

// second component
int TimeSpan::getSecond() const { return seconds; }

// true if timespan is 0 or larger
bool TimeSpan::isPositive() const { return isPos; }

// add
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  int second = toSeconds() + ts.toSeconds();
  TimeSpan tsSum(0, 0, second);
  return tsSum;
}

// subtract
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  int second = toSeconds() - ts.toSeconds();
  TimeSpan tsSub(0, 0, second);
  return tsSub;
}

// multiply with an integer
TimeSpan TimeSpan::operator*(unsigned int number) const {
  TimeSpan tsLarge(0, 0, toSeconds() * number);
  return tsLarge;
}

// equality ==
bool TimeSpan::operator==(const TimeSpan &ts) const { 
  if (toSeconds() == ts.toSeconds()) {
    return true;
  } else {
    return false;
  }
}

// inequality !=
bool TimeSpan::operator!=(const TimeSpan &ts) const { 
  if (*this == ts) {
    return false;
  } else {
    return true;
  }
}

// operator to add new time to existing one
TimeSpan& TimeSpan::operator+=(TimeSpan const &ts) {
  int second = toSeconds() + ts.toSeconds();
  TimeSpan tsNew(0, 0, second);
  hours = tsNew.hours;
  minutes = tsNew.minutes;
  seconds = tsNew.seconds;
  return *this;
}

// operator to subtract new time to existing one
TimeSpan& TimeSpan::operator-=(TimeSpan const &ts) {
  int second = toSeconds() - ts.toSeconds();
  TimeSpan tsNew(0, 0, second);
  hours = tsNew.hours;
  minutes = tsNew.minutes;
  seconds = tsNew.seconds;
  return *this;
}

// operator to check if current time is less than new time
bool TimeSpan::operator<(TimeSpan const &ts) {
  return toSeconds() < ts.toSeconds();
}

//operator to check if current time is greater than new time
bool TimeSpan::operator>(TimeSpan const &ts) {
  return toSeconds() > ts.toSeconds();
}

bool TimeSpan::operator<=(TimeSpan const &ts) {
  if (*this <= ts) {
    return true;
  } else {
    return false;
  }
}

bool TimeSpan::operator>=(TimeSpan const &ts) {
  if (*this >= ts) {
    return true;
  } else {
    return false;
  }
}