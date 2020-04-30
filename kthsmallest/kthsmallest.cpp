#include <iostream>  
//Sohan Gadiraju
using namespace std; 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
int kthSmallest(int arr[], int low, int n, int k) 
{  
        int pi = partition(arr, low, n);   
        // Base case checking to see if position of pivot is same as k 
        if (pi-low == k-1){
            return arr[pi]; 
        } 
        else if (pi-low > k-1){
            return kthSmallest(arr, low, pi-1, k); 
        }  
        else
            return kthSmallest(arr, pi+1, n, k-pi+low-1); 

} 

// Driver Code 
int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5, 8, 12, 84, 68}; 
    int n = sizeof(arr) / sizeof(arr[0]);  
	int k;
	cout << "Enter the value of k: " << endl;
	cin >> k;
	while (k<=0 || k > n){
		cout << "Please enter a valid value for k:" << endl;
		cin >> k;
	} 
	cout<< "Kth Smallest Element: " << kthSmallest(arr, 0, n-1, k) << "\n"; 
	return 0; 
} 


