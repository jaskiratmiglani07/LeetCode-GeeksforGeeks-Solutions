class Solution {
public:
    // Recursive function to find the winner
    int winner(vector<bool>& person, int n, int index, int pplLeft, int k) {
        // Base condition: if only one person left, return their index
        if (pplLeft == 1) {
            for (int i = 0; i < n; i++) {
                if (person[i] == 0) // If person is still in the circle
                    return i; // Return their index as the winner
            }
        }
        
        // Calculate the position to eliminate
        int kill = (k - 1) % pplLeft; // Index of the person to be eliminated
        while (kill--) { // Move to the next eligible person to eliminate
            index = (index + 1) % n; // Move index to the next person, wrapping around if needed
            while (person[index] == 1) // If the person is already eliminated, skip them
                index = (index + 1) % n; // Move to the next eligible person
        }
        
        person[index] = 1; // Mark the person at index as eliminated
        
        // Find the next alive person after elimination
        while (person[index] == 1) { 
            index = (index + 1) % n; // Move index to the next person, wrapping around if needed
        }
        
        // Recursive call to find the winner with updated parameters
        return winner(person, n, index, pplLeft - 1, k);
    }
    
    // Function to find the winner given the total number of friends and k value
    int findTheWinner(int n, int k) {
        vector<bool> person(n, 0); // Vector to track whether each person is eliminated or not
        // Call the winner function with initial parameters and return the winner's index
        return winner(person, n, 0, n, k) + 1; // Add 1 to the index since friends are 1-indexed
    }
};
