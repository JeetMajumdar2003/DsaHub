#include<iostream>
#include<vector>
using namespace std;

// Node class
class Node {    
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insertion at the end of the list
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Display the list
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }cout<<endl;
    }
};

// Pair Sum in a Doubly Linked List:
vector<int> pairSum(Node* head, Node* tail, int x){
    vector<int> ans(2,-1);
    Node* start = head;
    Node* end = tail;
    while(start != end){
        int sum = start->data + end->data;
        if(sum == x){
            ans[0] = start->data;
            ans[1] = end->data;
            return ans;
        }
        if(sum < x){
            start = start->next;
        }else{
            end = end->prev;
        }   
    }
    return ans;
}

// Main function
int main(){
    DoublyLinkedList* dll = new DoublyLinkedList();
    dll->insert(2);
    dll->insert(5);
    dll->insert(6);
    dll->insert(8);
    dll->insert(10);
    
    dll->display();

    vector<int> ans = pairSum(dll->head, dll->tail, 10);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}