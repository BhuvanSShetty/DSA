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

    long long merge(vector<int>& arr, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        long long cnt = 0;

        while (left <= mid && right <= high) {

            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {

                cnt += (mid - left + 1);

                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& arr, int low, int high) {

        if (low >= high)
            return 0;

        int mid = (low + high) / 2;

        long long cnt = 0;

        cnt += mergeSort(arr, low, mid);

        cnt += mergeSort(arr, mid + 1, high);

        cnt += merge(arr, low, mid, high);

        return cnt;
    }

    long long int numberOfInversions(vector<int> nums) {

        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 20, 6, 4, 5};
    long long inversions = s.numberOfInversions(nums);
    cout << "Number of Inversions: " << inversions << endl;     
    return 0;
}