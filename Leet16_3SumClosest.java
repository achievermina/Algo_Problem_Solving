import java.util.Arrays;

public class Leet16_3SumClosest {

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closest = nums[0], diff = Integer.MAX_VALUE;

        for ( int i = 0; i < nums.length-2; i++) {
            int low = i+1, high = nums.length-1;
            while(low<high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum==target){
                    return target;
                }

                if(sum>target) high--;
                else low++;

                if(diff > Math.abs(sum-target)){
                    diff = Math.abs(sum-target);
                    closest = sum;
                }
            }
        }
        return closest;
    }
}
