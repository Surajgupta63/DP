// Approach-1 Using Recursion (TLE)
// T.C : O(2^N)
// S.C : O(N)
class Solution {
public:
    void solve(vector<int>& nums, int i, int prev, vector<int> &temp, vector<int> &result){
        if(i >= nums.size()){
            if(temp.size() > result.size()){
                result = temp;
            }
            return;
        }

        if(prev == -1 || nums[i] % prev == 0){
            temp.push_back(nums[i]);
            solve(nums, i+1, nums[i], temp, result);
            temp.pop_back();
        }

        solve(nums, i+1, prev, temp, result);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<int> temp;

        solve(nums, 0, -1, temp, result);

        return result;
    }
};

// Approach-2 Using Tabulation
// T.C : O(N^2) + O(Nlog(N))
// S.C : O(N)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);
        int maxLen = 1;
        int maxIdx = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prevIdx[i] = j;
                    }
                    if(dp[i] > maxLen){
                        maxIdx = i;
                        maxLen = dp[i];
                    }
                }
            }
        }

        vector<int> result;
        while(maxIdx != -1){
            result.push_back(nums[maxIdx]);
            maxIdx = prevIdx[maxIdx];
        }

        return result;

    }
};
