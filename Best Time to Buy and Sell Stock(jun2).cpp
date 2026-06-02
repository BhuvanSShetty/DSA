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
    int maxProfit(vector<int>& prices) {
            int buy=prices[0],profit=0;
            
            for(int i=1;i<prices.size();i++)
            {
                if(buy>prices[i])
                {
                    buy=prices[i];
                }
                profit=max(profit,prices[i]-buy);
            }

            return profit;
    }
};

int main() {
    
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int max = s.maxProfit(prices);
    cout<<max;
    return 0;
}

/*
buy    -> lowest price seen till now
profit -> best profit seen till now

For each day:
1. update cheapest buy price
2. check profit if sold today
*/
