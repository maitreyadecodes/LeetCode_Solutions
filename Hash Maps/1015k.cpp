class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // 1. Initial Check: If k is divisible by 2 or 5, no repunit (which ends in 1) 
        // can be divisible by k.
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        // 'remainder' represents the value of (11...1) mod k.
        // We start with the value 0, which corresponds to the virtual number '0', 
        // and the length 0. The first iteration calculates 1 mod k.
        int remainder = 0;
        
        // The length L can be at most k (guaranteed by the Pigeonhole Principle 
        // when gcd(k, 10) = 1). We iterate from L=1 up to L=k.
        for (int length = 1; length <= k; ++length) {
            // Calculate the new remainder: 
            // remainder_new = (remainder_old * 10 + 1) % k
            // We cast remainder to long long before multiplying by 10 to 
            // prevent intermediate overflow if k is close to INT_MAX (though k <= 10^5 
            // makes int sufficient for this step, it's good practice).
            // For k <= 10^5, `(remainder * 10 + 1)` is at most `(99999 * 10 + 1) = 1000001`, 
            // which fits safely in a standard 32-bit `int`.
            remainder = (remainder * 10 + 1) % k;

            // 3. Check for Solution: If remainder is 0, we found the smallest n.
            if (remainder == 0) {
                return length;
            }
        }

        // As proven by the Pigeonhole Principle, if a solution exists (which it does 
        // if k is not divisible by 2 or 5), it must be found within 'k' steps.
        // This line is technically unreachable given the initial check and loop bound,
        // but included for completeness in some problem contexts.
        return -1; 
    }
};