class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = nums.size() - 1;

        while (i <= k) {
            if (nums[i] == val) {
                swap(nums[i], nums[k--]);
            } else {
                i++;
            }
        }
        return k+1;
    }
};