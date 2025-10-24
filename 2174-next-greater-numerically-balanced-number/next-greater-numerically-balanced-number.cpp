class Solution {
private:
    bool isbeautiful(vector<int>&count){
        for(int i = 1;i<8;i++){
            if(count[i] != 0 && count[i] != i) return false;
        }
        return true;
    }
    void generate(int num, vector<int>&count, vector<int>&res){
        if(num > 0 && isbeautiful(count)){
            res.push_back(num);
        }

        if(num > 1224444) return;

        for(int d = 1;d<8;d++){
            if(count[d] < d){
                count[d]++;
                generate(num*10 + d, count, res);
                count[d]--;
            }
        }
    }
public:
    int nextBeautifulNumber(int n) {
        vector<int>res;
        vector<int>count(10, 0);
        generate(0, count, res);
        sort(res.begin(), res.end());
        for(int num : res){
            if(num > n) return num;
        }
        return -1;
    }
};
