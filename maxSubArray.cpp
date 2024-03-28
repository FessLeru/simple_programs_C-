class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndHere = nums[0];
        int totalMax = nums[0];
        for(int i = 1; i < ((int)nums.size()); ++i){
            maxEndHere = std::max(maxEndHere + nums[i], nums[i]);
            totalMax = std::max(totalMax, maxEndHere);
        }
        return totalMax;
    }
};

// Time O(n)
// memory O(1)
