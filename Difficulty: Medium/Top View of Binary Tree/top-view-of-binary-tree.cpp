//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
// Helper function to recursively find the leftmost and rightmost positions in the binary tree
void find(Node *root, int pos, int& l, int& r)
{
    // Base case: if root is null, return
    if (!root)
        return;

    // Update the leftmost and rightmost positions encountered so far
    l = min(l, pos);
    r = max(r, pos);

    // Recursively traverse left and right subtrees, adjusting position
    find(root->left, pos - 1, l, r);   // Move left: decrement position
    find(root->right, pos + 1, l, r);  // Move right: increment position
}
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    // Function to return the top view of the binary tree
vector<int> topView(Node *root)
{
    // Variables to store the leftmost and rightmost positions
    int l = 0, r = 0;
    
    // Determine the range of horizontal positions using the find function
    find(root, 0, l, r);

    // Vector to store the top view values
    vector<int> ans(r - l + 1);

    // Vector to track whether a position has been filled in the top view vector
    vector<int> filled(r - l + 1, 0);

    // Queue for level order traversal: stores nodes
    queue<Node *> q;
    // Queue for level order traversal: stores horizontal positions corresponding to nodes
    queue<int> index;

    // Initialize the queues with the root node and its adjusted horizontal position
    q.push(root);
    index.push(-l);  // Adjust root's position to start at zero in the vector

    // Perform level order traversal to fill the top view vector
    while (!q.empty())
    {
        // Dequeue the front node and its corresponding position
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        // If this position hasn't been filled yet, fill it with the node's data
        if (!filled[pos])
        {
            filled[pos] = 1;        // Mark position as filled
            ans[pos] = temp->data;  // Store node's data in the top view vector
        }

        // Enqueue the left child with its adjusted position (pos - 1)
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }

        // Enqueue the right child with its adjusted position (pos + 1)
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    // Return the vector containing the top view values of the binary tree
    return ans;
}
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends