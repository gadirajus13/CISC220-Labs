#include <iostream>
#include <stack> 
using namespace std;

#pragma
class minStack: std::stack<int> {
    stack<int> s1, s2;
    int min;
 public:
    void push(int x);
    int pop();
    int findMin();
};