class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n<=1) return n;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            count++;
        }
        int start=0;
        int maxlength = 1;
        for(int length=2;length<=n;length++){
            for(int i=0;i<=n-length;i++){
                int j = i + length -1;
                if(s[i]==s[j]){
                    if(length==2 || dp[i+1][j-1]){
                        dp[i][j]=true;
                        count++;
                    }

                }
            }
        }
        return count;
    }
};
