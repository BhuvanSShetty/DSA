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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;

        for( i=0 ; i < n ; i++)
        {
            if(target <= matrix[i][m-1])
            {
                break;
            }
        }

        if(i == n) return false;

        for( int j=0 ; j < m ; j++)
        {
            if(target == matrix[i][j])
                return true;
        }

        return false;
    }
};

int main() {
    Solution s; 
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    int target = 3;
    bool found = s.searchMatrix(matrix, target);
    cout << "Target " << target << (found ? " found" : " not found") << " in the matrix." << endl;

    return 0;
}