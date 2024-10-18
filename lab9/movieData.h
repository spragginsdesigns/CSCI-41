#ifndef MOVIEDATA_H
#define MOVIEDATA_H

#include <iostream>
#include <string>

class MovieData {
public:
  MovieData(std::string name, int year, double rating);
  bool operator<(const MovieData& other) const;
  bool operator>(const MovieData& other) const { return other < *this; }
  bool operator<=(const MovieData& other) const { return !(*this > other); }
  bool operator>=(const MovieData& other) const { return !(*this < other); }
  bool operator==(const MovieData& other) const;
  std::string getName() const;
  int getYear() const;
  double getRating() const;
private:
  std::string name;
  int year;
  double rating;
};

std::ostream& operator<<(std::ostream& os, const MovieData& m);

#endif /* MOVIEDATA_H */
