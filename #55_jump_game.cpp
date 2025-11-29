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

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int curpos = 0, max_dist = 0;
        while (curpos <= max_dist && max_dist <= nums.size() - 1)
        {
            max_dist = max(max_dist, curpos + nums[curpos]);
            curpos++;
        }
        if (max_dist >= nums.size() - 1)
            return true;
        else
            return false;
    }
};
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {1, 0, 2};
    cout << Solution().canJump(v);

    TwoLineVerticalSpace;
    return 0;
}