// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int countPriory(char a) {
if (a == '+' || a == '-') {
return 2;
}
if (a == '*' || a == '/') {
return 3;
}
if (a == '(') {
return 0;
}
if (a == ')') {
return 1;
}
}

std::string infx2pstfx(std::string inf) {
TStack<char> mstack;
string result = "";
for (int i = 0; i < inf.size(); ++i) {
if (inf[i] > '9' || inf[i] < '0' || (inf[i] != '(' && inf[i] != ')' && inf[i] != '+' && inf[i] != '-' && inf[i] != '*' && inf[i] != '/')) {
if (inf[i] <= '9' && inf[i] >= '0') {
result = result + inf[i] + ' ';
} else {
if (countPriory(inf[i]) == 1) {
while (mstack.get() != '(') {
result = result + mstack.get() + ' ';
mstack.pop();
}
mstack.pop();
}
else {
if (mstack.isEmpty() || countPriory(inf[i]) == 0 || countPriory(inf[i]) > countPriory(mstack.get())) {
mstack.push(inf[i]);
} else {
result = result + mstack.get() + ' ';
mstack.pop();
mstack.push(inf[i]);
}
}
}
}
}
while (!mstack.isEmpty()) {
result = result + mstack.get() + ' ';
mstack.pop();
}
result.erase(result.end() - 1);
return result;
return std::string("");
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
}
else {
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
