class Solution {
public:
    bool possible(std::vector<int> &arr, int day, int m, int k) {
        int n = arr.size(); //size of the array
        int cnt = 0;
        int noOfB = 0;
        // count the number of bouquets:
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }

    int minDays(std::vector<int>& bloomDay, int m, int k) {
        // m tells the number of bouquets to be made
        // k tells the number of flowers that have to be adjacent in each bouquet
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); //size of the array
        if (val > n) return -1; //impossible case.
        
        // find maximum and minimum:
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = std::min(mini, bloomDay[i]);
            maxi = std::max(maxi, bloomDay[i]);
        }

        // apply binary search:
        int low = mini, high = maxi;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}; 