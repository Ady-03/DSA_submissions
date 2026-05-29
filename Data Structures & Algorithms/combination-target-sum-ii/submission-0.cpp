class Solution {
private:
    void solve(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i]==nums[i-1])
                continue;
            if(nums[i] > target)
                break;
            curr.push_back(nums[i]);
            solve(i+1, nums, curr, ans, target-nums[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, candidates, curr, ans, target);
        return ans;
    }
};
