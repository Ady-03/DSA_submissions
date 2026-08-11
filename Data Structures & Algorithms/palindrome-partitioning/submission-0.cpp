class Solution {
   private:
    bool isPal(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int idx, string& s, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPal(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};
