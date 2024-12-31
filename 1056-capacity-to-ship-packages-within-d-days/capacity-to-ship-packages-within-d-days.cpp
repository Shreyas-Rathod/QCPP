class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = *max_element(weights.begin(), weights.end()), mid, right = 0, count, sum;
        for(int i : weights) right += i;
        if(days == 1) return right;

        auto fun = [&](int x){
            count = 1;
            sum = 0;
            for(int i : weights){
                if(i+sum > x){
                    count++;
                    sum = i;
                }
                else sum += i;
            }
            return count<=days;
        };

        while(left<=right){
            mid = (left+right)/2;
            if(fun(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};