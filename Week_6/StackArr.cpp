#include <iostream>
#include <chrono>

using namespace std;

int top = -1; // initialize top to -1, indicating the stack is empty
int* stack_arr; // array to hold the stack elements
int* max_size;

bool isEmpty(){ // Check if stack is empty
    return top < 0;
}

bool isFull(){ // Check if stack is full
    return top >= (*max_size - 1); 
}

int StackTop(){ // Return the top element of the stack
    if (isEmpty()){ // If stack is empty, print error message and return
        cout << "Stack Underflow\n";
        return 0;
    }
    return stack_arr[top];
}

void Display(){ // Display the elements of the stack
    if (isEmpty()){ // If stack is empty, print error message and return
        cout << "Stack Underflow\n";
        return;
    }

    for(int i = top; i >= 0; i--){ // Print each element of the stack from top to bottom
        cout << stack_arr[i] << endl;
    }
    cout << endl;
}

void Push(int x) { // Function to push an element onto the stack
    if (isFull()) { // If stack is full, print error message and return 0
        cout << "Stack Overflow\n"; 
        return;
    }
    stack_arr[++top] = x; // Increment top and insert the element
}

int Pop() { // Remove and return the top element of the stack
    if (isEmpty()) { // If stack is empty, print error message and return 0
        cout << "Stack Underflow\n"; 
        return 0;
    }
    return stack_arr[top--]; // Remove and return the top element
}


int main(int argc, char const *argv[])
{
    max_size = new int;
    cout << "What is the size of the stack: ";
    cin >> *max_size;
    stack_arr = new int[*max_size];
    auto start = chrono::high_resolution_clock::now(); // get current time  
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    auto end = chrono::high_resolution_clock::now(); // get current time
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start); // calculate time difference in microseconds
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}


