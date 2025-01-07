class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.size(), n2 = goal.size(), j = 0;
        char c;

        if(n1 != n2) return false;
        for(int i = 0;i<n1;i++){
            if(s == goal) return true;
            c = s.front();
            s.erase(s.begin());
            s.push_back(c);
        }
        return false;
    }
};