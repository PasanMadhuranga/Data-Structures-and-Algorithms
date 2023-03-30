#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <chrono>
using namespace std;

// function to swap two integer values
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This function takes the last element as pivot, 
   places the pivot element at its correct position 
   in the sorted array, and places all smaller (smaller than pivot) 
   to the left of pivot and all greater elements to the right of pivot */
int partition(int array[], int low, int high)
{
    // pivot element - the last element in the array
    int pivot = array[high];
    // initialize index of smaller element
    int i = low - 1;

    // traverse through the array from low to high-1
    for (int j = low; j <= high - 1; j++)
    {
        // if current element is smaller than or equal to pivot
        if (array[j] <= pivot)
        {
            // increment index of smaller element
            i++;
            // swap the current element with the element at index i
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the element at index i+1
    swap(&array[i + 1], &array[high]);
    // return the index of the pivot element
    return (i + 1);
}

/* iterative implementation of quicksort */
void IterativeQuickSort(int array[], int low, int high)
{
    // create an auxiliary stack
    int stack[high - low + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // pop elements from stack until it is empty
    while (top >= 0)
    {
        // pop high and low from stack
        high = stack[top--];
        low = stack[top--];

        // set the pivot element at its correct position
        int pivot_index = partition(array, low, high);

        // if there are elements on left side of pivot, push left side to stack
        if (pivot_index - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pivot_index - 1;
        }

        // if there are elements on right side of pivot, push right side to stack
        if (pivot_index + 1 < high)
        {
            stack[++top] = pivot_index + 1;
            stack[++top] = high;
        }
    }
}


int main(){
    int array_size = 19847;
    int arr[array_size];

    srand(time(NULL));

    // Create the array by adding random elements less than 1000;
    for (int i = 0; i < array_size; i++) {
        arr[i] = rand() % 1000;
    }

    // Start time
    auto start = chrono::high_resolution_clock::now();

    IterativeQuickSort(arr, 0, array_size - 1);

    // End time
    auto stop = chrono::high_resolution_clock::now();

    // Get the execution time for Recursive QuickSort algorithm
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}

