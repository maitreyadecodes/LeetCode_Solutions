#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    // **CHANGE: Renamed function from maxSubarraySumDivisibleByK to maxSubarraySum**
    long long maxSubarraySum(vector<int>& nums, int k) { 
        int n = nums.size();
        if (n == 0) return 0;

        // 1. Compute Prefix Sums (using long long to prevent overflow)
        // P[i] = sum(nums[0]...nums[i-1]). P[0] = 0.
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        // 2. Initialize DP array
        // dp[i] = max sum subarray ENDING at index i-1 (length multiple of k)
        // Initialize with a very small number (negative infinity proxy)
        // -2e18 is safely smaller than the minimum possible sum (-10^9 * 2 * 10^5 = -2 * 10^14)
        vector<long long> dp(n + 1, -2e18); 
        
        long long max_sum = -2e18; 

        // 3. Compute DP values
        // i iterates from k to n (inclusive), corresponding to the end of the subarray in the 1-based indexing of prefix_sum.
        for (int i = k; i <= n; ++i) {
            
            // Calculate S_k = Sum of the last k elements ending at index i-1
            // nums[i-k] ... nums[i-1]
            long long current_k_sum = prefix_sum[i] - prefix_sum[i - k];
            
            // The recurrence is: dp[i] = S_k + max(0, dp[i-k])
            
            // dp[i-k] is the max sum subarray of length multiple of k ending at index i-k-1.
            long long prev_max_sum_ending_at_i_minus_k = dp[i-k];
            
            if (i - k > 0) {
                // Extension case: Extend the previous maximum sum (if it's positive)
                // or start a new subarray (by adding max(0, ...))
                dp[i] = current_k_sum + max(0LL, prev_max_sum_ending_at_i_minus_k);
            } else { // i == k, the very first possible subarray of length k
                dp[i] = current_k_sum;
            }

            // Update the overall maximum sum
            max_sum = max(max_sum, dp[i]);
        }

        return max_sum;
    }
};