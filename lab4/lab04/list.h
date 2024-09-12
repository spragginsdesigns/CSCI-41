#ifndef LIST_H
#define LIST_H

#include "point2D.h"

struct Node {
  Point2D data;
  Node* next;
};

class List {
public:
  List();
  ~List();
  List& operator=(const List& other);
  List(const List& other);

  const Node* getFirst();
  const Node* getLast();

  void push_front(Point2D data);
  void push_back(Point2D data);
  void pop_front();
  void pop_back();
  int size();

private:
  Node* first;
  Node* last;
};

#endif /* LIST_H */
