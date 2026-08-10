class Solution {
   private:
    void solve(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int k) {
        if (k == 0) {
            ans.push_back(curr);
            return;
        }
        if (idx == nums.size() || k < 0) return;
        curr.push_back(nums[idx]);
        solve(idx + 1, nums, curr, ans, k - 1);
        curr.pop_back();
        solve(idx + 1, nums, curr, ans, k);
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i < n + 1; i++) {
            nums.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, curr, ans, k);
        return ans;
    }
};