#include "movieData.h"
#include <iomanip>

std::string MovieData::getName() const { return name; }

int MovieData::getYear() const { return year; }

double MovieData::getRating() const { return rating; }

MovieData::MovieData(std::string name, int year, double rating) :
  name(name), year(year), rating(rating) {}

bool MovieData::operator==(const MovieData& other) const {
  return name == other.name && year == other.year && rating == other.rating;
}

std::ostream& operator<<(std::ostream& os, const MovieData& m) {
  os << std::fixed << std::setprecision(1);
  os << m.getName() << " (" << m.getYear() << "): " << m.getRating();
  return os;
}

// Use alphabetical order by name if two movies have the same rating.
bool MovieData::operator<(const MovieData& other) const {
  return rating > other.rating ||
         (rating == other.rating && name < other.name);
}
