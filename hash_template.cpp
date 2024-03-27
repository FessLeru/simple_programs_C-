// struct for Polynomial hashing modulo 1e9 + 7 and 2^64
// The object must have function size() and operator [] for to access the elements
// The type Element must have operator <
// This is slow variant. In future it will be optimize

#include <iostream>
#include <vector>

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
    precalc(5, 259);
    std::vector<int> a = {1, 2, 3}, b = {1, 2, 3};
    Hash<std::vector<int>, int> hash1(a, 0), hash2(b, 0); 
    std::cout << (hash1 == hash2) << std::endl; // true
}
