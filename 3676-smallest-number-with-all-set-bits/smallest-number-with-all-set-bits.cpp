class Solution {
public:
    int smallestNumber(int n) {
        int digits = log2(n);
        return pow(2, digits+1) - 1;
    }
};