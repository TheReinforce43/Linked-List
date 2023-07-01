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

void Insert_at_tail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
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

void Insert_at_any_position(Node *&head, int data, int index)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    int i = 1;
    Node *temp = head;
    while (temp && i != index)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        temp->next = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void Insert_at_head(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void Print_linked_list(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty\n";
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void Delete_value_at_head(Node *&head)
{
    if (head == NULL)
        return;

    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void Delete_from_position(Node *&head, int pos)
{
    Node *temp = head;
    if (head == NULL)
        return;
    for (int i = 1; i <= pos - 1; i++)
    {
        if (temp == NULL)
            return;
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    if (temp->next == NULL)
    {
        return;
    }
    temp->next = temp->next->next;
    delete deleteNode;
}
int main()
{

    Node *head = NULL;
    while (true)
    {
        cout << "Enter 1 for adding in tail : \n";
        cout << "Enter 2 for Insert at any position : \n";
        cout << "Enter 3 for print the linked list: \n";
        cout << "Enter 4 for Insert at head \n";
        cout << "Enter 5 for Delete value at head\n";
        cout << "Enter 6 for Delete value at any position\n";
        cout << "Enter 7 for Delete value at tail\n";
        cout << "Enter 8 for break: \n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the data\n";
            int data;
            cin >> data;
            Insert_at_tail(head, data);
            break;
        case 2:
            cout << "Enter the position and data\n";
            int pos;
            cin >> pos >> data;
            Insert_at_any_position(head, data, pos);
            break;
        case 3:
            Print_linked_list(head);
            break;
        case 4:
            cout << "Enter the value \n";
            cin >> data;
            Insert_at_head(head, data);
            break;
        case 5:
            Delete_value_at_head(head);
            break;
        case 6:
            cout << "Enter the position\n";
            cin >> pos;
            Delete_from_position(head, pos);
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid option\n";
            break;
        }
    }

    return 0;
}