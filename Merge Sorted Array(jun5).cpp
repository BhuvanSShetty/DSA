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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int midx = m - 1;
        int nidx = n - 1;
        int right = m + n - 1;

        while (nidx >= 0) {
            if (midx >= 0 && nums1[midx] > nums2[nidx]) {
                nums1[right] = nums1[midx];
                midx--;
            } else {
                nums1[right] = nums2[nidx];
                nidx--;
            }
            right--;
        }        
    }
};

int main() {

        Solution s;
    
        vector<int> nums1 = {1,2,3,0,0,0};
        int m = 3;
        vector<int> nums2 = {2,5,6};            

        s.merge(nums1, m, nums2, nums2.size());

        cout << "Merged Array: ";
        for (auto val : nums1) {
            cout << val << " ";
        }
    return 0;
}