/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

// Stack structure for TreeNode pointers
struct Stack {
    struct TreeNode** data;
    int top;
    int capacity;
};

// Initialize stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Push a node to stack
void push(struct Stack* stack, struct TreeNode* node) {
    stack->data[++stack->top] = node;
}

// Pop a node from stack
struct TreeNode* pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    int capacity = 100; // assume max nodes
    int* result = (int*)malloc(sizeof(int) * capacity);
    struct Stack* stack = createStack(capacity);

    push(stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* node = pop(stack);
        result[(*returnSize)++] = node->val;

        // Push right first so that left is processed first
        if (node->right) push(stack, node->right);
        if (node->left) push(stack, node->left);
    }

    // Free stack memory
    free(stack->data);
    free(stack);

    return result;
}
