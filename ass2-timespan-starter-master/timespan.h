//
// Created by Yusuf Pisan on 4/2/18.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:
  // explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);

  explicit TimeSpan(double minute = 0, double second = 0);
  explicit TimeSpan(double second = 0);
  explicit TimeSpan();

  // add
  TimeSpan operator+(const TimeSpan &ts) const;

  // subtract
  TimeSpan operator-(const TimeSpan &ts) const;

  // check equality
  bool operator==(const TimeSpan &ts) const;

  // check if not equal
  bool operator!=(const TimeSpan &ts) const;

  // multiply timespan by an unsigned number
  TimeSpan operator*(unsigned int number) const;

  // TODO(student)
  // to add operator+=, operator-=, operator<, operator>, operator<=, operator>=

  // add to existing TimeSpan
  TimeSpan& operator+=(TimeSpan const &ts);

  // subtract from existing TimeSpan
  TimeSpan& operator-=(TimeSpan const &ts);

  // check if current time is less
  bool operator<(TimeSpan const &ts);

  // check if current time is greater
  bool operator>(TimeSpan const &ts);

  // check if current time is less than or equal
  bool operator<=(TimeSpan const &ts);

  // check if current time is greater than or equal
  bool operator>=(TimeSpan const &ts);

  // hour component of timespan
  int getHour() const;

  // minute component of timespan
  int getMinute() const;

  // second component of timespan
  int getSecond() const;

  // true if timespan is 0 or larger
  bool isPositive() const;

private:
  int toSeconds() const;

  int hours;
  int minutes;
  int seconds;
  bool isPos;
};

#endif // ASS2_TIMESPAN_H
