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
    bool isPrime(long long n)
    {
        if (n < 2)
            return false;
        if (n % 2 == 0)
            return n == 2;
        if (n % 3 == 0)
            return n == 3;

        // check only numbers of form 6k ± 1
        for (long long i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    bool completePrime(int num)
    {
        if (num <= 1)
            return 0;
        int len = (log10(num)) + 1;
        int det = 1;
        for (int i = 0; i < len; i++)
        {

            int exp = pow(10, i);

            if (i == 0)
            {

                if (isPrime(num / exp))
                    ;
                else
                {
                    det = 0;
                    break;
                }
            }
            else
            {

                if (isPrime(num / exp) && isPrime(num % exp))
                    ;
                else
                {
                    det = 0;
                    break;
                }
            }
        }

        return det;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    cout << Solution().completePrime(27) << ln;
    TwoLineVerticalSpace;
    return 0;
}