class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjLs(V);
        vector<int> indegree(V,0);
        queue<int> q;
        vector<int> ans;

        for(auto& e: prerequisites){
            int u = e[0];
            int v = e[1];
            adjLs[u].push_back(v);
        }
        for(int i=0; i<V; i++){
            for(auto next: adjLs[i])
                indegree[next]++;
        }

        for(int i=0; i<V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adjLs[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(ans.size() == V){
            reverse(ans.begin(),ans.end());
            return ans;
        }else{
            return {};
        }
    }
};
