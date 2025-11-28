import java.util.*;

class Solution {
    // Global variable to track the maximum number of K-divisible components
    private int maxComponents = 0;

    /**
     * Finds the maximum number of K-divisible components in a tree.
     * * @param n The number of nodes.
     * @param edges The edges of the tree.
     * @param values The values of the nodes.
     * @param k The divisor.
     * @return The maximum number of components.
     */
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        // 1. Build Adjacency List
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        // Reset the component count for each test case
        maxComponents = 0;

        // 4. Initial Call: Start DFS from node 0 (arbitrary root) with parent -1
        dfs(0, -1, values, adj, k);

        // 5. Final Result
        return maxComponents;
    }

    /**
     * Performs DFS to calculate the sum of values (mod k) for the component 
     * in the subtree rooted at u, and greedily cuts edges to form components.
     * * @param u The current node.
     * @param p The parent node of u.
     * @param values The values array.
     * @param adj The adjacency list.
     * @param k The divisor.
     * @return The accumulated sum of the component rooted at u, modulo k.
     */
    private long dfs(int u, int p, int[] values, List<List<Integer>> adj, int k) {
        // 3. Inside dfs: Initialize the current node's value (modulo k)
        // Note: Using 'long' for intermediate sum to prevent potential overflow,
        // even though the final sum is only calculated modulo k.
        long currentSumModK = (long)values[u] % k;

        // Traverse all neighbors (children)
        for (int v : adj.get(u)) {
            if (v != p) {
                // Get the accumulated sum (mod k) from the child's component
                long childSumModK = dfs(v, u, values, adj, k);
                
                // Add the child's contribution to the current sum
                currentSumModK = (currentSumModK + childSumModK) % k;
            }
        }

        // Decision Point (Greedy Cut):
        // If the current accumulated sum (mod k) is 0, we have found a valid component
        if (currentSumModK == 0) {
            // Found a valid component: Increment the counter.
            maxComponents++;
            // Since this component is complete, it contributes 0 to the parent's sum.
            return 0;
        } else {
            // The component is not complete yet: It must remain connected to the parent.
            // Return the accumulated sum (mod k) for the parent to include.
            return currentSumModK;
        }
    }
}