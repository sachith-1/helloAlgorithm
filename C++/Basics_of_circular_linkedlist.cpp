#include <bits/stdc++.h>
using namespace std;

// defining the linked list  node
struct node {
    int data;
    struct node* next;
};

typedef struct node* lptr;
// function to print the circuilar linked list
void printCLL(lptr ref)
{
    lptr first = ref;
    do    
    {
        cout<<ref->data<<" ";
        ref=ref->next;
    }while(ref!=first);
    cout<<endl;
}
// making a flat linked list to circular one
void makeCircular(lptr *head)
{
    lptr ref = *head;
    lptr headRef = *head;
    while(ref->next)
    {
        ref=ref->next;
    }
    ref->next=headRef;
    *head=headRef;
}
// insert a value at the end
void insert(lptr ref,int val)
{
    lptr nxt = ref->next;
    lptr newnode = new(node);
    newnode->data = val;
    ref -> next = newnode;
    newnode->next = nxt;
}
// find length of ll
int findLen(lptr ref)
{
    lptr first  = ref;
    int len = 0;
    do
    {
        len++;
        ref = ref->next;
    } while (ref!=first);
    return len;
    
}

// splitting into two halves
void split(lptr head,lptr *part1,lptr *part2)
{
    int n=findLen(head);
    lptr curr1=*part1,curr2=*part2;
    lptr head1=*part1,head2=*part2;
    for(int i=1;i<=n;i++)
    {
        if(i<=(n+1)/2)
        {
            insert(curr1,head->data);
            curr1=curr1->next;
        }
        else
        {
            insert(curr2,head->data);
            curr2=curr2->next;
        }
        head=head->next;
    }
    *part1=head1->next;
    *part2=head2->next;
    curr1->next=*part1;
    curr2->next=*part2;
}

// delete node with the given key
void deleteNode(lptr *head, int key)
{
    lptr first = *head;
    lptr ref = *head;
    if(first->data==key)
    {
        *head=first->next;
        return;
    }
    do
    {
        if(ref->next->data==key)
        {
            ref->next=ref->next->next;
            break;
        }
        ref=ref->next;
    }while(ref!=first);
}

// code for sorted insert
void sortedInsert(lptr *head, int key)
{
    lptr first=*head;
    if(first->data>key)
    {
        lptr newNode = new(node);
        newNode->data=key;
        newNode->next=first;
        *head=newNode;
        return;
    }
    lptr ref = *head;
    do
    {
        if(ref->next->data>key)
        {
            lptr newNode = new(node);
            newNode->data=key;
            lptr nxt = ref->next;
            ref->next=newNode;
            newNode->next=nxt;
            return;
        }
        ref=ref->next;
    }while(ref->next!=first);
    
    lptr newNode = new(node);
    newNode->data=key;
    ref->next=newNode;
    newNode->next=first;
    return;
}

// check if ll is circular or not
bool isCircular(lptr head)
{
    lptr slow = new(node);
    lptr fast = new(node);
    slow = head;
    fast=head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

// josephus algorithm
int josephus(lptr head, int m)
{
    lptr ref = head;
    while(ref->next!=ref)
    {
        for(int i=1;i<m-1;i++)
        {
            ref = ref->next;
        }
        ref->next = ref->next->next;
        ref = ref->next;
    }
    return ref->data;
}
int main()
{
    lptr head = new(node);
    head->data = 1;
    lptr curr = head;
    curr->next=NULL;
    for(int i=0;i<6;i++)
    {
        insert(curr,i+2);
        curr=curr->next;
    }
    makeCircular(&head);
    printCLL(head);
    cout<<findLen(head);
    lptr part1 = new(node);
    lptr part2 = new(node);
    split(head,&part1,&part2);
    printCLL(part1);
    printCLL(part2);
    deleteNode(&head,4);
    printCLL(head);
    sortedInsert(&head,4);
    printCLL(head);
    isCircular(head) ? cout<<"yes" : cout<<"no";
    cout<<"\nThe survivor is "<<josephus(head,6);
}