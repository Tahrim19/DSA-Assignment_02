#include <iostream>
#include <fstream>
#include <sstream>

struct TransactionNode {
    int Transaction_ID;         
    int Transaction_Amount;    
    TransactionNode* next;     
};

TransactionNode* start = nullptr;

// Function to insert a new transaction node into a linked list.
void InsertTransaction(int Transaction_ID, int Transaction_Amount) {
    TransactionNode* temp = new TransactionNode(); // Allocating memory for a new node.
    
    // Set the Transaction_ID and Transaction_Amount for the new node.
    temp->Transaction_ID = Transaction_ID;
    temp->Transaction_Amount = Transaction_Amount;
    
    temp->next = nullptr; // Setting the pointer of the new node to null.
    
    TransactionNode* current = start;      // Create a pointer 'current' to traverse the linked list.
    
    // If the linked list is empty, make the new node the 'start' of the list and return.
    if (start == nullptr) {
        start = temp;
        return;
    }
    else {
        // Traverse the list until the last node is reached.
        while (current->next != nullptr) {
            current = current->next;
        }
        
        // Set the 'next' pointer of the current last node to point to the new node, 
        // effectively adding the new node to the end of the list.
        current->next = temp;
    }
}


// Function to delete a fraudulent transaction by its Transaction_ID.
void DeleteTransaction(int Fraudulent_ID) {
    TransactionNode* current = start; // Initialize a pointer 'current' to the start of the list.
    TransactionNode* prev = nullptr; // Initialize a pointer 'prev' to keep track of the previous node.

    while (current != nullptr) {
        
        if (current->Transaction_ID == Fraudulent_ID) {  // Check if the 'Transaction_ID' matches 'Fraudulent_ID'.
            if (prev == nullptr) {
                // If 'prev' is null, it means the current node is the first node in the list.
                // Update 'start' to point to the next node (removing the first node).
                start = current->next;
            } else {
                // If 'prev' is not null, it means the current node is not the first node.
                // Update the 'next' pointer of the previous node to skip the current node.
                prev->next = current->next;
            }
            
            // Delete the current node to free up memory.
            delete current; 
            
            return; // Exit the function after deleting the node.
        }
        
        // Move 'prev' and 'current' pointers to the next nodes in the list.
        prev = current;
        current = current->next;
    }
}


// Function to print the transactions in the linked list
void printTransactions() {
    TransactionNode* current = start; // Initialize a pointer to traverse the linked list
    // Traverse the linked list
    while (current != nullptr) {
        // Print the transaction details for the current node
        std::cout << "Transaction ID: " << current->Transaction_ID << ", Amount: " 
		<< current->Transaction_Amount << std::endl;  
	
	    // Move to the next node
        current = current->next;
    }
}

// Function to delete all nodes in the linked list.
void End() {
    TransactionNode* current = start;

    // Traverse the linked list and delete each node.
    while (current != nullptr) {
        TransactionNode* temp = current; // Create a temporary pointer to the current node.
        current = current->next; // Move to the next node before deleting the current node.
        delete temp; // Delete the current node using the temporary pointer.
    }
    start = nullptr; // Update 'start' to indicate an empty linked list.
}


// Function to read data from a file and process transactions.
void ReadFile() {
    std::string filepath;
    std::cout << "Enter the file path: "<< std::endl;
    std::cin >> filepath;
    std::ifstream inputFile(filepath);    // Open the file for reading.

    // Check if the file was successfully opened.
    if (!inputFile) {
        std::cout << "Error Opening the file." << std::endl;
        return;
    }

    int Total_Transactions, Total_Fraudulent;
    // Read the total number of transactions and fraudulent transactions from the file.
    inputFile >> Total_Transactions >> Total_Fraudulent;
    inputFile.ignore(); // Consume the newline character

    // Read and insert or delete transactions based on the file content.
    int t = Total_Transactions + Total_Fraudulent;
    int Transaction_ID, Transaction_Amount;
    int Fraudulent_ID;
    
    for (int i = 0; i < t; ++i) {
        std::string line;
        std::getline(inputFile, line);

        if (line.find(',') != std::string::npos) {
            // If the line contains a comma, it's a transaction line.
            std::istringstream iss(line);
            
            char comma;
            iss >> Transaction_ID >> comma >> Transaction_Amount;
            
            // Insert the transaction into the linked list.
            InsertTransaction(Transaction_ID, Transaction_Amount);
        } else if (!line.empty()) {
            // If the line is not empty, it's a fraudulent ID line.
            Fraudulent_ID = std::stoi(line);
            
            // Delete the transaction with the fraudulent ID from the linked list.
            DeleteTransaction(Fraudulent_ID);
        }
    }
    
    // Print the transactions in the linked list.
    printTransactions();

    // Close the input file.
    inputFile.close();
}



int main() {
    ReadFile(); // Call 'ReadFile()' function.
    End(); // // Call 'End()' function to free the memory.
    
    return 0;
}




