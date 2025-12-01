#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    // constructor:
    // Node(int val) : data(val), next(nullptr) {}
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* addOneHelper(Node* head, int& carry) {
        if (head == NULL) {
            return NULL;
        }
    
        head->next = addOneHelper(head->next, carry);
        int sum = head->data + carry;
        head->data = sum % 10;
        carry = sum / 10;
    
        return head;
    }
Node* addOne(Node* head) {
    int carry = 1;
    Node* newHead = addOneHelper(head, carry);

    // If carry is still non-zero, create an additional node
    if (carry > 0) {
        Node* extraNode = new Node(1);
        extraNode->next = newHead;
        newHead = extraNode;
    }

    return newHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    std::cout << "Original list: ";
    printList(head);

    Node* result = addOne(head);

    std::cout << "Modified list: ";
    printList(result);

    // Clean up memory (don't forget to delete the nodes)
    while (result) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
