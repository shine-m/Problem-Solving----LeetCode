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
    int divide(int dividend, int divisor)
    {

        bool signNegative = (dividend < 0) ^ (divisor < 0);

        long long dvdnd = llabs((long long)dividend), dvsr = llabs((long long)divisor);

        long long result = 0;

        while (dvdnd >= dvsr)
        {

            long long times = 1, tempdvsr = dvsr;
            while ((tempdvsr << 1) < dvdnd)
            {

                tempdvsr = tempdvsr << 1;
                times = times << 1;
            }

            result += times;
            dvdnd -= tempdvsr;
        }
        cout << result << ln;
        return signNegative ? -(result >= llabs((long long)INT_MIN) ? INT_MIN : result) : (result >= llabs((long long)INT_MIN) ? INT_MAX : result);
    }
};
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    cout << Solution().divide(INT_MIN, 1);

    TwoLineVerticalSpace;
    return 0;
}