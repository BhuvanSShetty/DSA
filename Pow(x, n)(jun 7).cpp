#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <numeric>
#include <deque>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;

        while (N > 0) {

            if (N % 2 == 1) {
                result *= x;
            }

            x *= x;
            N /= 2;
        }

        return result;
    }
};

int main() {
    Solution s;
    double x = 2.0;
    int n = 10;
    double result = s.myPow(x, n);
    cout << x << " raised to the power of " << n << " is: " << result << endl;
    return 0;
}