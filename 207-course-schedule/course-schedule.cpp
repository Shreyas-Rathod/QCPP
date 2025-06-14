class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        int n = prerequisites.size();
        for(int i = 0;i<n;i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            for(int &it : adj[u]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(cnt == numCourses) return true;
        return false;
    }
};