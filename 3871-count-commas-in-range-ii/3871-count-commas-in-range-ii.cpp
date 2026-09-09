class Solution {
public:
    long long countCommas(long long n) {
        long long comma = 0;

        for (long long x = 1000; x <= n; x *= 1000) {
            comma += n - x + 1;
        }

        return comma;
    }
};