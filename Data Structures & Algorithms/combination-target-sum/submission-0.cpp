class Solution {
private:
    void solve(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int sum, int& target){
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(index == nums.size() || sum > target)
            return;
        
        // Include
        sum += nums[index];
        curr.push_back(nums[index]);
        solve(index, nums, curr, ans, sum, target);

        // solve(index+1, nums, curr, ans, sum , target);

        sum -= nums[index];
        curr.pop_back();
        solve(index+1, nums, curr, ans, sum, target);   
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, curr, ans, 0, target);
        return ans;
    }
};
