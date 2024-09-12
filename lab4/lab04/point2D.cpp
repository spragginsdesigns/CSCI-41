#include "point2D.h"

Point2D::Point2D(int x, int y): x(x), y(y) {}

Point2D Point2D::operator+(const Point2D& other) const {
  Point2D ret(x + other.x, y + other.y);
  return ret;
}

bool Point2D::operator<(const Point2D& other) const {
  return x < other.x || (x == other.x && y < other.y);
}

bool Point2D::operator==(const Point2D& other) const {
  return x == other.x && y == other.y;
}

int Point2D::getX() const {
  return x;
}

int Point2D::getY() const {
  return y;
}
