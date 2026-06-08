class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0, r=0;
        int hash[256]={0};
        int maxlen = 0;
        while(r<s.length()){
            if(hash[s[r]] == 0){
                hash[s[r]] = 1;
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else{
                while(hash[s[r]] != 0){
                    hash[s[l]] = 0;
                    l++;
                    maxlen=max(maxlen,r-l+1);
                }
            }
        }
        return maxlen;
    }
};
