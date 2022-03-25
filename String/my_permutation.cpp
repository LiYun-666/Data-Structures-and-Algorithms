#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(vector<string> &res, string &s, int pos)
{
    if (pos == s.size() - 1)
    {
        res.push_back(s);
        return;
    }
    unordered_set<char> ch;
    for (int i = pos; i < s.size(); i++)
    {
        if (ch.find(s[i]) != ch.end())
            continue;
        ch.insert(s[i]);
        swap(s[i], s[pos]);
        dfs(res, s, pos + 1);
        swap(s[i], s[pos]);
    }
}

void my_permutation(string s)
{
    vector<string> res;
    dfs(res, s, 0);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

void api_permutation(string s)
{
    sort(s.begin(), s.end());
    do
    {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
    cout << endl;
}

int main()
{
    string s = "abc";
    cout << "algorithm's permutation: ";
    api_permutation(s);
    cout << "my permutation: ";
    my_permutation(s);
}