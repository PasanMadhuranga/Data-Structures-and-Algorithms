#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <chrono>

using namespace std;

// function to swap two integer values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to partition the array and return the index of the pivot element
int partition(int array[], int start, int end)
{
    // pivot element - the last element in the array
    int pivot = array[end];
    // initialize index of smaller element
    int i = start - 1;

    // traverse through the array from start to end-1
    for (int j = start; j <= end - 1; j++)
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
    swap(&array[i + 1], &array[end]);
    // return the index of the pivot element
    return (i + 1);
}


void RecursiveQuickSort(int array[], int start, int end)
{
    if (start < end)
    {
        // partition the array and get the index of the pivot element
        int pivot_index = partition(array, start, end);
        // recursively call RecursiveQuickSort on the subarrays
        RecursiveQuickSort(array, start, pivot_index - 1);
        RecursiveQuickSort(array, pivot_index + 1, end);
    }
}


int main()
{
    int array_size = 19847;
    int arr[array_size];

    srand(time(NULL));

    // Create the array by adding random elements less than 1000;
    for (int i = 0; i < array_size; i++) {
        arr[i] = rand() % 1000;
    }

    // Start time
    auto start = chrono::high_resolution_clock::now();

    RecursiveQuickSort(arr, 0, array_size - 1);

    // End time
    auto stop = chrono::high_resolution_clock::now();

    // Get the execution time for Recursive QuickSort algorithm
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
