#include <iostream>

using namespace std; 

bool asc(int a, int b)
{ return a > b; }

bool desc(int a, int b)
{ return a < b; }

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n, bool (*comp)(int,int)) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)  

    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
    if (comp(arr[j] , arr[j+1])) 
        swap(&arr[j], &arr[j+1]); 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

// Driver code 
int main() 
{ 
  int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  bubbleSort(arr, n,asc); 
  cout<<"Sorted array: \n"; 
  printArray(arr, n); 

  bubbleSort(arr, n,desc); 
  cout<<"Sorted array: \n"; 
  printArray(arr, n); 
  return 0; 
} 

/*OUTPUT

Sorted array:
11 12 22 25 34 64 90        
Sorted array:
90 64 34 25 22 12 11  

*/