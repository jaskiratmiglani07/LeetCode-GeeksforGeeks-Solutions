#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if (n == 0) return result; // Handle empty matrix
        int m = matrix[0].size();
        int row_start = 0;
        int row_end = n - 1;
        int column_start = 0;
        int column_end = m - 1;
        while (row_start <= row_end && column_start <= column_end) {
            // Traverse right
            for (int j = column_start; j <= column_end; j++) {
                result.push_back(matrix[row_start][j]);
            }
            row_start++;
            // Traverse down
            for (int i = row_start; i <= row_end; i++) {
                result.push_back(matrix[i][column_end]);
            }
            column_end--;
            // Traverse left
            if (row_start <= row_end) { // Ensure there are rows remaining
                for (int j = column_end; j >= column_start; j--) {
                    result.push_back(matrix[row_end][j]);
                }
                row_end--;
            }
            // Traverse up
            if (column_start <= column_end) { // Ensure there are columns remaining
                for (int i = row_end; i >= row_start; i--) {
                    result.push_back(matrix[i][column_start]);
                }
                column_start++;
            }
        }
        return result;
    }
};
