class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        stack<pair<int, int>>st;
        map<int, int>mp;
        int cnt = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    st.push({i, j});
                    int area = 0;
                    cnt++;
                    while(!st.empty()){
                        int r = st.top().first;
                        int c = st.top().second;
                        area++;
                        vis[r][c] = true;
                        grid[r][c] = cnt;
                        st.pop();

                        if(r+1 < n && !vis[r+1][c] && grid[r+1][c]){
                            vis[r+1][c] = true;
                            st.push({r+1, c});
                        } 
                        if(c+1 < n && !vis[r][c+1] && grid[r][c+1]){
                            vis[r][c+1] = true;
                            st.push({r, c+1});
                        }
                        if(r-1 >= 0 && !vis[r-1][c] && grid[r-1][c]){
                            vis[r-1][c] = true;
                            st.push({r-1, c});
                        }
                        if(c-1 >= 0 && !vis[r][c-1] && grid[r][c-1]){
                            vis[r][c-1] = true;
                            st.push({r, c-1});
                        }
                    }
                    mp[cnt] = area;
                }
            }
        }

        if(mp.size() == 0) return 1;
        
        int res = 1;
        bool flag = false;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if(!grid[r][c]){
                    flag = true;
                    int temparea = 1;
                    unordered_set<int> seen;
                    if (r+1 < n && grid[r+1][c] && seen.insert(grid[r+1][c]).second)
                        temparea += mp[ grid[r+1][c] ];
                    if (c+1 < n && grid[r][c+1] && seen.insert(grid[r][c+1]).second)
                        temparea += mp[ grid[r][c+1] ];
                    if (r-1 >= 0 && grid[r-1][c] && seen.insert(grid[r-1][c]).second)
                        temparea += mp[ grid[r-1][c] ];
                    if (c-1 >= 0 && grid[r][c-1] && seen.insert(grid[r][c-1]).second)
                        temparea += mp[ grid[r][c-1] ];
                    res = max(res, temparea);
                }
            }
        }

        if(!flag) return n*n;
        return res;
    }
};