#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void merge(vector<int>& arr, int low, int mid, int high)
    {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    long long checkInversion(vector<int>& arr,
                             int low,
                             int mid,
                             int high)
    {
        long long cnt = 0;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                left++;
            }
            else
            {
                cnt += (mid - left + 1);
                right++;
            }
        }

        return cnt;
    }

    long long mergeSort(vector<int>& arr,
                        int low,
                        int high)
    {
        if(low >= high)
            return 0;

        long long cnt = 0;

        int mid = low + (high - low) / 2;

        cnt += mergeSort(arr, low, mid);

        cnt += mergeSort(arr, mid + 1, high);

        cnt += checkInversion(arr, low, mid, high);

        merge(arr, low, mid, high);

        return cnt;
    }

    long long numberOfInversions(vector<int> nums)
    {
        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 20, 6, 4, 5};

    cout << "Array: ";

    for(int x : nums)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "Number of Inversions = "
         << s.numberOfInversions(nums)
         << endl;

    return 0;
}