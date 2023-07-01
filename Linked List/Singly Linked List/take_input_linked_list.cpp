#include<bits/stdc++.h>
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

void Insert(Node *&head,int data)
{
    Node *newNode=new Node(data);
    if(head==NULL)
    {
        head=newNode;
        return;
    }   
    Node *temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void Print(Node *head)
{
    if(head==NULL) return;
    Node *temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main()
{
    Node *head=NULL;
    int value;
    while(true)
    {   cin>>value;
        if(value==-1)
        {
            break;
        }
        Insert(head,value);

    }
    Print(head);
    
    return 0;

}