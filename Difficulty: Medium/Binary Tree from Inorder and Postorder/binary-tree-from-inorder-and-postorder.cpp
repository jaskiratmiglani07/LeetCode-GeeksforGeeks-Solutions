//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
int find(int in[], int target, int start, int end)
{
    for(int i = start; i<=end; i++)
    {
        if(in[i]==target)
        return i;
    }
    return -1;
}
Node *tree(int *in, int *post, int inStart, int inEnd, int index)
{
    if(inStart > inEnd)
    return nullptr;
    Node * root = new Node(post[index]);
    int pos = find(in, post[index], inStart, inEnd);
    root->right = tree(in, post, pos+1, inEnd, index-1);//index-1 tells the index of the first element that is to the right of the node in the post order array
    root->left = tree(in, post, inStart, pos-1, index-(inEnd-pos)-1);//index-(inEnd-inStart)-1 tells the index of the first element that is to the left of the node in the post order array
    return root;
}

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        tree(in, post, 0, n-1, n-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends