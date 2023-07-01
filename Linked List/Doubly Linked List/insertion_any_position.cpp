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

void Insert_any_position(Node *&head, Node *&tail, int value, int pos)
{
    if (pos < 0)
        return;
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        Insertion(head, tail, value);
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            if (temp == NULL)
                return;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
}
void print_list(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    print_list(head->next);
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
    int pos;
    cin >> pos>> value;
    Insert_any_position(head, tail, value, pos);
    cout << endl;
    print_list(head);

    return 0;
}