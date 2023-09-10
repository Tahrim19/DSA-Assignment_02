#include <iostream>
#include <fstream>
#include <cstdlib>

// Define a structure for a node in the linked list
struct node {
    int number;
    struct node* next = NULL;
};
// Initialize a pointer to the start of the linked list
struct node* start = NULL;

// Function to add a new node to the linked list
int add(int num) {
    node* temp = new node();     // Allocate memory for a new node
    temp->number = num;
    temp->next = NULL; // Initialize the 'next' pointer to NULL

    // If the linked list is empty, make the new node the start
    if (start == NULL) {
        start = temp;
        return 1; // Return 1 to indicate that the node was added successfully
    } else {
        // Traverse the linked list to find the last node
        struct node* curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Add the new node at the end of the linked list
        curr->next = temp;
        return 1; // Return 1 to indicate that the node was added successfully
    }
    
}


// Function to calculate median
double calculateMedian() {
    // Check if the linked list is empty.
    if (start == NULL) {
        std::cout << "List is empty." << std::endl;
        return 0.0; // Return 0.0 if the list is empty
    }

    node* slow = start; // Initialize a slow pointer to the start
    node* fast = start; // Initialize a fast pointer to the start
    node* prev = start; // Initialize a previous pointer to the start

    // Traverse the linked list using the 'slow' and 'fast' pointers.
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;             // Update 'prev' to the current 'slow'
        slow = slow->next;       // Move 'slow' one step
        fast = fast->next->next; // Move 'fast' two steps
    }

    if (fast == nullptr) {
        // Even number of elements, so the median is the average of two middle elements
        return (prev->number + slow->number) / 2.0;
    } else {
        // Odd number of elements, so the median is the middle element
        return (slow->number);
    }
}

// Function to release memory.
void end() {
    struct node* curr = start; // Initialize a temporary pointer to traverse the linked list, starting from 'start'
    while (curr) {   
        struct node* temp = curr;   // Store the current node's address in a temporary pointer 'temp'
        curr = curr->next;   // Move 'curr' to the next node by following the 'next' pointer
        free(temp);   // Release memory allocated for the current node using 'temp'
    }
}

// Function to read input from file
void ReadFile(){
    std::string filepath;
    std::cout << "Enter the file path: " << std::endl;
    std::cin >> filepath;
    std::ifstream inputFile(filepath);
    if (!inputFile) {
        std::cout << "Error Opening the file." << std::endl;
    }
    int num;
    while (inputFile >> num) {
		add(num);
    	//std::cout << "number: "<< num <<std::endl;
        double median = calculateMedian();
        std::cout << "Median " << median << std::endl;
    }
}

int main() {
    ReadFile();
    end();
    return 0;
}

