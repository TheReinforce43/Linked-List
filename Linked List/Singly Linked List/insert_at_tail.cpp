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
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head = NULL;

    while (true)
    {
        cout << "Enter 1 for inserting\n";
        cout << "Enter 2 for Print Linked List\n";
        cout << "Enter 3 for stop the Working Procedure\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the inserting value : \n";
            int key;
            cin >> key;
            Insert_at_tail(head, key);
            break;
        case 2:
            print_linked_list(head);
            break;
        case 3:
            return 0;

        default:
            cout << "Invalid option\n";
            break;
        }
    }

    return 0;
}