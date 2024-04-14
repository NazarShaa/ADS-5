// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
#include <stdexcept>

template<typename T, int size>
class TStack {
public:
  TStack() : top(-1) {
    data = new T[size];
  }
  void push(const T& item) {
    if (top <= size - 1)
      data[++top] = item;
    else
      resize(2 * size);
  }
  T pop() {
    if (!isEmpty())
      throw std::string("stack is empty");
    else
      return data[top--];
  }
  ~TStack() {
    delete[] data;
  }
  bool isEmpty() const {
    return top == -1;
  }
  T get() const {
    if (!isEmpty())
      throw std::string("stack is empty");
    else
      return data[top];
  }
private:
  T* data;
  int top, size;
  void resize(int nsize) {
    T* temp = new T[nsize];
    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    size = nsize;
  }
};
#endif  // INCLUDE_TSTACK_H_
