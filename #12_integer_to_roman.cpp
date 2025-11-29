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
    int callForRoman(int num)
    {
        auto it = lower_bound(possible_values.begin(), possible_values.end(), num);
        if (it != possible_values.end())
            if (*it == num)
                return it - possible_values.begin();
            else
                return it - possible_values.begin() - 1;

        else
            return possible_values.end() - possible_values.begin() - 1;
    }
    vector<int> possible_values = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    vector<string> roman_eq = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    string intToRoman(int num)
    {
        string ans;
        while (num > 0)
        {
            int maxx_num = callForRoman(num);
            int times = num / possible_values[maxx_num];
            while (times--)
            {
                ans += roman_eq[maxx_num];
            }
            num %= possible_values[maxx_num];
        }

        return ans;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    Solution ob;
    cout << ob.intToRoman(1994);

    TwoLineVerticalSpace;
    return 0;
}