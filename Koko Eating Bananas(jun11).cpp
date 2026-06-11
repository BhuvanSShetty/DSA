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
    bool caneat(vector<int>& piles, int h,int mid)
    {
        long long cnt =0;
        for(int i=0; i<piles.size();i++)
        {
            cnt += (piles[i]+mid-1)/mid;
        }

        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1;
        int rgt = *max_element(piles.begin(),piles.end());
        int ans = rgt;
        while(rgt>=left)
        {
            int mid = left+(rgt-left)/2;
            if(caneat(piles,h,mid))
            {
                ans=mid;
                rgt=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    int cnt = s.minEatingSpeed(piles,h);
    cout<<"Count of largest sub string is"<< cnt;
    return 0;
}