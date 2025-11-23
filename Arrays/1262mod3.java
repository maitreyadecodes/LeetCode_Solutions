import java.util.Arrays;

class Solution {
    /**
     * Finds the maximum possible sum of elements of the array such that it is divisible by three.
     * Uses Dynamic Programming.
     * * dp[i] represents the maximum sum found so far that has a remainder of i when divided by 3.
     */
    public int maxSumDivThree(int[] nums) {
        // dp[0]: max sum with remainder 0
        // dp[1]: max sum with remainder 1
        // dp[2]: max sum with remainder 2
        
        // Initialize dp array. 
        // dp[0] is 0 (the sum of an empty set is 0, and 0 % 3 = 0).
        // dp[1] and dp[2] are initialized to a very small negative number 
        // to ensure any valid sum found later will replace this initial value.
        int[] dp = {-10000, -10000, -10000}; 
        dp[0] = 0;
        
        for (int num : nums) {
            // Create a temporary array to store the next state of DP sums.
            // Initialize it with the current dp values (representing not taking the current num).
            int[] nextDp = Arrays.copyOf(dp, 3);
            
            // Iterate through the current remainders
            for (int currentRemainder = 0; currentRemainder < 3; currentRemainder++) {
                // If the current max sum for this remainder is valid (i.e., not -10000)
                if (dp[currentRemainder] >= 0) {
                    // Calculate the new sum by including 'num'
                    int newSum = dp[currentRemainder] + num;
                    
                    // Calculate the new remainder
                    int newRemainder = newSum % 3;
                    
                    // Update the maximum sum for the 'newRemainder'
                    // We take the max of:
                    // 1. The existing max sum for 'newRemainder' (from nextDp[newRemainder])
                    // 2. The new sum we just calculated (newSum)
                    nextDp[newRemainder] = Math.max(nextDp[newRemainder], newSum);
                }
            }
            // Update the main dp array with the calculated next state
            dp = nextDp;
        }
        
        // The maximum sum divisible by 3 is the value stored in dp[0].
        // Since we initialized invalid sums to a large negative number, and we only update 
        // valid sums (dp[currentRemainder] >= 0), dp[0] will contain the largest non-negative sum.
        return dp[0];
    }
}