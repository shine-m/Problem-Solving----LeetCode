#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *tor, *here; // tor stands for iterator
        tor = here = head;

        while (here->next)
        {
            // tor will advance one step per cycle but here will do it 2 steps. so by the time here exhausts the linkedlist, the tor will barely reach the middle position and thus returning tor is returning the middle position of the linked list
            tor = tor->next;
            if (here->next->next)
            {
                here = here->next->next;
            }
            else
                break;
        }
        return tor;
    }
};
int main()
{
    ListNode *root = new ListNode(7);
    root->next = new ListNode(3);
    root->next->next = new ListNode(6);
    root->next->next->next = new ListNode(9);
    root->next->next->next->next = new ListNode(9);
    root->next->next->next->next->next = new ListNode(7);

    ListNode *it = root;
    while (it)
    {
        cout << it->val << " ";
        it = it->next;
    }
    cout << ln;

    Solution ob;
    it = ob.middleNode(root);

    while (it)
    {
        cout << it->val << " ";
        it = it->next;
    }
    cout << ln;

    return 0;
}