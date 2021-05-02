// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int Priory(char a) {
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
TStack<char> mstack;
std::string result;
for (int i = 0; i < inf.size(); ++i) {
if ((inf[i] <= '9' && inf[i] >= '0') || Priory(inf[i]) != -1) {
if (inf[i] <= '9' && inf[i] >= '0') {
result.push_back(inf[i]);
result.push_back(' ');
continue;
}
if (Priory(inf[i]) == 1) {
while (mstack.get() != '(') {
result.push_back(mstack.get())
result.push_back(' ');
mstack.pop();
}
mstack.pop();
} else {
if (mstack.isEmpty() || Priory(inf[i]) == 0 || Priory(inf[i]) > Priory(mstack.get())) {
mstack.push(inf[i]);
} else {
result.push_back(mstack.get())
result.push_back(' ');
mstack.pop();
mstack.push(inf[i]);
}
}
}
}
}
while (!mstack.isEmpty()) {
result.push_back(mstack.get())
result.push_back(' ');
mstack.pop();
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
