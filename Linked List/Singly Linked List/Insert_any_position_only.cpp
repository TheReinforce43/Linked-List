#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node();
    Node (int data)
    {
        this->data=data;
        next=NULL;
    }
};

void Insert_any_position(Node *&head,int pos,int value)
{
    Node *newNode=new Node(value);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node *temp=head;
    for(int i=1;i<=(pos-1);i++)
    {
        temp=temp->next;
    }
}

int main()
{
    
    
    
    return 0;

}