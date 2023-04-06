#include <iostream>
#include <chrono>

using namespace std;

// Define the structure of a node in the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL; // initialize top to NULL, indicating the stack is empty
int* max_size;
int current_size = 0;

// Check if the stack is empty
bool isEmpty(){
    return top == NULL;
}

bool isFull(){ // Check if stack is full
    return current_size >= *max_size; 
}

// Get the data of the top node in the stack
int StackTop(){
    if (isEmpty()){
        cout << "Stack Underflow\n";
        return 0;
    }
    return top->data;
}

// Display the elements of the stack
void Display(){
    if (isEmpty()){ // If stack is empty, print error message and return
        cout << "Stack Underflow\n";
        return;
    }

    Node* currentNode = top;
    while (currentNode != NULL){
        cout << currentNode->data << endl;  // Print the data of the current node
        currentNode = currentNode->next;    // Move to the next node
    }  
    cout << endl;
}

// Insert an element at the top of the stack
void Push(int x) {
    if (isFull()) { // If stack is full, print error message and return 0
        cout << "Stack Overflow\n"; 
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node)); // allocate memory for a new node
    newNode->data = x;                  
    newNode->next = top;                
    top = newNode;
    current_size++;                      
}

// Function to remove the top element from the stack and return its value
int Pop() {
    if (isEmpty()) { // If stack is empty, print error message and return
        cout << "Stack Underflow\n";
        return 0;
    }
    else {
        current_size--;
        int x = top->data; // retrieve the data from the top node
        top = top->next; // Set the top to the next node
        return x; // return the data of the removed node
    }
}

int main() {
    max_size = new int;
    cout << "What is the size of the stack: ";
    cin >> *max_size;

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
