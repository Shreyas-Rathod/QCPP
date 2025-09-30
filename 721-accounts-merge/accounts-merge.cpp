class Disjoint{
    vector<int>rank, parent;
    public :
    Disjoint(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++) parent[i] = i;
    }
    int findp(int x){
        if(x == parent[x]) return x;
        return parent[x] = findp(parent[x]);
    }
    void UnionByRank(int x, int y){
        int xpar = findp(x);
        int ypar = findp(y);
        if(xpar == ypar) return;
        if(rank[xpar] > rank[ypar]) parent[ypar] = xpar;
        else if(rank[xpar] < rank[ypar]) parent[xpar] = ypar;
        else{
            parent[xpar] = ypar;
            rank[ypar]++;
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string, int>mp;

        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(mp.count(accounts[i][j])){
                    ds.UnionByRank(i, mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>>group;

        vector<vector<string>>res;

        for(auto ele : mp){
            group[ds.findp(ele.second)].push_back(ele.first);
        }

        for(auto i : group){
            vector<string>temp;
            temp.push_back(accounts[i.first][0]);
            vector<string>temp1 = i.second;
            sort(temp1.begin(), temp1.end());
            temp.insert(temp.end(), temp1.begin(), temp1.end());
            res.push_back(temp);
        }

        return res;
    }
};