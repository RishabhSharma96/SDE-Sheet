class Solution {
public:
    double fastPower(double x, long long n) {

        double ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = ans * x;
            }
            x = x * x;
            n = n >> 1;
        }
        return ans;
    }

    double myPow(double x, int n) {

        bool isNegative = false;
        if (n < 0) {
            isNegative = true;
        }

        double ans = fastPower(x, abs(n));

        return !isNegative ? fastPower(x, n) : double(double(1) / double(ans));
    }
};