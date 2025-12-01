#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& st)
{
    stack<int> tm;
    while (!st.empty()){
        int topElement = st.top();
        st.pop();
        while (!tm.empty() && topElement > tm.top()){
            st.push(tm.top());
            tm.pop();
        }
        tm.push(topElement);
    }
    // now tm has the elements in decreasing order, where top is the smallest
    while (!tm.empty()){
        st.push(tm.top());
        tm.pop();
    }
    return;
}


int main()
{
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);
    cout<<s.top()<<endl;
    sortStack(s);
    cout<<s.top()<<endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}