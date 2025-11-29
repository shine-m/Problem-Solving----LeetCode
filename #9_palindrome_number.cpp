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

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return 0;

        int temp = x, newnumber = 0;

        while (temp > 0)
        {

            newnumber = newnumber * 10 + temp % 10;
            temp /= 10;
        }
        return x == newnumber;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    cout << INT_MAX << ln;
    cout << (int)pow(2, 31 - 1) << ln;
    Solution ob;
    cout << ob.isPalindrome(0);

    TwoLineVerticalSpace;
    return 0;
}