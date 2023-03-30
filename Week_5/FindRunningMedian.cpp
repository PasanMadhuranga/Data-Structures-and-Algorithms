#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void InsertToSortedArr(vector<int>& num_arr, int num){
    int j = num_arr.size() - 1;
    // If the array has no elements, just insert the number.
    if (j < 0){
        num_arr.push_back(num);
    }
    else{
        // Identify the correct position that number has to insert.
        while (j >= 0 && num_arr[j] > num) {
        j--;
        }
        // Insert the number to that correct position.
        num_arr.insert(num_arr.begin() + j + 1, num);
    }
}


double GetMedian(vector<int>& num_arr){
    double median;
    if (num_arr.size() % 2 == 1){ // If the array has odd number of elements get the middle element.
        median = (double)num_arr[num_arr.size() / 2];
    }
    else {
        // If the element has even number of elements, get the average of the two middle elements of the sorted array as median.
        int mid = num_arr.size() / 2;
        median = (num_arr[mid] + num_arr[mid - 1]) / 2.0;
    }
    return round(median * 10.0) / 10.0; // return the median round to first decimal place.
}


int main() {
    vector<int> sorted_num_arr; // Store the user entered numbers
    int num_of_inputs;
    cout << "How many numbers are you going to input? "; // Get the number of inputs that the user is going to input.
    cin >> num_of_inputs;
    int num;
    for (int i = 0; i < num_of_inputs; i++){ // Get inputs from the user
        cout << "Enter number " << (i + 1) << ": ";
        cin >> num;
        InsertToSortedArr(sorted_num_arr, num); // Enter the number to the correct position of the sorted array.
        cout << "Median: " << GetMedian(sorted_num_arr) << endl; // Print the median of the sorted array.
    }
    return 0;
}
