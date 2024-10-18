// COMSC210 | Midterm 1 | Winston Jose
// IDE used: Visual Studio Code
// Github link: https://github.com/winstonjose01/COMSC210-Midterm1

#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {    // Defines the class for the doubly linked list
private:
    struct Node {           // Defines the struct for a node in the linked list
        int data;           // Integer data contained in a node in the list
        Node* prev;         // Pointer to the previous node on the list
        Node* next;         // Pointer to the next node on the list
        Node(int val, Node* p = nullptr, Node* n = nullptr) {      // Constructor to initialize the node
            data = val;     // Initialize the data variable with val parameter
            prev = p;       // Initialize the previous pointer with null pointer
            next = n;       // Initialize the next pointer with the null pointer
        }
    };

    Node* head;     // Pointer to the head or first node of the linked list
    Node* tail;     // Pointer to the tail or last node of the linked list

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }  // Constructor to initialize an empty list

    void insert_after(int value, int position) {        // Method to insert a new node at a given position
        if (position < 0) {                             // Checks if the position value is negative
            cout << "Position must be >= 0." << endl;   // If position is negative, output error message
            return;                                     // Exit the function
        }

        Node* newNode = new Node(value);                // Create a new node the given parameter value
        if (!head) {                                    // Checks if the list is empty
            head = tail = newNode;                      // If the list is empty, assign both the head and tail to the new node
            return;                                     // Exit the function
        }

        Node* temp = head;                              // Create a temporary pointer to traverse the list
        for (int i = 0; i < position && temp; ++i)      // Using a loop, traverse to the specified position
            temp = temp->next;                          // Move to the next node

        if (!temp) {                                     // Check if the position exceeds the list size
            cout << "Position exceeds list size. Node not inserted.\n";    // Output error message
            delete newNode;                              // Delete the newly created node
            return;                                      // Exit the function
        }

        newNode->next = temp->next;                      // Set the next pointer to the new node
        newNode->prev = temp;                            // Set the previous pointer to the new node
        if (temp->next)                                  // Check if the current node has a next node
            temp->next->prev = newNode;                  // Set the previous pointer of the next node to the new node
        else
            tail = newNode;                             // Update the tail to the new node if there is no next node
        temp->next = newNode;                           // Set the next pointer of the current node to the new node
    }

    void delete_val(int value) {                        // Method to delete a node with a specific value
        if (!head) return;                              // Checks if the list is empty , exit the function 

        Node* temp = head;                              // Create temporary pointer to traverse the list
        
        while (temp && temp->data != value)             // Traverse the list until the node with the value is found
            temp = temp->next;                          // Move to the next node

        if (!temp) return;                              // If the value is not found, exit the function

        if (temp->prev)                                 // Checks if the node to be deleted is not the head
            temp->prev->next = temp->next;              // Update the next pointer of the previous node
        else
            head = temp->next;                          // If it's the head, update the head to the next node

        if (temp->next)                                 // Check if the node to be deleted is not the tail
            temp->next->prev = temp->prev;              // Update the previous pointer of the next node
        else
            tail = temp->prev;                          // If it's the tail, update the tail to the previous node

        delete temp;                                    // Delete the temporary node
    }

    void delete_pos(int pos) {                          // Method to delete a node at a specific position
        if (!head) {                                    // Check if the list is empty
            cout << "List is empty." << endl;           // Output error message
            return;                                     // Exit the function
        }
    
        if (pos == 1) {                                 // If the position is 1, it's the head of the list
            pop_front();                                // Call the method to remove the head node
            return;                                     // Exit the function
        }
    
        Node* temp = head;  
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}