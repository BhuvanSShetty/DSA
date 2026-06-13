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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummyNode = new ListNode();

        ListNode* curr = dummyNode;

        int carry = 0;

        while(l1 || l2 || carry)
        {
            int num1 = (l1 != nullptr) ? l1->val : 0;
            int num2 = (l2 != nullptr) ? l2->val : 0;

            int sum = num1 + num2 + carry;

            carry = sum / 10;

            int digit = sum % 10;

            curr->next = new ListNode(digit);

            curr = curr->next;

            if(l1)
                l1 = l1->next;

            if(l2)
                l2 = l2->next;
        }

        return dummyNode->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next= new ListNode(1);
    l2->next->next = new ListNode(9);
    ListNode* result = s.addTwoNumbers(l1, l2);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    };

    return 0;
}