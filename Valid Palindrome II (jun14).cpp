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
    bool check(string& s, int l, int r)
{
    while(l < r)
    {
        if(s[l] != s[r])
            return false;

        l++;
        r--;
    }

    return true;
}

bool validPalindrome(string s)
{
    int l = 0;
    int r = s.size()-1;

    while(l < r)
    {
        if(s[l] != s[r])
        {
            return check(s,l+1,r) ||
                   check(s,l,r-1);
        }

        l++;
        r--;
    }

    return true;
}
};

int main() {
    Solution s;
    string str = "abca";
    bool ans = s.validPalindrome(str);
    if(ans)
        cout<<"String is palindrome";
    else        cout<<"String is not palindrome";

    

    return 0;
}