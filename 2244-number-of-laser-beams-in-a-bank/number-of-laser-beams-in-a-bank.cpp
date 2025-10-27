class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0, curr = 0, cnt = 0;

        for(char c : bank[0]) if(c == '1') prev++;

        for(int i = 1;i<n;i++){
            curr = 0;
            for(char c : bank[i]) if(c == '1') curr++;
            if(curr){
                cnt += (prev * curr);
                prev = curr;
            } 
        }

        return cnt;
    }
};