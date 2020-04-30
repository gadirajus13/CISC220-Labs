#include <iostream>
#include <cmath>
using namespace std;
// Nick Fafel and Sohan Gadiraju

struct minmax {
    int min;
    int max;
};

// Recursive function that returns minmax struct and takes in an array with arrayLength
struct minmax recursiveFunction(int a[], int arrayLength) 
{
    struct minmax get, numLeft, numRight;
    double half1, half2;

    // Primary base cases that returns element as min and max if array only has one element
    if (arrayLength == 1){
        get.min = a[0];
        get.max = a[0];
        return get;
    }
    // Secondary base case that returns the smaller one as the minimum 
    // and the larger one as the maximum if array has two elements
    else if (arrayLength == 2){
        if (a[0]<a[1]){
            get.min = a[0];
            get.max = a[1];
        }
        else {
            get.max = a[0];
            get.min = a[1];
        }
        return get;
    }

    //Checks if arrayLength is odd
    if(arrayLength%2 != 0){
        half1 = arrayLength/2;
        half2 = ceil(double(arrayLength)/2);  //If odd second half is larger than first
    }
    else{
        half1 = arrayLength/2;
        half2 = arrayLength/2; 
    }

    //Declaring leftSide array and rightSide array with their respective halves
    int recArray1[(int)half1];
    int recArray2[(int)half2];

    //Filling both arrays with their elements
    for (int i=0; i<half1; i++){
        recArray1[i] = a[i];
    }
    for (int j=0; j<half2; j++){
        recArray2[j] = a[(int)half1+j];
    }

    //Performing recursive function with the leftSide array and rightSide array
    numLeft = recursiveFunction(recArray1, (int)half1);
    numRight = recursiveFunction(recArray2, (int)half2);

    //Fianl comparisons after recursive functions are done to find max and min of whole array
    if (numLeft.min < numRight.min)
        get.min = numLeft.min;
    else
        get.min = numRight.min;

    if (numLeft.max > numRight.max)
        get.max = numLeft.max;
    else
        get.max = numRight.max;        

    return get;
}

int main(){
    
    struct minmax get;
    int arrayLength;
    cout << "Enter the length of the array of which you desire the min and max:" << endl;
    cin >> arrayLength;

    int A[arrayLength];

    cout << "Enter the integers of the array of which you desire the min and max and hit enter after each:" << endl;
    for (int i=0; i<arrayLength; i++) {
    int newElement;
    cout << "Element " << i+1 << ":" << endl;
    cin >> newElement;
    A[i] = newElement;
   }

    get = recursiveFunction(A, arrayLength);
    cout << "Max: " << get.max << endl; 
    cout << "Min: " << get.min << endl; 
    return 0;

}
