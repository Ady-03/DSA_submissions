class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0, j=people.size()-1;
        int count = 0;
        sort(people.begin(),people.end()); 

        while(i<=j){
            int sum = people[i] + people[j];

            if(sum <= limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            count++;
        }
        return count;
    }
};