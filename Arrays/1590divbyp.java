import java.util.*;

class Solution {
    public int minSubarray(int[] nums, int p) {
        long total = 0;
        for (int num : nums) total += num;
        int remainder = (int)(total % p);
        if (remainder == 0) return 0;  // already divisible

        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, -1);  // prefix_mod -> index
        long prefix = 0;
        int res = nums.length;

        for (int i = 0; i < nums.length; i++) {
            prefix = (prefix + nums[i]) % p;
            int target = (int)((prefix - remainder + p) % p);
            if (seen.containsKey(target)) {
                res = Math.min(res, i - seen.get(target));
            }
            seen.put((int)prefix, i);
        }

        return res == nums.length ? -1 : res;
    }
}