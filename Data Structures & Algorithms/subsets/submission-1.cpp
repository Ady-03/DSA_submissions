class Solution {
   private:
    void solve(int idx, vector<int>& nums, vector<int> curr, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }
        // take
        curr.push_back(nums[idx]);
        solve(idx + 1, nums, curr, ans);
        curr.pop_back();
        solve(idx + 1, nums, curr, ans);
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, {}, ans);
        return ans;
    }
};
