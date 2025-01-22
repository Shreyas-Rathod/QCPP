class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        for(int x : asteroids){
            if(x<0){
                while(!res.empty() && res.back() > 0 && res.back() < abs(x)) 
                    res.pop_back();
                if(res.empty()) res.push_back(x);
                else if(res.back() + x == 0) res.pop_back();
                else if(res.back() > 0 && res.back() > abs(x)) continue;
                else res.push_back(x);
            }
            else res.push_back(x);
        } 
        return res;
    }
};