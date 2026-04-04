class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
        int m = s.size();
        int n = t.size();
        if(m != n)
            return false;

        for(int i =0; i<m; i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }

        for(int i =0; i<26; i++){
            if(hash[i] != 0)
                return false;
        }
        return true;
    }
};
