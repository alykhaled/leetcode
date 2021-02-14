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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    int n = 1;
    ListNode* here = head;
    ListNode* flippoint = head;
    ListNode* prev = nullptr;
    
    while (here != nullptr)
    {
        if (n == k)
        {
            ListNode* next = here->next;
            for (int i = 0; i < n; i++)
            {
                ListNode* nextNode = head->next;
                head->next = prev;
                prev = head;
                head = nextNode;
            }
            flippoint = next;
            // while (here != nullptr)
            // {
            //     if (n < k)
            //     {
            //         ListNode* next = here->next;
            //         for (int i = 0; i < n; i++)
            //         {
            //             ListNode* nextNode = here->next;
            //             here->next = prev;
            //             prev = here;
            //             here = nextNode;
            //         }   
            //     }
            //     else
            //     {
            //         n++;
            //     }
            // }
            
            
        }
        else
        {

            n++;
        }
        here = here->next;
        
    }
    

}