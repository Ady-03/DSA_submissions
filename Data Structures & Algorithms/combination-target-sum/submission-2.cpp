class Solution {
   private:
    void solve(int idx, vector<int>& nums, vector<int> curr, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (idx == nums.size() || target < 0) return;
        if (target < nums[idx]) return;

        curr.push_back(nums[idx]);
        solve(idx, nums, curr, ans, target - nums[idx]);
        curr.pop_back();
        solve(idx + 1, nums, curr, ans, target);
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0, nums, {}, ans, target);
        return ans;
    }
};
