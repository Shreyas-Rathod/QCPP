class Disjoint{
    public :
    vector<int>size, par;
    Disjoint(int n){
        size.resize(n+1);
        par.resize(n+1, 0);
        for(int i = 0;i<n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]); 
    }

    void unionbySize(int x, int z){
        int xpar = find(x);
        int zpar = find(z);

        if(xpar == zpar) return;
        if(size[xpar] > size[zpar]){
            par[zpar] = xpar;
            size[xpar] += size[zpar];
        }
        else{
            par[xpar] = par[zpar];
            size[zpar] += size[xpar];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int E = connections.size();
        if(E < n-1) return -1;
        Disjoint ds(n);
        for(int i = 0;i<E;i++){
            ds.unionbySize(connections[i][0], connections[i][1]);
        }
        set<int>st;
        for(int i = 0;i<n;i++){
            st.insert(ds.find(i));
        }
        return st.size()-1;
    }
};