#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 目前需要保证字符串长度小于 10，不然有 bug
class KMP_algorithm
{
public:
    void get_next(string s, int next[])
    {
        int n = s[0] - '0';
        int i = 1, j = 0;
        next[1] = 0;
        while (i < n)
        {
            if (j == 0 || s[i] == s[j])
                next[++i] = next[++j];
            else
                j = next[j];
        }
    }
    int kmp(string s1, string s2)
    {
        int m = s1[0] - '0', n = s2[0] - '0';
        int i = 1, j = 1;
        int next[n + 1];
        get_next(s2, next);
        while (i <= m && j <= n)
        {
            if (j == 0 || s1[i] == s2[j])
                i++, j++;
            else
                j = next[j];
        }
        if (j > n)
            return i - n;
        else
            return 0;
    }
};

int main()
{
    KMP_algorithm obj;
    string s1 = "kjasffal", s2 = "asff";
    s1 = to_string(s1.size()) + s1;
    s2 = to_string(s2.size()) + s2;
    cout << obj.kmp(s1, s2) << endl;
    return 0;
}