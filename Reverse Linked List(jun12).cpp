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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *temp1 = nullptr;
        ListNode *temp2 = nullptr;

        while (head)
        {
            temp1 = head->next;
            head->next = temp2;
            temp2 = head;
            head = temp1;
        }
        return temp2;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = s.reverseList(head);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}