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

ListNode* addToList(ListNode* head, ListNode* item)
{
    if(!head)
    {
        return item;
    }
    while(head)
    {
        if(item->val >= head->val && (!head->next || item->val <= head->next->val))
        {
            item->next = head->next;
            head->next = item;
            break;
        }
        else{
            head = head->next;
        }
    }
    return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1 && l2)
    {
        return l2;
    }
    if(l1 && !l2)
    {
        return l1;
    }
    if(!l1 && !l2)
    {
        return nullptr;
    }
    ListNode* first = l2;
    ListNode* second = l2->next;
    ListNode* ans = l1;
    while(first)
    {
        ans = addToList(l1,first);
        first = second;
        second = second ? second->next : nullptr;
    }
    return ans;
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    ListNode* l1 = new ListNode(1);
    // l1->next = new ListNode(2);
    // l1->next->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(2);
    // l2->next = new ListNode(3);
    // l2->next->next = new ListNode(4);
    mergeTwoLists(l1,l2);
}