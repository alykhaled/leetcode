#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    // head->next->next->next = new ListNode(4);
    ListNode* here = head;
    vector<int> ans;
    /*Brute Force*/
    /*while(here != nullptr && here->next != nullptr)
    {
        ListNode* another = here->next;
        while(another != nullptr)
        {
            if(another->val > here->val)
            {
                ans.push_back(another->val);
                break;
            }
            else
            {
                if(another->next == nullptr)
                {
                    ans.push_back(0);
                }
                another = another->next;
            }
        }
        here = here->next;
    }
    ans.push_back(0);*/
    /*=========================================*/

    /*Stack Solution*/
    vector<int> stack;
    while(here != nullptr)
    {
        ans.push_back(here->val);
        here = here->next;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        int current = ans[i];
        while (!stack.empty() && stack.back() <= ans[i])
        {
            stack.pop_back();
        }
        ans[i] = stack.empty() ? 0 : stack.back();
        stack.push_back(current);
    }
    
}