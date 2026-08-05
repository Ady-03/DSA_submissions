class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0;
        int maxi = INT_MIN;

        while (r < prices.size()) {
            if (prices[l] > prices[r])
                l++;
            else if (prices[l] == prices[r])
                r++;
            else {
                maxi = max(maxi, prices[r] - prices[l]);
                r++;
            }
        }

        return maxi == INT_MIN ? 0 : maxi;
    }
};
