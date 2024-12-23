class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size(), c1vote = 0, c2vote = 0, candi1 = INT_MIN, candi2 = INT_MIN;
        int c1 = 0, c2 = 0;
        vector<int>res;

        for(int i = 0;i<n;i++){
            if(c1vote == 0 && candi2 != v[i]) candi1 = v[i], c1vote = 1;
            else if(c2vote == 0 && candi1 != v[i]) candi2 = v[i], c2vote = 1;
            else{
                if(candi1 == v[i]) c1vote++;
                else if(candi2 == v[i]) c2vote++;
                else c1vote--, c2vote--;
            }
        }
        for(int i = 0;i<n;i++){
            if(candi1 == v[i]) c1++;
            if(candi2 == v[i]) c2++;
        }

        if((int)(n/3) < c1) res.push_back(candi1);
        if((int)(n/3) < c2) res.push_back(candi2);
        return res;
    }
};