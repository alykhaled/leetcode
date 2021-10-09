#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* first = l1;
    ListNode* second = l2;
    ListNode* ans;
    if (l1->val <= l2->val)
    {
        ans = l1;
        first = l1->next;
    }
    else{
        ans = l2;
        second = l2->next;
    }
    
    ListNode* currentAns = ans;
    while(first || second)
    {
        if(!second || (first && first->val <= second->val))
        {
            currentAns->next = first;
            first = first->next;
            currentAns = currentAns->next;
        }
        else if(!first || (second && first->val > second->val ))
        {
            currentAns->next = second;
            second = second->next;
            currentAns = currentAns->next;
        }
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    mergeTwoLists(l1,l2);

}