class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long hours=0;

            for(auto pile : piles)
                hours += (pile + mid - 1) / mid;

            if (hours <= h) {
                e = mid - 1;
            }
            if (hours > h) s = mid + 1;
        }
        return s;
    }
};