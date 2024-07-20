//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int find(int in[], int target, int start, int end)
{
    for(int i = start; i<=end; i++)
    {
        if(in[i]==target)
        return i;
    }
    return -1;
}

 Node *tree(int in[], int pre[], int inStart, int inEnd, int index) //inStart and inEnd depict the beginning and end of in-order array whereas index denotes the starting index of pre-order array
 {
        if(inStart > inEnd)
        return nullptr;
        Node *root = new Node(pre[index]);
        int pos = find(in, pre[index], inStart, inEnd);
        root->left = tree(in, pre, inStart, pos-1, index+1);
        root->right = tree(in, pre, pos+1, inEnd, index+(pos-inStart)+1);
        return root;
 }

class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        //step 1
        //get the first element out of pre-order
        //step 2
        //find the position of that first element in in-order
        //step 3
        //divide into left and right sub-categories
        return tree(in, pre, 0, n-1, 0);
        

    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends