class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        int l = 0, r = 0;
        int maxi = INT_MIN;
        while (r < n) {
            if (prices[l] > prices[r]) {
                l++;
            } else if (prices[l] == prices[r])
                r++;
            else {
                maxi = max(prices[r] - prices[l], maxi);
                r++;
            }
        }
        if (maxi == INT_MIN)
            return 0;
        else {
            return maxi;
        }
    }
};
