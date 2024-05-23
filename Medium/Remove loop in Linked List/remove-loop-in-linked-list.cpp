//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        
//is there even a loop?
//bring back the slow pointer to head
//they will meet at the beginning of the loop if both of them move one node at a time now.
//now move ahead slow until the next of slow equals fast, and when it does, break the link.
// Node *slow = head;
// Node *fast = head;
// while(fast != nullptr && fast->next != nullptr)
// {
//     slow = slow->next;
//     fast = fast->next->next;
//     if(slow == fast)
//     break;
// }
// if(fast == nullptr|| fast->next == nullptr)
// return;
// slow = head;
// while(slow != fast)
// { 
//     slow = slow->next;
//     fast = fast->next;
// }
// while(slow->next != fast)
// {
//     slow = slow->next;
// }
// slow->next = nullptr;
//method 2
    Node *slow=head, *fast=head;
    //checking if the loop exists or not
    while( fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
        break;
    }
    if(!fast||!fast->next)
    return;
    //find the length of loop
    slow = fast->next;
    int count = 1;
    while(slow!=fast)
    {
        count++;
        slow = slow->next;
    }
    
    slow = head, fast = head;
    while(count--)
    {
        fast = fast->next;
    }
    while( slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    //bring slow to the last node
    while( slow->next !=fast)
    {
        slow=slow->next;
    }
    slow->next= nullptr;
        // just remove the loop without losing any nodes
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends