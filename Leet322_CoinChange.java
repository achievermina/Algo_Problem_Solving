import java.util.ArrayList;

public class Leet322_CoinChange {
    public int coinChange(int[] coins, int amount) {
        int row = amount+1, col = coins.length;
        if (row < 1 || amount < 1) return -1;

        int[][] dp = new int[row][col]; // java initialize with Zero

        for (int j = 1; j<row; j++){
            int curMin = Integer.MAX_VALUE;
            for (int i = 0; i< col; i++){
                int curAmount = coins[i];
                if(j >= curAmount && dp[j-curAmount][i] != Integer.MAX_VALUE ){
                    dp[j][i] = Math.min(dp[j-curAmount][i]+1, curMin);
                    curMin = Math.min(curMin, dp[j][i]);
                }else{
                    dp[j][i] = curMin;
                }
            }
        }
        return dp[row-1][col-1] == Integer.MAX_VALUE ? -1 : dp[row-1][col-1] ;
    }
}
