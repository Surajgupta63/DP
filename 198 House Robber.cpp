// BruteForce-- TLE ---
class Solution {
public:
    int solve(int i, vector<int>& nums){
        if(i >= nums.size()) return 0;

        int pick    = nums[i] + solve(i+2, nums);
        int notPick = solve(i+1, nums);

        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        return solve(0, nums);
    }
};
