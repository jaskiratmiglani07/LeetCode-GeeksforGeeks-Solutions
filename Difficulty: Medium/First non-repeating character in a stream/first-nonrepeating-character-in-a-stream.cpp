//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
    string FirstNonRepeating(string A) {
        // Code here
        string B;
        vector<int> alphabet(26, 0);
        queue<char> q;
        
        for (int i = 0; i < A.size(); i++) {   
            if (alphabet[A[i] - 'a'] >= 1) { 
                alphabet[A[i] - 'a']++;
                
                while (!q.empty() && (alphabet[q.front() - 'a'] > 1)) {
                    q.pop();
                }
                
                if (q.empty()) {
                    B += '#';
                } else {
                    B += q.front();
                }
            } else {
                alphabet[A[i] - 'a']++;
                q.push(A[i]);
                
                while (!q.empty() && alphabet[q.front() - 'a'] > 1) {
                    q.pop();
                }
                B += q.front();
            }
        }
        
        return B;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends