class Solution {
   private:
    bool dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                if (dfs(it, adjLs, vis, pathVis) == true) return true;
            } else if (pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<vector<int>> adjLs(V);

        for (auto& e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adjLs[u].push_back(v);
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                if (dfs(i, adjLs, vis, pathVis) == true) return false;
        }
        return true;
    }
};
