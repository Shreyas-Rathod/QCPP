class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prer) {
        int n = prer.size(), u;

        vector<vector<int>>mat(numCourses);
        vector<int>res;
        vector<int>vis(numCourses, 0);

        for(int i = 0;i<n;i++){
            mat[prer[i][1]].push_back(prer[i][0]);
            vis[prer[i][0]]++;
        }
        
        queue<int>q;

        for(int i = 0;i<numCourses;i++) if(vis[i]==0) q.push(i);

        int visited = 0;

        while(!q.empty()){
            u = q.front();
            q.pop();
            res.push_back(u);
            visited++;
            for(int &v : mat[u]){
                vis[v]--;
                if(vis[v] == 0) q.push(v);
            }
        }

        if(visited == numCourses) return res;

        return {};
    }
};