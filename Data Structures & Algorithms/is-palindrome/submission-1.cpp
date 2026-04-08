class Solution {
public:
    bool isPalindrome(string s) {
        int i =0, j=s.length()-1;
        
        while(i<j){

            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }

            if(s[i] >= 'A' && s[i] <= 'Z' && s[j] >= 'a' && s[j] <= 'z'){
                if(s[i] + 32 != s[j])
                    return false;
            }
            else if(s[i] >= 'a' && s[i] <= 'z' && s[j] >= 'A' && s[j] <= 'Z'){
                if(s[i] != s[j] + 32)
                    return false;
            }
            else{
                if(s[i] != s[j])
                    return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
