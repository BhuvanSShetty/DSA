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
    bool isPalindrome(string s) {
       string str;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i]))
            str+=tolower(s[i]);
        }
        cout<<str;
        int n=str.size()-1;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!=str[n-i])
            {
                return false;
            }
        }
        return true;

    }
};

int main() {
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    bool ans = s.isPalindrome(str);
    if(ans)
        cout<<"String is palindrome";
    else
        cout<<"String is not palindrome";   
    

    return 0;
}