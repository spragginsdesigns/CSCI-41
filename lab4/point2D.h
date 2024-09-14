#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
public:
  Point2D(int x = 0, int y = 0);
  Point2D operator+(const Point2D& other) const;
  bool operator<(const Point2D& other) const;
  bool operator==(const Point2D& other) const;
  int getX() const;
  int getY() const;
private:
  int x;
  int y;
};

#endif /* POINT2D_H */
