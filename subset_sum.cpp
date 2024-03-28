class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAXN = 20001;
        int need = accumulate(nums.begin(), nums.end(), 0);
        if (need & 1) {
            return false;
        }
        need /= 2;
        bitset<MAXN> dp;
        dp[0] = 1;
        for (int i = 0; i < (int)nums.size(); ++i){
            dp |= dp << nums[i];
        }
        return dp[need];
    }
};
