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

// Check Critical Point:
bool isCriticalPoint(Node* &currNode){
    if(currNode->prev->data > currNode->data && currNode->next->data > currNode->data) return true;
    if(currNode->prev->data < currNode->data && currNode->next->data < currNode->data) return true;
    return false;
}

// Distance between two critical points in a Doubly Linked List:(min-max)
vector<int> distanceBetweenCriticalPoints(Node* head, Node* tail){
    vector<int> ans(2,-1);
    int firstCP=-1, lastCP=-1;
    Node* currNode = tail->prev;
    if(currNode == NULL){
        return ans;
    }
    int currPos = 0;
    int minDistance = INT_MAX;
    int maxDistance = 0;
    while(currNode->prev != NULL){
        if(isCriticalPoint(currNode)){
            if(firstCP == -1){
                firstCP = currPos;
                lastCP = currPos;
            }
            else{
                minDistance = min(minDistance, (currPos - lastCP));
                maxDistance = currPos - firstCP;
                lastCP = currPos;
            }
        }
        currPos++;
        currNode = currNode->prev;
    }
    if(minDistance == INT_MAX) return ans;
    ans[0] = minDistance;
    ans[1] = maxDistance;
    return ans;
}

int main(){
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(5);
    dll.insert(2);
    dll.insert(6);
    dll.insert(3);

    dll.display();

    vector<int> ans = distanceBetweenCriticalPoints(dll.head, dll.tail);
    cout << "Min Distance: " << ans[0] << endl;
    cout << "Max Distance: " << ans[1] << endl;
    return 0;
}