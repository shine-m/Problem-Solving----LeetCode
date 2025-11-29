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
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {

        sort(nums.begin(), nums.end());

        int gcd = numsDivide[0];
        for (auto &i : numsDivide)
        {

            gcd = __gcd(gcd, i);
        }

        int res = 0;
        for (auto &i : nums)
        {
            if (i > gcd)
                return -1;
            if (!(gcd % i))
                return res;
            else
                res++;
        }
        return -1;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<int> v1 = {2, 3, 2, 4, 3}, v2 = {3, 6, 9, 12, 15};
    cout << Solution().minOperations(v1, v2);
    TwoLineVerticalSpace;
    return 0;
}