//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function
void tohcall(int n, int source, int helper, int destination)
{   
    if(n==1)//statement1
    {
      cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<destination<<endl;
      return;
    }
    tohcall(n-1, source, destination ,helper);//statement 2
    cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<destination<<endl;//statement 3
    tohcall(n-1, helper, source, destination);//statement 4
}

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        // Your code here
       tohcall(N,from,aux,to);
       return pow(2,N)-1;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends