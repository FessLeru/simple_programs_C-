
class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int) height.size();
        int ans = 0;
        int ind_mx = 0;
        for (int i = 0; i < n; ++i) {
            if (height[ind_mx] < height[i]) {
                ind_mx = i;
            }
        }
        int cur_water = height[0];
        for (int i = 1; i < ind_mx; ++i) {
            if (cur_water <= height[i]) {
                cur_water = max(cur_water, height[i]);
                continue;
            }
            ans += cur_water - height[i];
        }
        cur_water = height[n - 1];
        for (int i = n - 2; i > ind_mx; --i) {
            if (cur_water <= height[i]) {
                cur_water = max(cur_water, height[i]);
                continue;
            }
            ans += cur_water- height[i];
        }
        return ans;
    }
};
