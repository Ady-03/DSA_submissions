class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;

        for (int i = 0; i < piles.size(); i++) maxi = max(maxi, piles[i]);

        int s = 1, e = maxi;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long hours = 0;

            for (auto it : piles) {
                hours += (it + mid - 1) / mid;
            }

            if (hours > h) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return s;
    }
};
