#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    Node* head = new Node(7); 
    Node* first = new Node(13); 
    Node* sec = new Node(11); 
    Node* third = new Node(10); 
    Node* fort = new Node(1); 

    head->next = first;
    first->next = sec;
    sec->next = third;
    third->next = fort;
    fort->next = nullptr;

    head->random = nullptr;
    first->random = head;
    sec->random = fort;
    third->random = sec;
    fort->random = head;

    // Node* fift = new Node(1); 
    unordered_map<Node*,Node*> map;
    Node* newhead = new Node(0);
    Node* here = newhead;

    while(head != nullptr)
    {
        here->val = head->val;
        map[head] = here;
        if(head->next != nullptr)
        {
            if(map.find(head->next) == map.end())
            {
                here->next = new Node(head->next->val);
                map[head->next] = here->next;
            }
            else
            {
                here->next = map[head->next];
            }
            if(head->random != nullptr)
            {
                if(map.find(head->random) == map.end())
                {
                    here->random = new Node(head->random->val);
                    map[head->random] = here->random;
                }
                else
                {
                    here->random = map[head->random];
                }
            }
        }
        head = head->next;
        here = here->next;
    }
    for(auto it : map)
    {
        
    }
}