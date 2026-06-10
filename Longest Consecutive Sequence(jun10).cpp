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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int lng=0;
        for(auto x : set)
        {
            if(set.find(x-1)==set.end())
            {
                int cur = x;
                int cnt = 1;
                while(set.find(cur+1)!=set.end())
                {
                    cur++;
                    cnt++;
                }
                lng=max(lng,cnt); 
            }
        }
        return lng;
    }
    
};

int main() {

    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int longest = s.longestConsecutive(nums);
    cout << "Longest Consecutive Sequence Length: " << longest << endl; 

    return 0;
}