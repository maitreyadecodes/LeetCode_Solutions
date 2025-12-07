class Solution {
    public int countOdds(int low, int high) {
        // Calculate the total number of integers in the range (inclusive)
        int totalNumbers = high - low + 1;

        // Check if either the start or the end of the range is odd
        if (low % 2 != 0 || high % 2 != 0) {
            // If at least one boundary is odd, we effectively round up the half count.
            // Example: [3, 7] has 5 numbers total. (5 + 1) / 2 = 3 odd numbers.
            // Example: [8, 10] has 3 numbers total. (3 / 2) = 1 odd number.
            return (totalNumbers + 1) / 2;
        } else {
            // If both boundaries are even (e.g., [8, 10]), simple integer division works.
            // Example: [8, 10] has 3 numbers total. The odd count is 1. 3 / 2 = 1.
            return totalNumbers / 2;
        }
    }
}
