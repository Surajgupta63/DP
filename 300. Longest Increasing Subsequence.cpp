// Using Recursion + Memoization
// T.C : O(N^2)
// S.C : O(N^2)
class Solution {
public:
    int dp[2501][2501];
    int solve(int currIdx, int prevIdx, vector<int>& nums){
        if(currIdx >= nums.size()) return 0;

        if(prevIdx != -1 && dp[currIdx][prevIdx] != -1) return dp[currIdx][prevIdx];

        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[currIdx]){
            take = 1 + solve(currIdx + 1, currIdx, nums);
        }

        int skip = solve(currIdx+1, prevIdx, nums);

        if(prevIdx != -1)
            dp[currIdx][prevIdx] = max(take, skip);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        return solve(0, -1, nums);
    }
};
