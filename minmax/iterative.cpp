#include <vector>
#include <iostream>
using namespace std;
//Nicholas Fafel and Sohan Gadiraju

int main() {
   int arrayLength;
   cout << "Enter the length of the array of which you desire the min and max:" << endl;
   cin >> arrayLength;

   int A[arrayLength];

   //The block of code below populates the array with the elements the user enters.
   cout << "Enter the integers of the array of which you desire the min and max and hit enter after each:" << endl;
   for (int i=0; i<arrayLength; i++) {
       int newElement;
       cout << "Element " << i+1 << ":" << endl;
       cin >> newElement;
       A[i] = newElement;
   }

   //Initialize min and max to the first element in the array
   int min = A[0];
   int max = A[0];

   //If the lenght of the array is 2, we only want to compare the second element to the min and max
   if (arrayLength == 2) {
       if (A[1] < min) {
           min = A[1];
       } else {
           if (A[1] > max) {
               max = A[1];
           }
       }
  
   /* When comparing elements, we pair the elements up and then compare them. If this condition is satisfied,
    * then the last element in the array would not have a pair, so we have to compare it to the min and max by itself. */
   } else if (arrayLength % 2 == 0) {
       if (A[arrayLength-1] <= min) {
           min = A[arrayLength-1];
       } else {
           if (A[arrayLength-1] > max) {
               max = A[arrayLength-1];
           }
       }
   }
  
   for (int i = 1; i < arrayLength - 1; i+=2) {
       /* Every time the body of this loop executes, we find the relative minimum and maximum between two consecutive elements in the array.
        * The relative minimum of the two elements is compared to the absolute minimum and the relative maximum of the two elements is compared
        * to the absolute maximum. */
       if (A[i] < A[i+1]) {
           if (A[i] < min) {
               min = A[i];
           }

           if (A[i+1] > max) {
               max = A[i+1];
           }
       } else {
           if (A[i+1] < min) {
               min = A[i+1];
           }

           if (A[i] > max) {
               max = A[i];
           }
       }
   }

   cout << "Min: " << min << endl; //Print the minimum
   cout << "Max: " << max << endl; //Print the maximum
  
   return 0; 
}
