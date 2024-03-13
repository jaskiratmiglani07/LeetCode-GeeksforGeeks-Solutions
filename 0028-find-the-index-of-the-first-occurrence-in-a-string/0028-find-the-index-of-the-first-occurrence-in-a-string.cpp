class Solution {
public:
    int strStr(string haystack, string needle) {
        // Get the lengths of the haystack and needle strings
        int n = haystack.size(), m = needle.size();
        
        // Loop through the haystack string
        for (int i = 0; i <= n - m; i++) {
            // Initialize variables to track positions in haystack and needle
            int first = i, second = 0;
            
            // Check if substring starting from index 'i' in haystack matches needle
            while (second < m) {
                // If characters don't match, break out of the loop
                if (haystack[first] != needle[second])
                    break;
                else
                    // Move to the next character in both haystack and needle
                    first++, second++;
            }
            
            // If we've matched the entire needle, return the starting index
            if (second == m)
                return i;
        }
        
        // If needle is not found in haystack, return -1
        return -1;
    }
};

