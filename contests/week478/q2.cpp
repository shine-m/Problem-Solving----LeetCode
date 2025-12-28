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
    int maxDistinct(string s)
    {

        vector<int> v(26, 0);
        for (auto &i : s)
        {
            v[i - 'a']++;
        }

        int ans = 0;
        for (auto &i : v)
        {
            if (i)
                ans++;
        }
        return ans;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    cout << Solution().maxDistinct("anan");

    TwoLineVerticalSpace;
    return 0;
}