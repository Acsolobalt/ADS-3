// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int prior(char a) {
switch(a) {
case '+':
return 2;
case '-':
return 2;
case '*':
return 3;
case '/':
return 3;
case '(':
return 0;
case ')':
return 1;
default:
return -1;
}

std::string infx2pstfx(std::string inf) {
std::string pfx;
    int i = 0;
    char ch = inf[i];
    char top = 0;
    TStack <char> stackChar;
    while (ch) {
        int priority;
        priority = prior(ch);

        if (priority > -1) {
            if ((priority == 0 || priority > prior(top) ||
                stackChar.isEmpty()) && ch != ')') {
                if (stackChar.isEmpty())
                    top = ch;
                stackChar.push(ch);
            } else if (ch == ')') {
                while (stackChar.get() != '(') {
                    pfx.push_back(stackChar.get());
                    pfx.push_back(' ');
                    stackChar.pop();
                }
                stackChar.pop();
                if (stackChar.isEmpty())
                    top = 0;
            } else {
                while (!stackChar.isEmpty() &&
                       prior(stackChar.get()) >= priority) {
                    pfx.push_back(stackChar.get());
                    pfx.push_back(' ');
                    stackChar.pop();
                }
                if (stackChar.isEmpty())
                    top = ch;
                stackChar.push(ch);
            }
        } else {
            pfx.push_back(ch);
            pfx.push_back(' ');
        }

        ch = inf[++i];
    }
    while (!stackChar.isEmpty()) {
        pfx.push_back(stackChar.get());
        pfx.push_back(' ');
        stackChar.pop();
    }
    pfx.erase(pfx.end() - 1, pfx.end());
    return pfx;
}

int eval(std::string pst) {
TStack<char> mstack;
int a, b, sum;
char result;
for (int i = 0; i < pst.size(); ++i) {
  if (pst[i] == ' ') {
  continue;
  }
  if (pst[i] <= '9' && pst[i] >= '0') {
  mstack.push(pst[i]);
  } else {
  switch (pst[i]) {
    case '+':
     a = mstack.get() - '0';
     mstack.pop();
     b = mstack.get() - '0';
     mstack.pop();
     sum = b + a;
     result = sum + '0';
     mstack.push(result); break;
    case '-':
     a = mstack.get() - '0';
     mstack.pop();
     b = mstack.get() - '0';
     mstack.pop();
     sum = b - a;
     result = sum + '0';
     mstack.push(result); break;
    case '*':
     a = mstack.get() - '0';
     mstack.pop();
     b = mstack.get() - '0';
     mstack.pop();
     sum = b * a;
     result = sum + '0';
     mstack.push(result); break;
    case '/':
     a = mstack.get() - '0';
     mstack.pop();
     b = mstack.get() - '0';
     mstack.pop();
     sum = b / a;
     result = sum + '0';
     mstack.push(result); break;
  }
  }
}
return mstack.get() - '0';
}
