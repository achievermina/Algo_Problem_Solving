public class Leet152_MaximumProductSubarray {
    public int maxProduct(int[] nums) {

        int[][] dp = new int[nums.length][2];
        int maxProduct = nums[0];
        dp[0]= new int[] {nums[0],nums[0]};

        for (int i = 1; i < nums.length; i++) {
            int a = dp[i-1][0] * nums[i];
            int b = dp[i-1][1] * nums[i];

            dp[i][0] = Math.max(dp[i-1][0] * nums[i], nums[i]);

            if(nums[i] < 0 ) {
                dp[i][0] = Math.max(dp[i-1][1] * nums[i], dp[i-1][0] * nums[i]);
                dp[i][1] =  Math.min(a, nums[i]);
            }else if(nums[i] > 0 ){
                dp[i][0] = Math.max(dp[i-1][0] * nums[i], nums[i]);
                dp[i][1] =  Math.min(dp[i-1][1], b);
            }else {
                dp[i][0] = Math.max(dp[i-1][0] * nums[i], nums[i]);
                dp[i][1] = 0;
            }

            maxProduct = Math.max(Math.max(a,b), Math.max(nums[i], maxProduct));
        }

        return maxProduct;
    }
}
