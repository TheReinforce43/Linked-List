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

void print_node(Node *head)
{
    if(head==NULL) return;
    cout<<head->data<<" ";
    print_node(head->next);
}

bool is_head_null(Node *head)
{
    if (head == NULL)
        return true;
    return false;
}

void Insertion(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (is_head_null(head))
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void delete_head(Node *&head)
{
    if (is_head_null(head))
    {
        cout << "there have no node to delete\n\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    print_node(head);
}

void delete_tail(Node *&head)
{
    if (is_head_null(head))
    {
        cout << "No value to delete\n\n";
        return;
    }
    if(head->next==NULL)
    {
        head=NULL;
        return;
    }
    Node *itr = head;
    while (itr->next->next)
    {
        itr = itr->next;
    }
    Node *temp = itr->next;
    itr->next= NULL;
    delete temp;
    print_node(head);
}

void delete_any_position(Node *&head, int pos)
{
    if (is_head_null(head))
    {
        cout << "No value to delete\n\n";
        return;
    }
    Node *itr = head;
    for (int i = 1; i < (pos - 1); i++)
    {
        itr=itr->next;
    }
    Node *temp = itr->next;
    itr->next = itr->next->next;
    delete temp;
    print_node(head);
}

void print_recursion(Node *head)
{
    if(head==NULL) return;
    print_recursion(head->next);
    cout<<head->data<<" ";
}

int main()
{

    Node *head = NULL;
    int value;
    while (cin >> value && value != -1)
    {
        Insertion(head, value);
    }
    //delete_head(head);
    //delete_tail(head);
    //delete_any_position(head,3);
    print_recursion(head);

    return 0;
}