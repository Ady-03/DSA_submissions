class Solution {
   private:
    void solve(int idx, vector<int>& nums, int XOR, int& ans) {
        if (idx == nums.size()) {
            ans += XOR;
            return;
        }
        solve(idx + 1, nums, XOR ^ nums[idx], ans);
        solve(idx + 1, nums, XOR, ans);
    }

   public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(0, nums, 0, ans);
        return ans;
    }
};