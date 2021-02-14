#include <iostream>
#include <vector>
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
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    ListNode* sum = new ListNode();
    ListNode* here = sum;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr)
    {
        int num1 = (l1 != nullptr) ? l1->val : 0;
        int num2 = (l2 != nullptr) ? l2->val : 0;
        int numsum = 0;
        
        if(num1 + num2 + carry >= 10)
        {
            numsum = num1+num2 -10 + carry;
            carry = 1;
        }
        else
        {
            numsum = num1+num2+carry;
            carry = 0;
        }
        here->val = numsum;
        if (l2 == nullptr)
        {
            if(l1->next != nullptr)
            {
                here->next = new ListNode();          
            }
        }
        else if (l1 == nullptr)
        {
            if(l2->next != nullptr)
            {
                here->next = new ListNode();          
            }
        }
        else
        {
            here->next = new ListNode(); 
        }
        
        if(l1 != nullptr && l2 != nullptr && carry == 1)
        {
            here->next = new ListNode(1); 
        }
        here = here->next;
        l1 = (l1 != nullptr) ? l1->next : l1;
        l2 = (l2 != nullptr) ? l2->next : l2;
    }
    
}