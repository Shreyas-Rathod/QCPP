class Disjoint{
    vector<int>rank, parent;
    public : 
    Disjoint(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++) parent[i] = i;
    }

    void UnionByRank(int x, int y){
        int xpar = findparent(x);
        int ypar = findparent(y);
        if(xpar == ypar) return;

        if(rank[xpar] < rank[ypar]) parent[xpar] = ypar;
        else if(rank[xpar] > rank[ypar]) parent[ypar] = xpar;
        else{
            parent[ypar] = xpar;
            rank[xpar]++;
        }
    }

    int findparent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findparent(parent[x]);
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size(), cnt = n;
        Disjoint ds(n);
        if(m < n-1) return -1;
        for(int i = 0;i<m;i++){
            if(ds.findparent(connections[i][0]) != ds.findparent(connections[i][1])){
                cnt--;
                ds.UnionByRank(connections[i][0], connections[i][1]);
            }
        }

        return --cnt;
    }
};