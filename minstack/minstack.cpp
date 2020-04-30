#include "minstack.h" 
using namespace std;

void minStack::push(int x)
{ 
    if (s1.empty()) 
    { 
        min = x; 
        s1.push(x);
        s2.push(x); 
        return; 
    } 
    if (x < min) 
    { 
        min = x;
        s1.push(x);
        s2.push(x); 
    } 
    else{
        s1.push(x); 
    }

} 
int minStack::pop() 
{
    int t;
    if (s1.size()==0){
        cout << "Stack is Empty! Invalid Option" << endl;
        return 0;
    }
    else{
        t = s1.top(); 
        s1.pop();
    } 
    
    if (t == min) 
    { 
        //Removes top number form s2 because it is no longer the min
        s2.pop();
        if (s2.size()==0){
            min = 0;     
        }
        else{
        min = s2.top();
        }
    } 
    return s1.top();
} 
int minStack::findMin()
{
    if (s1.empty()){ 
        cout << "Stack is empty\n";
        return 0;
    }     
    else{
        return min;
    }    
}