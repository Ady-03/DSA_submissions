class Solution {
   private:
    bool canSum(vector<int>& nums, int k, int maxSum) {
        int subarray = 1;
        int currSum = 0;

        for(int x : nums){
            if(currSum+x <= maxSum){
                currSum += x;
            }else{
                subarray++;
                currSum = x;
            }
        }
        return subarray <= k;
    }

   public:
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);

        while (s < e) {
            int mid = s + (e - s) / 2;
            if (canSum(nums, k, mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};