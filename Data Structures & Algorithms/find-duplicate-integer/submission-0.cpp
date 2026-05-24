class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()+1;
        vector<int> hash(n,0);

        for(int i=0; i<nums.size(); i++){
            if(hash[nums[i]] != 0)
                return nums[i];
            hash[nums[i]] = 1;
        }
        return -1;
    }
};
