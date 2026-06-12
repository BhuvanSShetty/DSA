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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *Mergetwo(ListNode *list1, ListNode *list2)
    {
        ListNode new1(0);
        ListNode *tail = &new1;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }
        if (list1)
            tail->next = list1;

        if (list2)
            tail->next = list2;

        return new1.next;
    }
};

int main()
{
    Solution s;
    ListNode *list1 = new ListNode(1);
    ListNode *list2 = new ListNode(2);
    ListNode *new11 = s.Mergetwo(list1, list2);
    while (new11)
    {
        cout << new11->val << " ";
        new11 = new11->next;
    }

    return 0;
}