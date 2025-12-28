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
    ListNode *deleteDuplicates(ListNode *head)
    {

        unordered_set<int> sign;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            sign.insert(temp->val);
            while (temp->next != nullptr && sign.find(temp->next->val) != sign.end())
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    TwoLineVerticalSpace;
    return 0;
}