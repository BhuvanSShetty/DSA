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

/*COUNT + SUBARRAY + SUM
→ Prefix Sum + Frequency Map

COUNT + SUBARRAY + XOR
→ Prefix XOR + Frequency Map

LONGEST + SUM=K + POSITIVES
→ Sliding Window

LONGEST + SUM=K + NEGATIVES
→ Prefix Sum + First Index Map

PRINT ONE SUBARRAY
→ First Index Map

PRINT ALL SUBARRAYS
→ Vector of Indices Map

CONSECUTIVE SEQUENCE
→ HashSet
*/

using namespace std;

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int xr=0;
        int cnt=0;
        for(int i=0 ; i<nums.size(); i++)
        {
            xr^=nums[i];
            int need = xr ^ k;
            
            cnt+=mp[need];

            mp[xr]++;
        }
        return cnt;

        
    }
};

int main() {
    int n = 5;
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    Solution sol;
    int result = sol.subarraysWithXorK(nums, k);
    cout << "Number of subarrays with XOR equal to " << k << ": " << result << endl;        
    return 0;
}