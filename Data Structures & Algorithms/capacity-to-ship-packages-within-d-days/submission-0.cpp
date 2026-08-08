class Solution {
   private:
    bool isPossible(vector<int>& weights, int days, int capacity) {
        int usedDays = 1;
        int load = 0;

        for (auto w : weights) {
            if (load + w <= capacity)
                load += w;
            else {
                usedDays++;
                load = w;
            }
        }
        return usedDays <= days;
    }

   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0, sum = 0;

        for (int it : weights) {
            maxi = max(maxi, it);
            sum += it;
        }

        int s = maxi, e = sum;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(weights, days, mid))
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};