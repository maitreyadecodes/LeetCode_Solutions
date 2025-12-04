#include <string>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int countCollisions(std::string directions) {
        int n = directions.length();
        int l = 0;
        int r = n - 1;

        // Find the start of the collision zone (first non-'L' car from the left)
        while (l < n && directions[l] == 'L') {
            ++l;
        }

        // Find the end of the collision zone (first non-'R' car from the right)
        while (r >= 0 && directions[r] == 'R') {
            --r;
        }

        // Initialize collisions count to the number of cars in the collision zone
        // Every moving car ('L' or 'R') in this zone will eventually stop
        int collisions = std::max(0, r - l + 1);

        // Subtract the number of stationary cars ('S') in this zone
        // as they don't contribute to the *count of moving cars that stop*
        for (int i = l; i <= r; ++i) {
            if (directions[i] == 'S') {
                collisions--;
            }
        }
        
        return collisions;
    }
};
