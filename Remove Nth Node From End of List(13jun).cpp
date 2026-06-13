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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
}; 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr = head, *temp = head;
        for (int i = 0; i < n; i++) ptr = ptr->next;
        
        if (!ptr) return head->next;
        
        while (ptr->next) {
            ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);       
    head->next->next = new ListNode(3);
    ListNode* temp = s.removeNthFromEnd(head, 2);
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    };
    
    

    return 0;
}