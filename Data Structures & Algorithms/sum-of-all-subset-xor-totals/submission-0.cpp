class Solution {
private:
    void solve(int ind, vector<int>& nums, vector<int>& curr, int& ans) {

        if (ind == nums.size()) {
            int Xor = 0;
            for (int i = 0; i < curr.size(); i++) {
                Xor ^= curr[i];
            }
            ans += Xor;
            return;
        }

        curr.push_back(nums[ind]);
        solve(ind + 1, nums, curr, ans);
        curr.pop_back();
        solve(ind + 1, nums, curr, ans);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> curr;
        int ans = 0;
        solve(0, nums, curr, ans);
        return ans;
    }
};