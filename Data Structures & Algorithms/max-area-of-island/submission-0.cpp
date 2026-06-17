class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int maxArea = 0;
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i,j});
                    
                    int area = 0;

                    while(!q.empty()){
                        pair<int,int> node = q.front();
                        int row = node.first;
                        int col = node.second;
                        q.pop();
                        
                        area++;
                        maxArea=max(maxArea,area);
                        for(int i=0; i<4; i++){
                            int nrow = row + drow[i];
                            int ncol = col + dcol[i];

                            if(nrow>=0 && nrow<m && ncol >=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                                vis[nrow][ncol] = 1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
        return maxArea;
    }
};
