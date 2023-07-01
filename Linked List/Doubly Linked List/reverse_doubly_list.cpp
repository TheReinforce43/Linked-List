#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
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
        newNode->prev = tail;
        tail = tail->next;
    }
}

void print_tail(Node *tail)
{
    if (tail == NULL)
        return;
    cout << tail->data << " ";
    print_tail(tail->prev);
}

void print_list(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    print_list(head->next);
}

void reverse(Node *&head, Node *curr)
{
    if (curr->next == NULL)
    {
        head = curr;
        head->prev = NULL;
        return;
    }
    reverse(head, curr->next);
    curr->next->next = curr;
    curr->next->prev = curr->next;
    curr->next = NULL;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    while (cin >> value && value != -1)
    {
        Insertion(head, tail, value);
    }
    print_list(head);
    cout << "\n";
    reverse(head, head);
    print_list(head);
    return 0;
}