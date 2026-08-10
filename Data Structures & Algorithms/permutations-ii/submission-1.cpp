class Solution {
   private:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans,
               unordered_map<int, int>& mp) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !mp[i-1]) continue;
            if (mp[i]) continue;
            curr.push_back(nums[i]);
            mp[i] = 1;
            solve(nums, curr, ans, mp);
            curr.pop_back();
            mp[i] = 0;
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        solve(nums, curr, ans, mp);
        return ans;
    }
};
