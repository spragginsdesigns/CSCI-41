#ifndef VEC_H
#define VEC_H

#define vector YoureNotAllowedToUseStdVector

class Vec {
public:
  Vec();
  void push_back(int x);
  int size() const;
  int& at(int i);
  void sort();
private:
  void resize();
  int *arr;
  int numItems;
  int capacity;
};

#endif /* VEC_H */