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
    string minWindow(string s, string t)
    {

        if (t.size() > s.size())
            return "";

        unordered_map<char, int> freqt;
        for (auto &i : t)
        {
            freqt[i]++;
        }
        deque<int> taken_index;
        unordered_map<char, int> checking;
        int taken = 0;
        for (int i = 0; i < s.length() && taken < t.size(); i++)
        {

            if (freqt[s[i]])
            {
                if (checking[s[i]] < freqt[s[i]])
                {
                    taken++;
                }

                taken_index.push_back(i);
                checking[s[i]]++;
            }
        }

        if (taken != t.size())
            return "";

        int ansl, ansr, anslen;
        ansl = taken_index[0], ansr = taken_index[taken_index.size() - 1];
        anslen = ansr - ansl + 1;
        int right = taken_index[taken_index.size() - 1];

        while (right < s.size())
        {

            while (checking[s[taken_index[0]]] > freqt[s[taken_index[0]]])
            {
                checking[s[taken_index[0]]]--;
                taken_index.pop_front();
            } // until we find the first element that we cant exclude from the substring concidered yet, ye continue this loop

            if (anslen > right - taken_index[0] + 1)
            {
                anslen = right - taken_index[0] + 1;
                ansl = taken_index[0];
                ansr = right;
            }

            right++; // till right we know what character has occur, so advancing with right+1
            while (right < s.size() && s[right] != s[taken_index[0]])
            {
                // we will delete the first element indexed by 0 th index from our sub araay . so we need to find another exact character afterwards. so our search will continue until we reach that element.
                if (freqt[s[right]])
                {
                    checking[s[right]]++;
                    taken_index.push_back(right);
                }
                right++;
            }

            if (right < s.size())
            {
                taken_index.push_back(right); // pushing again the value at the right most index and deleting teh index of occurance of that character in the first of the taken index in the following line
                taken_index.pop_front();
            }
        }

        return s.substr(ansl, ansr - ansl + 1);
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    cout << Solution().minWindow("cabefgecdaecf", "cae");

    TwoLineVerticalSpace;
    return 0;
}