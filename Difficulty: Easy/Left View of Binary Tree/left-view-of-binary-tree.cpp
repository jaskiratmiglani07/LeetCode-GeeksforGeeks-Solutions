//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   queue<Node *>q;
   q.push(root);
   vector<int>ans;
   if(!root)
   return ans;
   while(!q.empty())
   {
       int n = q.size();
       ans.push_back(q.front()->data);
       while(n--)
       {
           Node *temp = q.front();
           q.pop();
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
           
       }
   }
   return ans;
//    1
//   / \
//  2   3
// / \
// 4   5
// Initial State
// Queue: [1]
// ans: []
// Iterations
// 1. Outer while loop (first iteration):

// n = q.size(): 1
// ans.push_back(q.front()->data): ans = [1]
// Inner while loop:

// Process node 1: Queue: []
// Enqueue left child (2), right child (3): Queue: [2, 3]
// 2. Outer while loop (second iteration):

// n = q.size(): 2
// ans.push_back(q.front()->data): ans = [1, 2]
// Inner while loop:

// Process node 2: Queue: [3]

// Enqueue left child (4), right child (5): Queue: [3, 4, 5]

// Process node 3: Queue: [4, 5]

// 3. Outer while loop (third iteration):

// n = q.size(): 2
// ans.push_back(q.front()->data): ans = [1, 2, 4]
// Inner while loop:

// Process node 4: Queue: [5]

// Process node 5: Queue: []

// Final State
// Queue: []
// ans: [1, 2, 4]

}
