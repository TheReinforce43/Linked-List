#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    Node();
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    void print(Node *head)
    {
        while(head)
        {
            cout<<head->data<<"\n";
            head=head->next;
        }
    }
};

int main()
{

    Node *head = new Node(10);
    Node *a = new Node(206);
    Node *b=new Node(50);
    head->next = a;
    a->next=b;
    //cout << head->data << " "<< a->data;
    Node *temp=head;
    while(temp)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    return 0;
}