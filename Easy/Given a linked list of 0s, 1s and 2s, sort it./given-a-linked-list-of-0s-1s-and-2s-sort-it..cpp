//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
//take a pointer in the beginning and count the number of 0s, 1s and 2s
// count 0=
// count 1= 
// count 2=
//change the data by first assigning 0s till count0 becomes 0, then assign 1s till count1 becomes 0 and subsequently assign 2s until count2 becomes 0.
    Node *curr=head;
    int count0=0, count1=0, count2=0;
    while(curr!=nullptr)
    {
        if(curr->data == 0)
        count0++;
        else if(curr->data == 1)
        count1++;
        else
        count2++;
        curr = curr->next;
    }
    curr = head;
    while(count0--)
    {
        curr->data = 0;
        curr=curr->next;
    }
    while(count1--)
    {
        curr->data = 1;
        curr=curr->next;
    }
    while(count2--)
    {
        curr->data = 2;
        curr=curr->next;
    }
    return head;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends