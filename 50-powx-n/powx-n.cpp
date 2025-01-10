class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        else if(n>0) {
            double res = myPow(x, n/2);
            if(n%2) return x*res*res;
            else return res*res;
        }
        else{
            double res = myPow(x, n/2);
            if(n%2) return 1/(double)x * res*res;
            else return res*res;
        }
    }
};