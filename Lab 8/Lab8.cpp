#include<iostream>
using namespace std;

int main()
{
int howOld = 41;
int *pHowOld = nullptr;
pHowOld = &howOld;

int stackint = 10;
int *ptrstackint = nullptr;
ptrstackint = &stackint;

unsigned short *ptrheapint = new unsigned short;
*ptrheapint = 20;

int &rReftoStack = stackint;


cout << "The value of stackint is: " << stackint << endl;
cout << "the memory address of stackint is: " << &stackint << endl;

cout <<"The value of ptrstackint is: " << *ptrstackint << endl;
cout << "The Memory Address of ptrstackint is: " << &ptrstackint << endl;

ptrstackint += 1;
cout << "Now ptrstackint is: " << ptrstackint << endl;


cout << "The value of ptrheapint is: " << *ptrheapint << endl;
cout << "The Memory Address ptrheapint is: " << ptrheapint << endl;

cout << "The Value of ReftoStack is: " << rReftoStack << endl;
cout << "The Memory Address of rReftoStack is: " << &rReftoStack << endl;


delete ptrheapint;




return 0;
}