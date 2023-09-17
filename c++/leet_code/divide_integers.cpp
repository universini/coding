#include<iostream>
#include <limits>

using namespace std;

int divide(int dividend, int divisor) {
    // Handle special cases
    if (divisor == 0) return std::numeric_limits<int>::max();
    if (dividend == std::numeric_limits<int>::min() && divisor == -1)
        return std::numeric_limits<int>::max();

    // Convert both dividend and divisor to long to handle the absolute values
    long long ldividend = std::llabs(dividend);
    long long ldivisor = std::llabs(divisor);

    int result = 0;

    while (ldividend >= ldivisor) {
        long long temp = ldivisor;
        long long multiple = 1;

        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        ldividend -= temp;
        result += multiple;
    }

    // Determine the sign of the result based on the input numbers
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        result = -result;

    return result;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        int new_dividend = dividend;

        while((new_dividend - divisor) >= 0) {
            result++;
            new_dividend -= divisor;
        }

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            result = -result;

        return result;
    }
};

int main()
{
    Solution s;

    cout << s.divide(10, 3) << endl;
    cout << divide(10, 3) << endl;

    return 0;
}
