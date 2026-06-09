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

class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<int> prev(n, 1);

        for (int i = 1; i < m; i++)
        {
            vector<int> curr(n, 1);

            for (int j = 1; j < n; j++)
            {
                curr[j] = curr[j - 1] + prev[j];
            }

            prev = curr;
        }

        return prev[n - 1];
    }

    int solve(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        return solve(i - 1, j) + solve(i, j - 1);
    }

    int memo(int n, int m)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    int m = 3, n = 3;
    int result = s.uniquePaths(m, n);
    cout << "Number of unique paths from top-left to bottom-right in a " << m << "x" << n << " grid: " << result << endl;
    int recursiveResult = s.solve(m - 1, n - 1);
    cout << "Number of unique paths (recursive): " << recursiveResult << endl;
    int memoResult = s.memo(m, n);
    cout << "Number of unique paths (memoization): " << memoResult << endl;

    return 0;
}