class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // initialized
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow]; // walks one step
        fast = nums[nums[fast]]; // walks two step 
        // detect a cycle first
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // once cycle found ...Put slow at start again
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};