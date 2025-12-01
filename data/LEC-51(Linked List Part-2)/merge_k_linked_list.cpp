#include <iostream>
#include <vector>
using namespace std;

// Node Class
class Node {
   public:
    int val;
    Node* next;

    // Constructor
    Node(int data) {
        val = data;
        next = NULL;
    }
};

// Linked List Class
class LinkedList {
   public:
    Node* head;

    // Constructor
    LinkedList() {
        this->head = nullptr;
    }

    // Insert
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = this->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display
    void display() {
        Node* temp = this->head;
        while (temp != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Merge Two Sorted Linked List:(Without Creating new linkedlist)
Node* mergeLinkedList(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1); 
    Node* ptr3 = dummyNode;

    Node* temp1 = head1;
    Node* temp2 = head2;

    // Compare 
    while (temp1 != NULL && temp2 != NULL){
        if (temp1->val <= temp2->val){
            ptr3->next = temp1;
            temp1 = temp1->next;
        }
        else{
            ptr3->next = temp2;
            temp2 = temp2->next;
        }
        ptr3 = ptr3->next;
    }

    if (temp1 != NULL){
        ptr3->next = temp1;
    }
    else{
        ptr3->next = temp2;
    }
    
    Node* newHead = dummyNode->next;
    return newHead;
}

// Merge K Sorted Linked List
Node* mergeKLinkedList(vector<Node*> &lists){
    while (lists.size() > 1){
        Node* mergedList = mergeLinkedList(lists[0], lists[1]);
        lists.push_back(mergedList);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

/**
vector —> headl head2 head3 head4
1. headl and head2 It will be merged
vector —> head3 head4 mergedhead1_2
2. head3 and head4 will be merged
vector —> mergedhead1_2 mergedhead3_4
3. mergedhead1_2 and mergedhead3_4 will be merged
vector mergedhead1_2_3_4
*/

// Node* mergeKLinkedList(Node* lists[], int k){
//     while (k != 0){
//         int i = 0, j = k;
//         while (i < j){
//             lists[i] = mergeSortLL(lists[i], lists[j]);
//             i++;
//             j--;
//             if (i >= j){
//                 k = j;
//             }
//         }
//     }
//     return lists[0];
// }


int main(){
    // Create two linked list
    LinkedList l1;
    l1.insert(1);
    l1.insert(4);
    l1.insert(7);
    l1.insert(8);

    LinkedList l2;
    l2.insert(3);
    l2.insert(5);
    l2.insert(6);

    LinkedList l3;
    l3.insert(2);
    l3.insert(9);
    l3.insert(10);

    LinkedList l4;
    l4.insert(11);
    l4.insert(12);
    l4.insert(13);

    // Print the linked list
    l1.display();
    l2.display();
    l3.display();
    l4.display();

    // Vector of linked list head
    vector<Node*> lists = {l1.head, l2.head, l3.head, l4.head};
    
    // Merge K Sorted Linked List
    LinkedList mergedLL;
    mergedLL.head = mergeKLinkedList(lists);
    mergedLL.display();



    return 0;
}