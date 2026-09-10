class Solution {
public:
    int ans = 0;
    pair<int,int> helper(TreeNode*root) {
        if (root==nullptr) return {0, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;
        int average = sum / count;

        if (average == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};