class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];

            // Find the key by sorting the string
            sort(s.begin(), s.end());

            // If key is not present in the hash map, add
            // an empty group (vector) in the result and
            // store the index of the group in hash map
            if (mp.find(s) == mp.end()) {
                mp[s] = res.size();
                res.push_back({});
            }

            // Insert the string in its correct group
            res[mp[s]].push_back(strs[i]);
        }
        return res;
    }
};
