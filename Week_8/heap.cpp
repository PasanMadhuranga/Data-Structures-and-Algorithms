#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   // Initialize largest element to be the root
   int largest = root;
   // Get indices of left and right children of the root
   int left = 2*root + 1;
   int right = 2*root + 2;

   // Check if left child is larger than root
   if (left < n && arr[largest] < arr[left]){
      largest = left;
   }

   // Check if right child is larger than root
   if (right < n && arr[largest] < arr[right]){
      largest = right;
   }


   // If the largest element is not the root, swap root with largest
   if (largest != root){
      int temp = arr[largest];
      arr[largest] = arr[root];
      arr[root] = temp;
      // Heapify the affected subtree
      heapify(arr, n, largest);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   // build heap by calling heapify on each parent node starting from the last parent node
   for (int i = n/2; i >= 0; i--){
      heapify(arr, n, i);
   }
   
   // extracting elements from heap one by one
   for (int i = n-1; i > 0; i--){
      // swap the root element with the last unsorted element
      int temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;
      // reduce the size of the heap and heapify the root
      heapify(arr, --n, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   // Get an array of integers from the user
   int n;
   cout << "How many integers are you going to input?\n";
   cin >> n;
   int* heap_arr = new int[n];
   cout << "Enter integers\n";
   for(int i = 0; i < n; i++){
      cin >> heap_arr[i];
   }

   // Display input array
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   // Sort the array
   heapSort(heap_arr, n);
  
   // Display the sorted array
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}