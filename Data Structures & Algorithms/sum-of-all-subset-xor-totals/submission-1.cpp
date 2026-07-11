class Solution {
private:
    void solve(int ind, vector<int>& nums, int Xor, int& ans) {

        if (ind == nums.size()) {
            ans += Xor;
            return;
        }

        solve(ind + 1, nums, Xor ^ nums[ind], ans);
        solve(ind + 1, nums, Xor, ans);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(0, nums, 0, ans);
        return ans;
    }
};