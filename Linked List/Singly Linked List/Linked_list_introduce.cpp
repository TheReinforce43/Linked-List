#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }

};

int main()
{

    Node a(10), b(20);
    //a.data = 12;
    //b.data = 16;
    a.next = &b;
    cout << a.data << " " << a.next->data << endl;

    return 0;
}