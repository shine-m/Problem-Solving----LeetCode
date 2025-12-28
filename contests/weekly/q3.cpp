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
    long long minMoves(vector<int> &balance)
    {

        long long sum = 0;
        int indx = -1;
        for (int i = 0; i < balance.size(); i++)
        {
            sum += balance[i];
            if (balance[i] < 0)
            {
                indx = i;
            }
        }
        if (sum < 0)
            return -1;
        else if (indx == -1)
            return 0;

        if (balance.size() <= 3)
            return -1 * balance[indx];

        long long op = 0;
        int l = (indx - 1 + balance.size()) % balance.size(), r = (indx + 1) % balance.size();
        while (balance[indx] < 0)
        {
            if ((balance[l] + balance[r]) < abs(balance[indx]))
            {
                balance[indx] += (balance[l] + balance[r]);
                op += min(abs(l - indx), abs(indx - r)) * (balance[l] + balance[r]);
            }
            else
            {

                op += min(abs(l - indx), abs(indx - r)) * abs(balance[indx]);
                balance[indx] = 0;
            }
            l = (l - 1 + balance.size()) % balance.size(), r = (r + 1) % balance.size();
        }
        return op;
    }
};
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<int> v = {-6, 2, 16, 13};
    cout << Solution().minMoves(v);
    TwoLineVerticalSpace;
    return 0;
}