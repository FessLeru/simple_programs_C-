#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<uint64_t> p1;
std::vector<int64_t> p2;

void precalc(int max_size, int64_t k, int64_t mod = 1e9 + 7) {
    p1.assign(max_size, 0);
    p2.assign(max_size, 0);
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i < max_size; ++i) {
        p1[i] = p1[i - 1] * k;
        p2[i] = (p2[i - 1] * k) % mod;
    }
}

template<typename Object, typename Element>
struct Hash {
    // h[i] = (sk^0 + sk^1 + sk^2 ... ) % mod
    int64_t mod = 1e9 + 7;
    std::vector<uint64_t> h1;
    std::vector<int64_t> h2;
    int sz; // max_size
    Object obj;

    Hash() = default;

    Hash(Object &object, const Element cast_elem_to_int) {
        obj = object;
        sz = (int)obj.size();
        calc(cast_elem_to_int);
    }

    void calc(const Element cast_elem_to_int) {
        h1.assign(sz + 1, 0);
        h2.assign(sz + 1, 0);
        for (int i = 0; i < sz; ++i) {
            h1[i + 1] = h1[i] + (obj[i] - cast_elem_to_int + 1LL) * p1[i];
            h2[i + 1] = (h2[i] + ((obj[i] - cast_elem_to_int + 1LL) * p2[i] % mod)) % mod;
        }
    }

    // retrun hash on interval [l, r) modulo 1e9 + 7
    int64_t hash_subobject2(int l, int r) const {
        return (((h2[r] - h2[l] + mod) % mod) * p2[sz - l]) % mod;
    }

    // retrun hash on interval [l, r) modulo 2^64
    uint64_t hash_subobject1(int l, int r) const {
        return (h1[r] - h1[l]) * p1[sz - l];
    }

    int size() const {
        return sz;
    }

    Element operator[](int index) const {
        return obj[index];
    }
};

template<typename T, typename U>
bool operator<(const Hash<T, U> &lhs, const Hash<T, U> &rhs) {
    int l = 0, r = std::min((int)lhs.size(), (int)rhs.size()) + 1;
    while (r - l > 1) {
        int mid = (r + l) >> 1;
        int64_t f1 = lhs.hash_subobject2(l, mid), f2 = rhs.hash_subobject2(l, mid);
        uint64_t fx = lhs.hash_subobject1(l, mid), fy = rhs.hash_subobject1(l, mid);
        if (f1 == f2 && fx == fy) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l == std::min((int)lhs.size(), (int)rhs.size())) {
        return (int)lhs.size() < (int)rhs.size();
    }
    return lhs[l] < rhs[l];
}

template<typename T, typename U>
bool operator>(const Hash<T, U> &lhs, const Hash<T, U> &rhs) {
    return rhs < lhs;
}

template<typename T, typename U>
bool operator==(const Hash<T, U> &lhs, const Hash<T, U> &rhs) {
    return (!(lhs < rhs) && !(rhs < lhs));
}

int main() {
    precalc(1e5 + 1, 259);
    std::string s;
    std::cin >> s;
    std::string help = s;
    std::reverse(help.begin(), help.end());
    int n = (int)s.size();
    int64_t ans = 0;
    Hash<std::string, char> hash(s, ' ');
    Hash<std::string, char> h(help, ' ');
    for (int i = 0; i < (int)s.size(); i += 1) {
        int l = 0, r = std::min(i, n - i - 1) + 1;
        while (r - l > 1) {
            int mid = (r + l) >> 1;
            int64_t  f1 = hash.hash_subobject2(i - mid, i), f2 = h.hash_subobject2(n - i - 1 - mid, n - i - 1);
            uint64_t  f3 = hash.hash_subobject1(i - mid, i), f4 = h.hash_subobject1(n - i - 1 - mid, n - i - 1);
            if (f1 == f2 && f3 == f4) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans += l + 1;
    }
    for (int i = 1; i < (int)s.size(); i += 1) {
        int l = 0, r = std::min(i, n - i) + 1;
        while (r - l > 1) {
            int mid = (r + l) >> 1;
            int64_t f1 = hash.hash_subobject2(i - mid, i), f2 = h.hash_subobject2(n - i - mid, n - i);
            uint64_t f3 = hash.hash_subobject1(i - mid, i), f4 = h.hash_subobject1(n - i - mid, n - i);
            if (f1 == f2 && f3 == f4) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans += l;
    }
    std::cout << ans;
}
