class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int num : nums) total += num;
        int remainder = total % p;
        if (remainder == 0) return 0;  // already divisible

        unordered_map<int, int> seen;
        seen[0] = -1;  // prefix_mod -> index
        long long prefix = 0;
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - remainder + p) % p;
            if (seen.count(target)) {
                res = min(res, i - seen[target]);
            }
            seen[prefix] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};
