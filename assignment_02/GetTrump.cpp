#include <iostream>
#include <fstream>
#include <string>

struct node {
    int number;
    struct node* next = nullptr;
};

struct node* start = nullptr;

// Function to insert a node in the list
void add(int number) {
    node* temp = new node();   // Create a new node and allocate memory for it.
    temp->number = number;    // Set the number stored in the new node to the input 'number'.
    temp->next = nullptr;     // Initialize the 'next' pointer of the new node to nullptr.
    
    // Check if the linked list is empty (start is null).   
    if (start == nullptr) {   
        start = temp;    // If the list is empty, set the 'start' pointer to the new node.
    } 
	else {   // If the list is not empty, traverse the list to find the last node.
        node* curr = start;    // Start at the beginning of the list.
        while (curr->next != nullptr) {   // Traverse the list until we reach the last node (where 'next' is nullptr).
            curr = curr->next;
        }
        curr->next = temp;   // Link the last node's 'next' pointer to the new node, making it the new last node.
    }
}

// Function to delete the last node from the list
void deleteLast() {
    // Check if the linked list is empty (start is nullptr).
    if (!start) {
        return;  // Nothing to delete if the list is empty.
    }

    // Check if there is only one node in the list.
    if (!start->next) {
        delete start;  // Delete the single node
        start = nullptr;  // Set the 'start' pointer to nullptr to indicate an empty list.
        return;
    }
    node* curr = start;   // If there are multiple nodes, traverse the list to find the second-to-last node.
 
    // Traverse the list until the second-to-last node (where 'next' of next is nullptr).
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;   // Delete the last node (which is currently pointed to by 'curr->next').
    curr->next = nullptr;  // Set the 'next' pointer of the second-to-last node to nullptr
}

// Function to delete the whole list
void end() {
    node* curr = start;  // Start at the beginning of the linked list.
    
    while (curr != nullptr) {   // Loop through the linked list until 'curr' becomes nullptr.
        node* temp = curr;  // Create a temporary pointer 'temp' to hold the current node.
        curr = curr->next;   // Move 'curr' to the next node in the list.
        delete temp;   // Delete the current node, freeing its memory.
    }
    start = nullptr;   // All the nodes has been deleted. Set the start pointer to null to indicate an empty list.
}


// Function to find the middle element of the list
void GetTrump() {
    // Check if the linked list is empty.
    if (!start) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    // Initialize two pointers, 'slow' and 'fast', to traverse the linked list.
    node* slow = start; // 'slow' moves one step at a time.
    node* fast = start; // 'fast' moves two steps at a time.
    node* prev = nullptr; // Initialize a pointer to keep track of the previous node to 'slow'.

    // Traverse the linked list using the 'slow' and 'fast' pointers.
    while (fast && fast->next) {
        prev = slow; // Update 'prev' to the current 'slow' node.
        slow = slow->next; // Move 'slow' one step forward.
        fast = fast->next->next; // Move 'fast' two steps forward.
    }

    // Check if 'fast' is not null. If it's not null, the list has an odd number of elements.
    if (fast) {
        std::cout << "Middle element: " << slow->number << std::endl;
    } else {
        // If 'fast' is null, the list has an even number of elements.
        std::cout << "Middle elements: " << prev->number << " and " << slow->number << std::endl;
    }
}


// Function to read input from the file
void ReadFile() {
    // Prompt the user to enter the file path.
    std::string filepath;
    std::cout << "Enter the file path: " << std::endl;
    std::cin >> filepath;

    // Open the specified file for reading.
    std::ifstream inputFile(filepath);

    // Check if the file opening was successful.
    if (!inputFile) {
        std::cout << "Error Opening the file." << std::endl;
        return;   // Return from the function if the file couldn't be opened.
    }

    std::string line;   // Store each line of input from the file.
    int number;   // Store an integer read from the file.

    // Read lines from the file until the end is reached.
    while (inputFile >> line) {
        if (line == "ADD") {
            // If the line is "ADD," try to read an integer (number) from the file.
            if (inputFile >> number) {
                // If successful, add the number to the linked list.
                add(number);
            } 
			else {
                // If the line is "ADD" but no number is provided, print an error message and return.
                std::cout << "Error: ADD command missing a number." << std::endl;
                return;
            }
        } 
		else if (line == "DELETE") {
            // If the line is "DELETE," delete the last node from the linked list.
            deleteLast();
        } 
		else if (line == "END") {
            // If the line is "END," call GetTrump to print the middle element.
            GetTrump();
            end();
            return;
        }
    }
    
    // Close the input file when done reading.
    inputFile.close();
}

int main() {
    ReadFile();
    end();

    return 0;
}

