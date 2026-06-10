class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix =1, sufix=1;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n ; i++){
            if(prefix == 0)
                prefix=1;
            if(sufix == 0)
                sufix=1;
            
            prefix *=nums[i];
            sufix *=nums[n-i-1];
            maxi=max(maxi,max(prefix,sufix));
        }
        return maxi;
    }
};
