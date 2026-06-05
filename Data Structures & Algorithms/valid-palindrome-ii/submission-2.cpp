class Solution {
   private:
    bool isPallindrome(int i, int j, string& s){
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
   public:
    bool validPalindrome(string s) {
        int i =0, j=s.length()-1;

        while(i<j){
            if(s[i] != s[j])
                return isPallindrome(i,j-1,s) || isPallindrome(i+1,j,s);
            i++;
            j--;
        }
        return true;
    }
};