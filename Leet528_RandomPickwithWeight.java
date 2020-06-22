import java.util.Arrays;

public class Leet528_RandomPickwithWeight {
    private double[] weight;

    public Solution(int[] w) {
        int len = w.length;
        int sum = Arrays.stream(w).sum();
        System.out.println(sum);

        weight = new double[len];

        double curSum = 0.0;
        for(int i =0; i < len; i++) {



            curSum += Double.valueOf(w[i]/sum);
            System.out.printf("%.2f, %d, %.2f", w[i]/sum, w[i], curSum);

            weight[i] = curSum;
        }
        System.out.println(Arrays.toString(weight));


    }

    public int pickIndex() {
        double picked = Math.random();
        int idx = Arrays.binarySearch(weight, picked);
        if(idx < 0) {
            idx = -idx - 1;
        }
        System.out.println(picked);
        System.out.println(idx);
        return idx;
    }
}
