class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        //we only need to remember dp[i+1],dp[i+2],dp[i+2] to update dp[i]
        vector<int> dp(4, INT_MIN);
        
        for(int i = n-1; i >= 0; i--){
            //initialization
            dp[i%4] = INT_MIN;
            for(int k = 0, take = 0; k <= 2 && i+k < n; k++){
                take += stoneValue[i+k];
                dp[i%4] = max(dp[i%4], take - ((i+k+1<n)?dp[(i+k+1)%4]:0));
            }
            // cout << i << " " << dp[i] << endl;
        }
        
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};