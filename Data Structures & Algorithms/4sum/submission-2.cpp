class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, p = n - 1;
                while (k < p) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[p];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[p]});
                        k++;
                        p--;
                        while (k < p && nums[k] == nums[k - 1]) k++;
                        while (k < p && nums[p] == nums[p + 1]) p--;
                    }
                    else if (sum < target)
                        k++;
                    else {
                        p--;
                    }
                }
            }
        }
        return ans;
    }
};