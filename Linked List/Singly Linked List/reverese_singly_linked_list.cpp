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
        return;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

void print_list(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void reverse_node(Node *&head, Node *cur)
{
    if (cur->next == NULL)
    {
        head = cur;
        return;
    }
    reverse_node(head, cur->next);
    cur->next->next = cur;
    cur->next = NULL;
}

int main()
{

    Node *head = NULL, *tail = NULL;
    int value;
    while (cin >> value && value != -1)
    {
        Insertion(head, tail, value);
    }

    print_list(head);
    reverse_node(head, head);
    print_list(head);

    return 0;
}