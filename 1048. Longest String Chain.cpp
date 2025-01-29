// Using Recursion + Memoization
// T.C : O(N^2) * 16
// S.C : O(N^2)
class Solution {
public:
    int n;
    int dp[1001][1001];
    bool isPredecessor(string &str1, string &str2){
        int x = str1.length();
        int y = str2.length();

        if(x >= y || y-x != 1) return false;

        int i=0, j=0;
        while(i < x && j < y){
            if(str1[i] == str2[j]){
                i++;
            }
            j++;
        }
        return i == x;
    }
    int solve(int i, int p, vector<string>& words){
        if(i >= n) return 0;

        if(p != -1 && dp[i][p] != -1) return dp[i][p];

        int take = 0;
        if(p == -1 || isPredecessor(words[p], words[i])){
            take = 1 + solve(i+1, i, words);
        }

        int skip = solve(i+1, p, words);

        if(p != -1)
            dp[i][p] = max(take, skip);

        return max(take, skip);
    }

    static bool comp(string &word1, string &word2){
        return word1.length() < word2.length();
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(dp, -1, sizeof(dp));
        sort(words.begin(), words.end(), comp);

        return solve(0, -1, words);
        
    }
};

// Using Tabulation
// T.C : O(N^2) * 16
// S.C : O(N)
class Solution {
public:
    bool isPredecessor(string &str1, string &str2){
        int x = str1.length();
        int y = str2.length();

        if(x >= y || y-x != 1) return false;

        int i=0, j=0;
        while(i < x && j < y){
            if(str1[i] == str2[j]){
                i++;
            }
            j++;
        }
        return i == x;
    }
    
    static bool comp(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);

        int maxStrChain = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isPredecessor(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxStrChain = max(maxStrChain, dp[i]);
                }
            }
        }
        return maxStrChain;
    }
};
