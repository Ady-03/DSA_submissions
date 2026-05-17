class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i =0, j=nums.size()-1;
        int count = 0;
        while(i<=j){
            if(nums[i] == val && nums[j] != val){
                swap(nums[i], nums[j]);
                i++;
                j--;
                count++;
            }
            else if(nums[i] == val && nums[j] == val){
                j--;
            }
            else{
                i++;
                count++;
            }
        }
        return count;
    }
};