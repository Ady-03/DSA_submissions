class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string ans;
        while(i<word1.length() && i <word2.length()){
            ans += word1[i];
            ans+= word2[i];
            i++;
        }
        while(i<word1.length())
            ans += word1[i++];
        while(i<word2.length())
            ans += word2[i++];
        return ans;
    }
};