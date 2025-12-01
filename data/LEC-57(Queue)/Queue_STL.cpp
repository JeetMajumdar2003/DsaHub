#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.back() << endl;
    q.pop();
    q.pop();
    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Empty or not: " << q.empty() << endl;
    q.emplace(50);
    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.back() << endl;
    
    return 0;
}