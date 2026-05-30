class Solution {
   private:
    void solve(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans,
               set<vector<int>>& st) 
            {
                if(index == nums.size()){
                    if(st.insert(curr).second)
                        ans.push_back(curr);
                    return;
                }

                // include
                curr.push_back(nums[index]);
                solve(index+1, nums, curr, ans, st);
                curr.pop_back();
                solve(index+1, nums, curr, ans, st);
            }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        solve(0, nums, curr, ans, st);
        return ans;
    }
};
