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
{   private:
        void merge(vector<int>& nums,int low,int mid, int high)
        {
            int cnt =0;
            vector<int> temp;
            int left=low;
            int right=mid+1;
            while(left<=mid && right<=high)
            {
                if(nums[left]<=nums[right])
                {
                    temp.push_back(nums[left]);
                    left++;
                }
                else
                {
                    temp.push_back(nums[right]);
                    right++;
                }
            }
            while (left<=mid)
            {
                temp.push_back(nums[left]);
                left++;
            }
            while (right<=high)
            {
                temp.push_back(nums[right]);
                right++;
            }

            for(int i=low;i<=high;i++)
            {
                nums[i]=temp[i-low];
            }
        }
        int rev(vector<int>& nums,int low,int mid, int high)
        {
            int cnt=0;
            int rgt=mid+1;
            for(int i=low;i<=mid;i++)
            {
                while (rgt<=high and nums[i]> 2LL*nums[rgt])
                {
                    rgt++;
                }
                cnt+=(rgt-(mid+1));
            }
            return cnt;
        }
        int mergesort(vector<int>& nums, int low , int high)
        {
            if(low>=high)
                return 0;
            int cnt=0;
            int mid = low + (high-low)/2;
            cnt+=mergesort(nums,low,mid);
            cnt+=mergesort(nums,mid+1,high);
            cnt+=rev(nums,low,mid,high);
            merge(nums,low,mid,high);
            return cnt;
        }
    public:
        int reversepairs(vector<int>& nums)
        {
            return mergesort(nums,0,nums.size()-1);
        }
};

int main() {
    Solution s;
    vector<int> arr ={1,3,2,3,1};
    int sol = s.reversepairs(arr);
    cout<<"Reverse Pair Count:"<<sol;
    return 0;
}