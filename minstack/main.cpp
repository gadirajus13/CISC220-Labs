#include "minstack.cpp" 
using namespace std;
int main() 
{ 
    int end = 1;
    minStack s; 
    int n;
    int x;
    while (end){
        cout << "\nList Operations\n===============\n";
        cout << "1.Insert\n";
        cout << "2.Delete Top Number\n";
        cout << "3.Find Minimum\n";
        cout << "4.Exit\n";
        cout << "Enter your choice : ";
        cin >> x;
        switch (x) 
        { 
            case 1:  
                cout << "Enter the number you would like to add to the stack: ";
                cin >> n;
                s.push(n); 
                break; 
            case 2:  
                s.pop(); 
                break; 
            case 3:  
                cout << "Minimum: " << s.findMin() << endl; 
                break; 
            case 4:
                end = 0;
                break;    
            default:  
                cout << "-------Invalid Choice------"; 
                break;   
        } 
    }

    return 0;    


}