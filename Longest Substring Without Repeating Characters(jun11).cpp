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
        int LongestSubString(string s)
        {
            unordered_set<char> mp;
            int left =0;
            int ans = 0;
            for(int rgt = 0 ; rgt < s.length(); rgt++)
            {
                while (mp.find(s[rgt])!=mp.end())   
                {   
                    mp.erase(s[left]);
                    left++;
                }
                mp.insert(s[rgt]);
                ans=max(ans,rgt-left+1);
                
            }
            return ans;

        }

};

int main() {
    Solution s;
    string u ="abcacm";
    int cnt = s.LongestSubString(u);
    cout<<"Count of largest sub string is"<< cnt;

    return 0;
}