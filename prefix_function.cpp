#include <iostream>
#include <vector>

std::vector<int> prefix_function(const std::string s) {
    int n = (int)s.size();
    std::vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0) {
            cur = p[cur - 1];
        }
        if (s[i] == s[cur]) {
            p[i] = cur + 1;
        }
    }
    return p;
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> res = prefix_function(s);
    for (int i = 0; i < (int)res.size(); ++i) {
        std::cout << res[i] << ' ';
    }
    return 0;
}
