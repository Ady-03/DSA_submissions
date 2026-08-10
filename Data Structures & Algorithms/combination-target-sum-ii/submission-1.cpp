class Solution {
   private:
    void solve(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans,
               int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (idx == nums.size() || target < 0) return;

        if (target < nums[idx]) return;

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            solve(i + 1, nums, curr, ans, target - nums[i]);
            curr.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        solve(0, candidates, curr, ans, target);
        return ans;
    }
};
