#include <iostream>
#include <vector>
#include <string>

std::vector<int> z_function(const std::string s) {
    int n = (int)s.size();
    std::vector<int> z(n);
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (s[z[i]] == s[z[i] + i]) {
            z[i] += 1;
        }
        if (z[i] + i - 1 > r) {
            r = z[i] + i - 1;
            l = i;
        }
    }
    return z;
}

int main() {
    std::string text, s;
    std::cin >> text >> s;
    std::vector<int> z = z_function(s + "#" + text);
    std::vector<int> poses;
    for (int i = (int)s.size() + 1; i < (int)z.size(); ++i) {
        if (z[i] == (int)s.size()) {
            // your variante to save start pose
            poses.push_back(i - (int)s.size() - 1);
        }
    }
    for (int i = 0; i < (int)poses.size(); ++i) {
        std::cout << poses[i] << ' ';
    }
}
