class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int val: nums)
            mp[val]=1;
        
        int res=0;
        for(auto val: mp){
            if(mp.find(val.first -1) == mp.end()){

                int curr = val.first -1;
                int cnt = 0;

                while(mp.find(curr + 1) != mp.end()){
                    curr++;
                    cnt++;
                }
                res=max(cnt,res);
            }
        }
        return res;
    }
};