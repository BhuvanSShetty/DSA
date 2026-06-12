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
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    int countLinkedList(ListNode* head)
    {
        int cnt = 0;
        while(head)
        {
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    bool isEven(int number) {
    return number % 2 == 0;
}
    ListNode* middleNode(ListNode* head) {
        int cnt = countLinkedList(head);
        cnt=cnt/2;
        if(cnt==0)
            return head;
        ListNode *temp = nullptr;
        while(cnt--)
        {
            temp = head->next;
            head=head->next;
        }
        return temp;
    }

    
    ListNode* middleNode1(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    int cur = s.middleNode(head)->val;
    cout<<"Middle node value is "<<cur;
    

    return 0;
}