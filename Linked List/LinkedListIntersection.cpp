/*
Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node() : data(0), next(nullptr) {}
        Node(int x) : data(x), next(nullptr) {}
};


Node* getIntersect(Node *head1, Node *head2, int diff)
{
    Node *t1 = head1;
    Node *t2 = head2;
    while(diff--)
    {
        t1 = t1 -> next;
    }
    
    while(t1 != t2)
    {
        t1 = t1 -> next;
        t2 = t2 -> next;
    }
    
    return t1;
}

int main() {
    
    Node *head1 = new Node(3);
    head1 -> next = new Node(6);
    head1 -> next -> next = new Node(9);
    head1 -> next -> next -> next = new Node(15);
    
    Node *head2 = new Node(10);
    head2 -> next = head1 -> next -> next -> next;
    head2 -> next -> next = new Node(30);
    
    int l1 = 0, l2 = 0;
    Node* t1 = head1;
    while(t1)
    {
        l1++;
        t1 = t1 -> next;
    }
    
    Node* t2 = head2;
    while(t2)
    {
        l2++;
        t2 = t2 -> next;
    }
    
    Node *intersect;
    if(l1 >= l2)
    {
        intersect = getIntersect(head1, head2, l1 - l2);
    }
    else
    {
        intersect = getIntersect(head2, head1, l2 - l1);
    }
    
    if(intersect)
    {
        cout << "intersection node : " << intersect -> data << endl; 
    }
    else
    {
        cout << "Linked lists are not intersecting\n";
    }
    
	return 0;
}