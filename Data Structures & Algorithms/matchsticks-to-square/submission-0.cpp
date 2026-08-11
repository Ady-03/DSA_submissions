class Solution {
   private:
    bool solve(int idx, vector<int>& matchsticks, vector<int>& sides, int target) {
        if (idx == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target &&
                   sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] > target) continue;

            sides[i] += matchsticks[idx];
            if (solve(idx + 1, matchsticks, sides, target)) return true;
            sides[i] -= matchsticks[idx];
        }

        return false;
    }

   public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;

        for (int i : matchsticks) sum += i;

        if (sum % 4 != 0) return false;

        int side = sum / 4;

        for (int x : matchsticks) {
            if (x > side) return false;
        }

        vector<int> sides(4, 0);
        return solve(0, matchsticks, sides, side);
    }
};