#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {

            if(ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    vector<vector<int>> ans = s.merge(intervals);

    cout << "Merged Intervals:\n";

    for(auto &v : ans) {
        cout << "[";
        cout << v[0] << "," << v[1];
        cout << "] ";
    }

    return 0;
}