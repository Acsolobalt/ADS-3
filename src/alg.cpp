// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int Pr(char a) {
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
std::string result;
TStack<char> mstk;
for (int i = 0; i < inf.size(); ++i) {
if ((inf[i] <= '9' && inf[i] >= '0') || Pr(inf[i]) != -1) {
if (inf[i] <= '9' && inf[i] >= '0') {
result.push_back(inf[i]);
result.push_back(' ');
continue;
}
if (Pr(inf[i]) == 1) {
while (mstk.get() != '(') {
result.push_back(mstk.get())
result.push_back(' ');
mstk.pop();
}
mstk.pop();
} else {
if (mstk.isEmpty() || Pr(inf[i]) == 0 || Pr(inf[i]) > Pr(mstk.get())) {
mstk.push(inf[i]);
} else {
result.push_back(mstk.get())
result.push_back(' ');
mstk.pop();
mstk.push(inf[i]);
}
}
}
}
}
while (!mstk.isEmpty()) {
result.push_back(mstk.get())
result.push_back(' ');
mstk.pop();
}
result.erase(result.end() - 1);
return result;
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
