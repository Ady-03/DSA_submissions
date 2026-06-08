class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int n_0 = 0, n_1 = 0, n_2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                n_0++;
            else if (nums[i] == 1)
                n_1++;
            else {
                n_2++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (n_0 != 0) {
                nums[i] = 0;
                n_0--;
            } else if (n_1 != 0) {
                nums[i] = 1;
                n_1--;
            } else {
                nums[i] = 2;
                n_2--;
            }
        }
    }
};