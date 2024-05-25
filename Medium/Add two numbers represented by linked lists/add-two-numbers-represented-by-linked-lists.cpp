//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* Reverse(Node *curr, Node *prev)
    {
        if(curr==nullptr)
        return prev;
        Node *front = curr->next;
        curr->next = prev;
        return Reverse(front, curr);
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        num1 =Reverse(num1, nullptr);
        num2 = Reverse(num2, nullptr);
        Node *curr1 = num1, *curr2 = num2;
        Node *head = new Node(0);
        Node *tail = head; 
        int sum=0, carry = 0;
        while(curr1 && curr2)
        {
            sum = curr1->data + curr2->data + carry;
            tail->next = new Node(sum%10);  
            curr1 = curr1->next;
            curr2 = curr2->next;
            tail = tail->next;
            carry = sum/10;
        }
        while(curr1)
        {
            sum = curr1->data + carry;
            tail->next = new Node(sum%10);
            curr1 = curr1->next;
            tail = tail->next;
            carry = sum/10;
        }
        while(curr2)
        {
            sum = curr2->data + carry;
            tail->next= new Node(sum%10);
            curr2 = curr2->next;
            tail = tail->next;
            carry = sum/10;
        }
        while(carry)
        {
            tail->next = new Node(carry%10);
            tail = tail->next;
            carry = carry/10;
        }
        
        head = Reverse(head->next, nullptr);
        while(head->next && head->data==0)
        head= head->next;
        return head;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends