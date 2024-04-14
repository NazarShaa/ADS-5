// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"

int Priority (char c) {
  if (c == '(')
    return 0;
  else if (c == ')')
    return 1;
  else if (c == '+' || c == '-')
    return 2;
  else if (c == '*' || c == '/')
    return 3;
  else
    return -1;
}
std::string infx2pstfx(std::string inf) {
  std::string post;
  TStack<char, 100> stack1;
  for (char c: inf) {
    if (c > '0' && c <= '9')
      post += c + ' ';
    else {
      char sym = stack1.get();
      if (c == '(' || Priority(sym) < Priority(c) || stack1.isEmpty() || c == ')') {
        while (Priority(sym) >= Priority(c)) {
          post += sym + ' ';
          stack1.pop();
          if (!stack1.isEmpty())
            sym = stack1.get();
          else
            break;
	}
	if (c == ')')
	  stack1.pop();
	else
	  stack1.push(c);
      }
      else {
        while (Priority(sym) >= Priority(c)) {
          post += sym + ' ';
          stack1.pop();
          if (!stack1.isEmpty())
	    sym = stack1.get();
          else
	    break;
        }
	stack1.push(c);
      }
    }
  }
  while (!stack1.isEmpty()) {
    post += stack1.get() + ' ';
    stack1.pop();
  }
  return post;
}

int eval(std::string post) {
  TStack<int, 100> stack2;
  std::string number;
  for (int i = 0; i < post.size(); ++i) {
    if (Priority(post[i]) == -1) {
      if (post[i] == ' ')
        continue;
      else if (isdigit(post[i + 1])) {
        number += post[i];
	continue;
      }
      else {
	number += post[i];
	int value = atoi(number.c_str());
	stack2.push(value);
	number = "";
      }
    }
    else {
      int b = stack2.pop();
      int a = stack2.pop();
      switch (post[i]) {
      case '+':
        stack2.push(a + b);
	break;
      case '-':
	stack2.push(a - b);
	break;
      case '*':
	stack2.push(a * b);
	break;
      case '/':
	stack2.push(a / b);
        break;
      }
    }
  }
  return stack2.get();
}
