#include <vector>
#include <cmath>
#include <numeric>

class Solution {
public:
    /**
     * Finds the minimum number of operations (add/subtract 1) to make all elements 
     * in nums divisible by 3.
     * * @param nums The input integer array.
     * @return The minimum total number of operations.
     */
    int minimumOperations(std::vector<int>& nums) {
        int total_operations = 0;
        
        // Iterate through each number in the array
        for (int num : nums) {
            // Find the remainder when the number is divided by 3
            int remainder = num % 3;
            
            // The minimum operations needed for the current number:
            if (remainder == 0) {
                // Case 1: Already divisible by 3 (e.g., 3, 6, 9)
                // Operations needed: 0
                // total_operations += 0; // Explicitly showing, but not needed
            } else if (remainder == 1) {
                // Case 2: Remainder is 1 (e.g., 1, 4, 7)
                // Nearest multiple of 3 is num - 1. Operations needed: 1
                total_operations += 1;
            } else { // remainder == 2
                // Case 3: Remainder is 2 (e.g., 2, 5, 8)
                // Nearest multiple of 3 is num + 1. Operations needed: 1
                total_operations += 1;
            }
        }
        
        return total_operations;
    }
};

/*
Alternative, more concise implementation using a mathematical trick:

int minimumOperations(std::vector<int>& nums) {
    int total_operations = 0;
    for (int num : nums) {
        // The minimum operations is 0 if remainder is 0, and 1 if remainder is 1 or 2.
        // For remainder r, the operation count is min(r, 3 - r).
        int remainder = num % 3;
        total_operations += std::min(remainder, 3 - remainder);
    }
    return total_operations;
}
*/