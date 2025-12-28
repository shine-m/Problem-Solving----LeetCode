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
using ll = long long;

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *temp = head;

        ListNode *reversed = head, *currtail;
        if (head == nullptr || k <= 1)
            return head;

        bool should_continue = 1, isfirst = 1;

        while (should_continue && temp != nullptr)
        {

            int reducingK = k;
            ListNode *iterationHead = temp;

            ListNode *currNode;
            if (temp != nullptr)
            {
                currNode = new ListNode(temp->val);
                temp = temp->next;
            }
            ListNode *temptail = currNode;

            while (--reducingK && temp != nullptr)
            {

                ListNode *node = new ListNode(temp->val, currNode);

                currNode = node;
                temp = temp->next;
            }

            if (reducingK)
            {
                if (isfirst)
                    return head;
                currtail->next = iterationHead;

                should_continue = 0;
            }
            else
            {

                if (isfirst)
                {
                    reversed = currNode;
                    isfirst = 0;
                }
                else
                {
                    currtail->next = currNode;
                }
                currtail = temptail;
            }
        }
        return reversed;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    ListNode *reversed = Solution().reverseKGroup(root, 3);

    cout << "before : - > ";
    ListNode *temp = root;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << "\nafter reversing => ";
    while (reversed != nullptr)
    {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }

    TwoLineVerticalSpace;
    return 0;
}