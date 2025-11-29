#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define CLEAR_SCREEN system("cls");
#endif
#define TwoLineVerticalSpace cout << ln << ln;
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *temp = head;
        while (temp && temp->next)
        {
            int tempval = temp->val;
            temp->val = temp->next->val;
            temp->next->val = tempval;
            temp = temp->next->next;
        }
        return head;
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
    it = ob.swapPairs(root);

    while (it)
    {
        cout << it->val << " ";
        it = it->next;
    }
    cout << ln;

    return 0;
}