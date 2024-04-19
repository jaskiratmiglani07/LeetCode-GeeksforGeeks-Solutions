//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int linearSearch(int arr[], int X, int index, int N)
    {
        if(index==N)
        return -1;
        if(arr[index]==X)
        return index;
        return linearSearch(arr,X,index+1,N);
        
        // Your code here
        
    }
    int search(int arr[],int N, int X)
    {
        return linearSearch(arr,X,0,N);
    }

};

//{ Driver Code Starts.

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        Solution ob;
        cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}

// } Driver Code Ends