class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int s = 0, e = row * col - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int rows = mid / col;
            int cols = mid % col;

            if (matrix[rows][cols] == target)
                return true;
            else if (matrix[rows][cols] > target)
                e = mid - 1;
            else {
                s = mid + 1;
            }
        }
        return false;
    }
};
