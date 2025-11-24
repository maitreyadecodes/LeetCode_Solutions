#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int prefixMod = 0;
        for (int bit : nums) {
            prefixMod = ((prefixMod << 1) + bit) % 5;
            result.push_back(prefixMod == 0);
        }
        return result;
    }
};
