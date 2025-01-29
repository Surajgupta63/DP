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

// Using Tabulation
// T.C : O(N^2)
// S.C : O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i]  = max(dp[i], dp[j] + 1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};
