class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inout(numCourses, 0);
        vector<int>res;

        int n = prerequisites.size();
        for(int i = 0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inout[prerequisites[i][0]]++;
        }

        queue<int>q;
        for(int i = 0;i<inout.size();i++){
            if(!inout[i]) q.push(i);
        }

        // bfs
        int visited = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            visited++;
            for(auto &it : adj[u]){
                inout[it]--;
                if(inout[it] == 0) q.push(it);
            }
        }
        if(visited == numCourses) return res;
        return {};
    }
};