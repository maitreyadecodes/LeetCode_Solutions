#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0;
        long long total = 0;
        for (int b : batteries) {
            total += b;
        }
        long long right = total;
        
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            long long can_use = 0;
            
            for (int b : batteries) {
                can_use += min((long long)b, mid);
            }
            
            if (can_use >= mid * n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
