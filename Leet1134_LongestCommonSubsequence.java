
public class Leet1134_LongestCommonSubsequence {
    private int[][] dp;

    public int longestCommonSubsequence(String text1, String text2) {
        int len1 = text1.length(), len2 = text2.length();
        int res = 0;
        if(len1 < 1 || len2 < 1) return res;

        dp = new int[len1][len2];
        //Initialization
        dp[0][0] = (text1.charAt(0)== text2.charAt(0))? 1:0;
        for (int i = 1; i < len1; i++) {
            if(dp[i-1][0] == 1) {dp[i][0] = 1;}
            else { dp[i][0] = (text1.charAt(i) == text2.charAt(0))? 1:0;}
        }
        for (int j = 1; j < len2; j++) {
            if(dp[0][j-1] == 1) {dp[0][j] = 1;}
            else { dp[0][j] = (text1.charAt(0) == text2.charAt(j))? 1:0;}
        }

        //bottom up
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if(text1.charAt(i)== text2.charAt(j))
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[len1-1][len2-1];

    }
}
