// Recursion + Memoization (Top Down)
class Solution {
public:
    long long dp[100001][2];

    long long solve(int i, bool sign, vector<int>& nums){
        if(i >= nums.size()) return 0;

        if(dp[i][sign] != -1) return dp[i][sign];

        long long notPick  = solve(i+1, sign, nums);

        long long val = (sign == false) ? -nums[i] : nums[i];

        long long pick = val + solve(i+1, !sign, nums);
        
        return dp[i][sign] = max(pick, notPick);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, true, nums);
    }
};
