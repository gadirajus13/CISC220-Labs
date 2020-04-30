#include <iostream> 
#include <queue> 
using namespace std; 
 // Sohan Gadiraju 
int main() 
{ 
    priority_queue <int> max_heap;
    priority_queue <int, vector<int>, greater<int> > min_heap; 
    int median;
    int count = 1;
    int n=1;
    int k;

    while(n){
        
        cout << "Enter a number to find the median: " << endl;
        cin >> k;
        if (count == 1){
            median = k;
            cout << "Median: " << median << endl;
        }
        if (k<median && count == 2){
            max_heap.push(k);
            min_heap.push(median);
            cout << "Median: " << median << " & " << max_heap.top() << endl;
        }
        if (k>median && count == 2){
            min_heap.push(k);
            max_heap.push(median);
            cout << "Median: " << median << " & " << min_heap.top() << endl;
        }

        // Checking for odd numbered list
        if ((count > 2) && (count%2 == 1) ){
            if (k>median){
                median = min_heap.top();
                min_heap.push(k);
                cout << "Median: " << median << endl;
            }
            else if (k<median){
                median = max_heap.top();
                max_heap.push(k);
                cout << "Median: " << median << endl;
            }
            else{
                cout << "Median: " << median << endl;
            }
        }

        // Checking for even numbered list
        if ((count > 2) && (count%2 == 0) ){
             if (k>median){
                // Moving terms over from one heap to another to keep them balanced 
                median = min_heap.top();
                min_heap.pop();
                max_heap.push(median); 
                cout << "Median: " << median << " & " << min_heap.top() << endl;
                min_heap.push(k);
            }
            else if (k<median){
                // Moving terms over from one heap to another to keep them balanced 
                max_heap.push(k);
                min_heap.push(max_heap.top());
                max_heap.pop();
                cout << "Median: "<< max_heap.top() << " & " << min_heap.top() << endl;
            }
            else{
                cout << "Median: " << median << endl;
            }
        }
        count++;
    }

    return 0; 
} 