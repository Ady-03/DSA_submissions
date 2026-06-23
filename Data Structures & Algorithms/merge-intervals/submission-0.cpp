class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        vector<vector<int>> ans;

        for(int i=1; i<intervals.size(); i++){
            int nmini = intervals[i][0];
            int nmaxi = intervals[i][1];

            if(maxi >= nmini)
                maxi=max(maxi,nmaxi);
            else{
                ans.push_back({mini,maxi});
                mini=nmini;
                maxi=nmaxi;
            }
        }
        ans.push_back({mini,maxi});
        return ans;
    }
};
