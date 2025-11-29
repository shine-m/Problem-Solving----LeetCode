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

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> signature;

        ListNode *temp = head;

        while (temp != NULL && signature.find(temp) == signature.end())
        {
            signature.insert(temp);
            temp = temp->next;
        }

        return temp == NULL ? false : true;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    TwoLineVerticalSpace;
    return 0;
}