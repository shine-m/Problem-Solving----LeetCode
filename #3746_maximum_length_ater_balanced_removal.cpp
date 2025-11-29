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
    int minLengthAfterRemovals(string s)
    {
        int a = 0, b = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')

                a++;
            else
                b++;
        }
        return abs(a - b);
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    TwoLineVerticalSpace;
    return 0;
}