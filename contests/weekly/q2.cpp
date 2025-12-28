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
    string reverseWords(string s)
    {

        vector<int> indices;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                indices.push_back(i);
        }

        if (!indices.size())
            return s;
        int primary_cont = 0;
        for (int i = 0; i < indices[0]; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                primary_cont++;
        }
        indices.push_back(s.size());
        for (int i = 0; i < indices.size() - 1; i++)
        {
            int count = 0;
            for (int j = indices[i] + 1; j < indices[i + 1]; j++)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    count++;
            }

            if (count == primary_cont)
            {
                for (int j = indices[i] + 1, k = indices[i + 1] - 1; j < k; j++, k--)
                {
                    swap(s[k], s[j]);
                }
            }
        }

        return s;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    cout << Solution().reverseWords("ten");
    TwoLineVerticalSpace;
    return 0;
}