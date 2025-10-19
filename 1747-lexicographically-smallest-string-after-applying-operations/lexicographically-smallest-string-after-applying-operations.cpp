class Solution {
public:
    string findLexSmallestString(string s, int a, int b){ 
        unordered_set<string>vis;
        string res = s;
        queue<string>q;
        q.push(s);
        vis.insert(s);

        while(!q.empty()){
            string cur = q.front(); q.pop();
            if(cur < res) res = cur;

            string temp = cur;
            for(int i = 1;i<cur.size();i+=2){
                temp[i] = ((temp[i] - '0') + a)%10 + '0';
            }

            if(!vis.count(temp)){
                q.push(temp);
                vis.insert(temp);
            }

            temp = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);

            if(!vis.count(temp)){
                q.push(temp);
                vis.insert(temp);
            }
        }

        return res;
    }
};