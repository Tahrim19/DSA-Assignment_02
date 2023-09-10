#include <iostream>
#include <fstream>
#include <sstream>

struct node{
	int number;
	node* next;
	node* prev;
	//node* cursor;
};
node* start = nullptr;




// Function to insert a node in the linked list.
void Add(int num){
    // Create a new node and allocate memory for it.
    node* temp = new node();
	temp->number = num;

    // Check if the linked list is empty.
    if (start == nullptr) {
        // If it's empty, set the 'start' pointer to the new node.
        start = temp;
    } else {
        // If the list is not empty, traverse to the end of the list.
        node* curr = start;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        // Add the new node to the end of the list.
        curr->next = temp;
    }
    return;
    std::cout<<std::endl;
}

void print(){
	node* curr = start;
	while(curr != NULL){
		std::cout << curr->number;
		std::cout << " -> ";
		curr = curr->next;
	}
	std::cout << "null";
}

// Function to delete the last node from the list
void DeleteLast() {
    // Check if the linked list is empty (start is nullptr).
    if (!start) {
        return; 
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
	return;
	std::cout<<std::endl;
}


// Function to add a node at a specific index in the linked list.
void AddAtSpecificIndex(int SearchIndex , int number) {
    int index = 0;      
    node* curr = start; 
    node* prev = nullptr; 

    // Traverse the list until the specified index or the end of the list is reached.
    while (curr != nullptr && index < SearchIndex) {
        prev = curr;    // Update the previous node pointer to the current node.
        curr = curr->next; // Move the current node to the next node in the list.
        index++;        // Increment the index.
    }

    // Check if the index is valid (within the bounds of the list).
    if (index == SearchIndex) {
        // Found the position to insert the new node.

        // Create a new node and input its data.
        node* temp = new node();
        temp->number = number;

        if (index == 0) {
            // If inserting at the beginning (index == 0), update 'start' to point to the new node.
            temp->next = start;
            start = temp;
        } else {
            // Insert the new node between 'prev' and 'curr'.
            prev->next = temp;
            temp->next = curr;
        }
    } else {
        // Index is out of bounds.
        std::cout << "Index out of bounds." << std::endl;
    }
    std::cout<<std::endl;
}

// Function to delete a node at a specific index in the linked list.
void DeleteAtSpecificIndex(int SearchIndex) {
    int index = 0;      
    node* curr = start; 
    node* prev = nullptr; 

    // Traverse the list until the specified index or the end of the list is reached.
    while (curr != nullptr && index < SearchIndex) {
        prev = curr;    // Update the previous node pointer to the current node.
        curr = curr->next; // Move the current node to the next node in the list.
        index++;        // Increment the index.
    }

    // Check if the index is valid (within the bounds of the list).
    if (index == SearchIndex) {
        // Found the node at the specified index.

        // If the node to delete is the first node (index == 0).
        if (index == 0) {
            start = curr->next; // Update 'start' to skip the first node.
        } else {
            prev->next = curr->next; // Update the previous node's 'next' pointer to skip the current node.
        }

        delete curr; // Delete the current node.
    } 
    else {
        // Index is out of bounds.
        std::cout << "Index out of bounds." << std::endl;
    }
    std::cout<<std::endl;
}

// Function to move the cursor forward by a specified number of steps.
int MoveForward(int steps) {
    // Check if the linked list is empty.
    if (!start) {
        std::cout << "List empty." << std::endl;
        return -1;
    }

    node* cursor = start; // Initialize the cursor at the start of the list.
    int index = 0; // Initialize the index to 0.

    for (int i = 0; i < steps; i++) {
        // Check if the cursor has a next node to move to.
        if (cursor->next) {
            cursor = cursor->next; // Move the cursor to the next node.
            index++; // Update the index to reflect the new position.
        } else {
            // If the end of the list is reached before completing 'steps', print a message.
            std::cout << "Reached the end of the list." << std::endl;
            return index;
        }
    }

    // Successfully moved the cursor forward by the specified number of steps.
    std::cout << "Cursor moved forward by " << steps << " steps." << std::endl;
    //std::cout << "Cursor is now at index " << index << " of the list." << std::endl;
    //std::cout << "Value at index " << index << ": " << cursor->number << std::endl;
    std::cout<<std::endl;
    return index;
}

// Function to move the cursor backward by a specified number of steps.
int MoveBackward(int steps) {
    // Check if linked list is empty.
    if (!start) {
        std::cout << "List empty." << std::endl;
        return -1;
    }

    // Initialize cursor and previous node pointers.
    node* curr = start;     
    node* prev = nullptr;     
    int count = 0;            
    int current_index = 0;  

    // Calculate the total number of nodes and find the current index.
    while (curr != nullptr) {
        count++;               // Increment the count to count nodes.
        prev = curr;         // Update 'prev' to the current node.
        curr = curr->next; // Move 'cursor' to the next node.
        current_index++;       // Increment the current index.
    }

    // Reset 'cursor' to the start of the linked list.
    curr = start;

    // Calculate the new position for the cursor.
    int target_position = current_index - steps;

    // Check if the list is empty or if the steps are out of bounds.
    if (!curr || target_position < 0 || steps > count) {
        std::cout << "Steps out of bounds." << std::endl;
        return -1;
    } 

    // Move the cursor to the new position.
    for (int i = 1; i <= target_position; i++) {
        prev = curr;         // Update 'prev' to the current node.
        curr = curr->next; // Move 'cursor' to the next node.
    }
    
    // Information about the cursor's movement.
    std::cout << "Cursor moved backward by " << steps << " steps." << std::endl;
    //std::cout << "Cursor is now at index " << current_index - steps << " of the list." << std::endl;
    //std::cout << "Value at index " << current_index - steps << ": " << curr->number << std::endl;
    std::cout<<std::endl;
    return target_position;
}


// Function to add a node to the current cursor position.
void AddImmediate(int addNum, int cursor_position) {
    // Check if the list is empty.
    if (!start) {
        std::cout << "List is empty." << std::endl;
        return; 
    }

    // Create a new node and allocate memory for it.
    node* addnew = new node();
    addnew->number = addNum; // Set the data for the new node.

    if (cursor_position  == 0) { // Check if 'a' is 0 (insertion at the beginning).
        addnew->next = start; // Update the new node's next pointer to the current start node.
        start = addnew; // Update the start pointer to point to the new node.
        return; 
    }

    node* curr = start; // Initialize 'curr' to the start of the list.
    node* prev = nullptr; // Initialize 'prev' to nullptr (no previous node yet).
    int count = 0; // Initialize a counter to keep track of the current index.

    while (curr != nullptr && count < cursor_position) {
        prev = curr; // Update 'prev' to the current node.
        curr = curr->next; // Move 'curr' to the next node.
        count++; // Increment the counter to track the current index.
    }

    // Check if 'cursor_position' is out of bounds.
    if (count < cursor_position) {
        std::cout << "Index out of bounds." << std::endl;
        return; 
    }

    // Insert the new node between 'prev' and 'curr'.
    prev->next = addnew; // Update the 'next' pointer of 'prev' to point to the new node.
    addnew->next = curr; // Update the 'next' pointer of the new node to point to 'curr'.
    std::cout<<std::endl;
}


// Function to delete the node where the current cursor position is.
void DeleteImmediate(int cursor_position) {
    // Handle the empty list case.
    if (!start) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    // Handle the deletion of the first node of the list.
    if (cursor_position == 0) {
        node* temp = start;
        start = start->next; // Update 'start' to point to the second node.
        delete temp; // Delete the first node.
        print(); // Print the updated list.
        return; // Exit the function after successful deletion.
    }

    node* curr = start;
    node* prev = nullptr;
    int count = 0;
    bool deleted = false; // Initialize the 'deleted' flag to false.

    // Traverse the list to find the node at the specified cursor_position.
    while (curr != nullptr) {
        if (count == cursor_position) {
            prev->next = curr->next; // Update the 'next' pointer of the previous node.
            delete curr; // Delete the current node.
            deleted = true; // Set 'deleted' to true when a node is successfully deleted.
            return; // Exit the loop and the function after successful deletion.
        }
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If the loop completes without finding the specified position, it's out of bounds.
    if (!deleted) {
        std::cout << "Index out of bounds." << std::endl;
    }
    std::cout<<std::endl;
}


// Function to print the data at the current cursor position.
void PrintCursorData(int cursor_position) {
    // Handle empty list case.
    if (!start) {
        std::cout << "The list is empty." << std::endl;
        return; // Exit the function if the list is empty.
    }

    node* curr = start;
    int count = 0;
    
    // Traverse the list to find the node at the specified cursor_position.
    while (curr != NULL) {
        if (count == cursor_position) {
            std::cout  /*<< "The value at current cursor position is: " */ << curr->number << std::endl;
            return; // Exit the function after printing the value.
        }
        count++;
        curr = curr->next;
    }

    // If the loop completes without finding the specified position, it's out of bounds.
    if (count > cursor_position) {
        std::cout << "Index out of bounds." << std::endl;
    }
    return;
}

// Function to update the value of a node at a specific index in the linked list.
void UpdateIndexNumber(int index, int num) {
    // Handle the empty list case.
    if (!start) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    if (index == 0){
    	start->number = num;
    	return;
	}

    node* curr = start; // Initialize 'curr' to the start of the list.
    bool updated = false; // Initialize a flag to track whether the update was successful.
    int count = 0; // Initialize a counter to keep track of the current index.

    // Traverse the list to find the node at the specified index.
    while (curr != nullptr) {
        if (count == index) {
            // Update the data of the node at the specified index.
            curr->number = num;
            updated = true; // Set the flag to true to indicate a successful update.
            return; // Exit the function after updating the value.
        }
        count++; // Increment the counter to track the current index.
        curr = curr->next; // Move 'curr' to the next node.
    }

    // If the loop completes without finding the specified index, it's out of bounds.
    if (!updated) {
        std::cout << "Index out of bounds." << std::endl;
    }
}


// Function to update the value of the node at the current cursor position in the linked list.
void UpdateCursorNumber(int cursor_position, int num) {
    // Handle the case of an empty list.
    if (!start) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    // Check if the cursor position is negative (pointing to NULL).
    if (cursor_position < 0) {
        std::cout << "The cursor is pointing to NULL." << std::endl;
        return;
    }

    node* curr = start; // Initialize 'curr' to the start of the list.
    int count = 0; // Initialize a counter to keep track of the current index.
    bool updated = false; // Initialize a flag to track whether the update was successful.

    // Traverse the list to find the node at the specified cursor position.
    while (curr != nullptr) {
        if (count == cursor_position) {
            // Update the data of the node at the cursor position.
            curr->number = num;
            updated = true; // Set the flag to true to indicate a successful update.
            return; // Exit the function after updating the value.
        }
        count++; // Increment the counter to track the current index.
        curr = curr->next; // Move 'curr' to the next node.
    }

    // If the loop completes without finding the specified cursor position, it's out of bounds.
    if (!updated) {
        std::cout << "Index out of bounds." << std::endl;
    }
}



// Function to shift the data of the cursor node with the data of the node at the specified index.
void Shift(int cursor_position, int index) {
    // Handle the empty list case.
    if (!start) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    node* curr = start; // Initialize 'curr' to the start of the list.
    node* cursor_node = nullptr; // Initialize a pointer for the cursor node.
    node* index_node = nullptr; // Initialize a pointer for the node at the specified index.

    int count = 0; // Initialize a counter to keep track of the current index.

    // Traverse the list to find the cursor node and the node at the specified index.
    while (curr != nullptr) {
        if (count == cursor_position) {
            cursor_node = curr; // Found the cursor node.
        }
        if (count == index) {
            index_node = curr; // Found the node at the specified index.
        }
        if (cursor_node && index_node) {
            break; // Stop searching once both nodes are found.
        }
        curr = curr->next; // Move 'curr' to the next node.
        count++; // Increment the counter to track the current index.
    }

    // Check if both nodes were found.
    if (cursor_node && index_node) {
        // Swap the data values between the cursor node and the node at the specified index.
        int temp = cursor_node->number;
        cursor_node->number = index_node->number;
        index_node->number = temp;
        //std::cout << "Data swapped." << std::endl;
    } else {
        //std::cout << "Index out of bounds." << std::endl;
    }
}



int main(){
	std::string  filepath;
	std::cout << "Enter the file path."<<std::endl;
	std::cin >> filepath;
	
	std::ifstream inputFile(filepath);

	
	if(!inputFile){
		std::cout << "Error opening the file";
		return -1;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int cursor_position;

		if (command == "Add") {
	    int num1, num2;
	    if (iss >> num1) {
	        if (iss >> num2) {
	            AddAtSpecificIndex(num1, num2);
	            std::cout<<std::endl;
	            print();
	        } 
			else {
	            Add(num1);
	            std::cout<<std::endl;
	            print();
	        }
	    	}
		}	
		else if (command == "Delete") {
			int num1;
			if(iss >> num1){
				std::cout<<std::endl;
				DeleteAtSpecificIndex(num1);
			}
			else{
				std::cout<<std::endl;
				DeleteLast();
			}
			print();
        } 
		else if(command == "MoveForward"){
			int num1;
			iss >> num1;
			std::cout<<std::endl;
			cursor_position = MoveForward(num1);
			print();
		} 
		else if(command == "MoveBackwards"){
			int num1;
			iss >> num1;
			std::cout<<std::endl;
			cursor_position = MoveBackward(num1);
			print();
		}
		else if(command == "AddImmediate"){
			int num1;
			iss >> num1;
			std::cout<<std::endl;
			if (cursor_position != NULL){
				AddImmediate(num1 , cursor_position);
			}
			else{
				cursor_position = NULL;
				AddImmediate(num1 , cursor_position);
			}
			print();
		}
		else if(command == "DeleteImmediate"){
			std::cout<<std::endl;
			if (cursor_position != NULL){
				DeleteImmediate(cursor_position);
				print();
			}
			else{
				DeleteImmediate(NULL);
				print();
			}
		}
		else if(command == "Print"){
			std::cout<<std::endl;
			PrintCursorData(cursor_position);
		}
		else if(command == "Update"){
			int num1 , num2;
			iss >> num1 >>num2;
			std::cout<<std::endl;
			UpdateIndexNumber(num1 , num2);
			print();
		}
		else if(command == "UpdateImmediate"){
			int num1;
			iss >> num1;
			std::cout<<std::endl;
			UpdateCursorNumber(cursor_position, num1);
			print();
		}
		else if(command == "Shift"){
			int num1;
			iss >> num1;
			std::cout<<std::endl;
			Shift(cursor_position , num1);
			print();
		}	
    }
    inputFile.close();
	return 0;
}
