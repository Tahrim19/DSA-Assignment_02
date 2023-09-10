#include <iostream>
#include <cstdlib>
#include <fstream>

// Structure definition for a node in the linked list
struct node {
    int number;  // Holds the integer value of the node
    struct node* next = NULL;  // Points to the next node in the list (initialized to NULL)
};

node* start = NULL;  // Points to the first node in the linked list
node* thirdLastNode = NULL;  // Points to the third-to-last node in the linked list

int count = 0; // Counter to keep track of the number of nodes in the linked list

// Function to add a new node to the linked list
void add(int num) {
    // Allocate memory for a new node 
    node* temp = new struct node;
    temp->number = num;  // Read and store the user input in the 'number' field of the new node
    temp->next = NULL;  // Initialize the 'next' pointer of the new node to NULL

    // If the linked list is currently empty, make the new node the start of the list
    if (start == NULL) {
        start = temp;
    } 
	else {
        // Traverse the linked list to find the last node and append the new node
        struct node* curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    
    count++; // Increment the node count

    // Update the 'thirdLastNode' pointer if there are at least 3 nodes in the list
    if (count >= 3) {
        if (count == 3) {
            thirdLastNode = start; // If this is the third node, 'thirdLastNode' points to 'start'
        } 
		else {
            thirdLastNode = thirdLastNode->next; // Otherwise, update 'thirdLastNode' to point to the next node
        }
    }
}



// Function to release memory 
void end() {
    struct node* curr = start; // Initialize a temporary pointer to traverse the linked list, starting from 'start'
    while (curr) {   
        struct node* temp = curr;   // Store the current node's address in a temporary pointer 'temp'
        curr = curr->next;   // Move 'curr' to the next node by following the 'next' pointer
        free(temp);   // Release memory allocated for the current node using 'temp'
    }
}

// Function to get the value of the third-to-last element in the linked list
int getThirdLastIndex() {
    int thirdLastValue = -1; // Initialize the value to -1 (default if there's no third-to-last element)

    if (count >= 3) { // Only proceed if there are at least 3 nodes in the linked list
        struct node* curr = start; // Initialize a temporary pointer to traverse the linked list, starting from 'start'
        for (int i = 0; i < count - 3; ++i) { // Traverse to the third-to-last node by moving 'curr' (count - 3) times
            curr = curr->next;
        }
        thirdLastValue = curr->number; // Retrieve the 'number' value of the third-to-last node
    }
    return thirdLastValue; 
}

// Function to read input from the file
void ReadFile() {
    std::string filepath;
    std::cout << "Enter the file path: " << std::endl;
    std::cin >> filepath;

    std::ifstream inputFile(filepath);

    if (!inputFile) {
        std::cout << "Error Opening the file." << std::endl;
        return;   
    }
   
    int num;
    while (inputFile >> num) {
        add(num);
    }
    int var= getThirdLastIndex();
    std::cout << var;
    inputFile.close();
}


int main() {
   ReadFile();
   end();

    return 0; 
}

