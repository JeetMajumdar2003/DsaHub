#include<iostream>
using namespace std;

// Template Node Class: it is used to create a node of any data type
template<typename T>
class Node{
    public:
        T data;
        Node<T> *next;

        Node(T data){
            this->data = data;
            next = NULL;
        }
};

int main(){
    Node<int>* node1 = new Node<int> (1);
    cout<<node1->data<<endl;

    Node<char>* node2 = new Node<char> ('A');
    cout<<node2->data<<endl;

    return 0;
}