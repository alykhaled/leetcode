#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = 0;
    ListNode* current = head;
    while(current)
    {
        length++;
        current = current->next;
    }
    current = head;
    for(int i = 1; i <= length; i++)
    {
        if(length - n == i)
        {
            current = current->next->next;
            return head;
        }
        else{
            current = current->next;    
        }
    }
    return head;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* result = removeNthFromEnd(head, 2);
    while(result)
    {
        cout << result->val << " ";
        result = result->next;
    }

}