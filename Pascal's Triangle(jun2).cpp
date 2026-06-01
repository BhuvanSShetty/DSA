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
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);

            for(int j = 1; j < i; j++)
            {
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};

int main() {
    Solution s;
    int numRows ;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;
    vector<vector<int>> result = s.generate(numRows); 
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (auto row : result) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}