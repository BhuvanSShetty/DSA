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
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int layer = 0; layer < (n / 2); layer++)
        {
            int start = layer;
            int end = n - 1 - layer;

            for (int i = start; i < end; i++)
            {
                int gap = i - start;

                int top = matrix[start][i];
                int left = matrix[end - gap][start];
                int bottom = matrix[end][end - gap];
                int right = matrix[i][end];

                matrix[start][i] = left;
                matrix[end - gap][start] = bottom;
                matrix[end][end - gap] = right;
                matrix[i][end] = top;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    s.rotateMatrix(matrix);
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}