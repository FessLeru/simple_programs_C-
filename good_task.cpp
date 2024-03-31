#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std; // sorry :)

std::vector<int> prefix_function(const vector<int> &s) {
    int n = (int)s.size();
    std::vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        if (s[i] == -1) {
            p[i] = 0;
            continue;
        }
        int cur = p[i - 1];
        while ((s[i] > cur ? 1e9 : s[i]) != s[cur] && cur > 0) {
            cur = p[cur - 1];
        }
        if ((s[i] > cur ? 1e9 : s[i]) == s[cur]) {
            p[i] = cur + 1;
        }
    }
    return p;
}

int main() {
    string text, word;
    cin >> text >> word;
    int n = (int) text.size(), m = (int) word.size();
    vector<int> a(n, 1e9), b(m, 1e9);
    map<char, int> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.count(text[i]) == 1) {
            a[i] = i - mp[text[i]];
        }
        mp[text[i]] = i;
    }
    mp.clear();
    for (int i = 0; i < m; ++i) {
        if (mp.count(word[i]) == 1) {
            b[i] = i - mp[word[i]];
        }
        mp[word[i]] = i;
    }
    b.push_back(-1);
    for (int i = 0; i < n; ++i) {
        b.push_back(a[i]);
    }
    vector<int> p = prefix_function(b);
    vector<int> ans;
    for (int i = m + m; i < n + m + 1; ++i) {
        if (p[i] == m) {
            ans.push_back(i - m - m + 1);
        }
    }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
