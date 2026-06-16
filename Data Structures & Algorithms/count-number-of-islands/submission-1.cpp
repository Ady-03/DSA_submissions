class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;

        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;

                    while(!q.empty()){
                        pair<int,int> node = q.front();
                        q.pop();
                        int row = node.first;
                        int col = node.second;

                        for(int i=0; i<4; i++){
                            int nrow = row + drow[i];
                            int ncol = col + dcol[i];
                            
                            if(nrow >= 0 && nrow <m && ncol >=0 && ncol <n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                                vis[nrow][ncol] =1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};