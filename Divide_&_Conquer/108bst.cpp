// **(The TreeNode struct definition is REMOVED to avoid redefinition error)**

class Solution {
private:
    /**
     * Recursive helper function to build the height-balanced BST.
     * @param nums The sorted array of integers.
     * @param left The starting index of the current subarray segment.
     * @param right The ending index of the current subarray segment.
     * @return The root of the height-balanced BST constructed from nums[left...right].
     */
    TreeNode* convertToBST(const std::vector<int>& nums, int left, int right) {
        // 1. Base Case: If the range is invalid/empty, return null.
        if (left > right) {
            return nullptr;
        }

        // 2. Find the Root: Calculate the middle index. 
        int mid = left + (right - left) / 2;

        // 3. Create Node: The middle element becomes the root.
        // NOTE: We assume 'TreeNode' is defined and has a constructor that takes an integer.
        TreeNode* root = new TreeNode(nums[mid]);

        // 4. Recurse Left: Build the left subtree from the left half.
        root->left = convertToBST(nums, left, mid - 1);

        // 5. Recurse Right: Build the right subtree from the right half.
        root->right = convertToBST(nums, mid + 1, right);

        // 6. Return the constructed root.
        return root;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        
        // Start the recursive process using the full range of the array.
        return convertToBST(nums, 0, nums.size() - 1);
    }
};