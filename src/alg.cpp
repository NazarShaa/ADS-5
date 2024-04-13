// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int Priority (char c) {
  if (c == '(')
    return 0;
  if (c == ')')
    return 1;
  if (c == '+' || c == '-')
    return 2;
  if (c == '*' || c == '/')
    return 3;
}
std::string infx2pstfx(std::string inf) {
  std::string post
   TStack<char, 100> stack1;
  for (char c: inf){
    if (c > '0' && c <= '9') {
      post += c;
      post += ' ';
    }
    else {
      if (c == '(')
        stack1.Push(c);
      if (stack1.get == 0)
        stack1.Push(c);
      if (stack1.get != 0 && Priority(stack1.get) < Priority(c))
        stack1.Push(c);
      if (c == ')') {
        while (stack1.get != '(') {
          post += stack1.pop;
          post += ' ';
        }
        stack1.pop;
      }
      if (stack1.get != 0 && Priority(stack1.get) >= Priority(c)) {
        while (stack1.get != 0 && Priority(stack1.get) <= Priority(c)) {
          post += stack1.pop;
          post += ' ';
        }
        stack1.Push(c);
      }
      if (c == '/0') {
        while (stack.get != 0) {
          post += stack.pop;
          post += ' ';
        }
      }
    } 
  }
  return post;
}

int eval(std::string post) {
  
  return 0;
}
