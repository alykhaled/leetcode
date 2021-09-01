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


vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> list(k);
    int size = 0;
    ListNode* currentNode = head;
    while(currentNode)
    {
        size++;
        currentNode = currentNode->next;
    }
    int reminder = size > k ? size % k : 0;
    for(int part = 0; part < k; part++)
    {
        if(head)
        {
            ListNode* current = head;
            if(head)
            {
                head = head->next;                
            }
            else
            {
                break;
            }            
            list[part] = current; 
            ListNode* currentItemInPart = list[part];
            currentItemInPart->next = nullptr;
            for(int i = 0; i < size/k; i++)
            {
                current = head;
                head = head->next;
                currentItemInPart->next = current;
                currentItemInPart = currentItemInPart->next;
                currentItemInPart->next = nullptr;

            }
            if(reminder)
            {
                current = head;
                head = head->next;
                currentItemInPart->next = current;
                currentItemInPart = currentItemInPart->next;
                currentItemInPart->next = nullptr;

                reminder--;
            }    
        }
    }
    return list;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    // l1->next->next->next = new ListNode(4);
    // l1->next->next->next->next = new ListNode(5);
    // l1->next->next->next->next->next = new ListNode(6);
    // l1->next->next->next->next->next->next = new ListNode(7);
    // l1->next->next->next->next->next->next->next = new ListNode(8);
    // l1->next->next->next->next->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next->next->next->next->next = new ListNode(10);

    vector<ListNode*> list = splitListToParts(l1,5);
    for (auto &&i : list)
    {
        cout << i->val << endl;
    }
    
}