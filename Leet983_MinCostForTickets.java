public class Leet983_MinCostForTickets {

    // DP
    //https://leetcode.com/problems/minimum-cost-for-tickets/discuss/226670/Java-DP-Solution-with-explanation-O(n)
    public int mincostTickets(int[] days, int[] costs) {
        int maxDay = days[days.length -1];
        boolean[] travel = new boolean[maxDay+1];
        int[] dp = new int[maxDay+1];

        for (int day : days) {
            travel[day] = true;
        }

        for (int i = 1; i < dp.length; i++){
            if(!travel[i]){
                dp[i]=dp[i-1];
                continue;
            }

            dp[i] = dp[i-1]+costs[0];
            dp[i] = Math.min(dp[i], dp[Math.max(0, i-7)]+costs[1]);
            dp[i] = Math.min(dp[i], dp[Math.max(0, i-30)]+costs[2]);
        }
        return dp[maxDay];
    }
}
