class Solution {
private:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<int>& used){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i])
                continue;
            curr.push_back(nums[i]);
            used[i] = 1;
            solve(nums,curr,ans,used);
            curr.pop_back();
            used[i]=0;
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> used(nums.size(),0);
        solve(nums, curr, ans, used);
        return ans;
    }
};