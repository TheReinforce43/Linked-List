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



void print_value(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    print_value(head->next);
}

void Insertion(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head==NULL)
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

void Sorting(Node *head)
{
    if (head == NULL)
        return;
    Node *first = head;
    while (first->next)
    {
        Node *second = first->next;
        while (second)
        {
            if (first->data > second->data)
                swap(first->data, second->data);
            second = second->next;
        }
        first = first->next;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int value;

    while (cin >> value && value != -1)
    {
        Insertion(head,tail,value);
    }
    Sorting(head);
    print_value(head);

    return 0;
}