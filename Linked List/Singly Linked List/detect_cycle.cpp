#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void Insertion(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

void print_list(Node *head)
{
    if (head == NULL)
        return;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

bool detect_cycle(Node *head)
{
    if (head == NULL)
        return false;
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;
    if (detect_cycle(head))
    {
        cout << "Cycle Detected\n";
    }
    else
    {
        cout << "Cycle Not Detected\n";
    }
    return 0;
}