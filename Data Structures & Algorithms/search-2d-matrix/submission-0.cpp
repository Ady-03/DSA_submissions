class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> searchSpace;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++)
                searchSpace.push_back(matrix[i][j]);
        }

        int s =0, e=searchSpace.size()-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(searchSpace[mid] == target)
                return true;
            else if(searchSpace[mid] > target)
                e=mid-1;
            else{
                s=mid+1;
            }
        }
        return false; 
    }
};
