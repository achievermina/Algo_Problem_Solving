public class Leet509_Fibonacci {

    public static int fib(int N) {
        if(N == 0) return 0;
        else if(N == 1) return 1;

        int[] box = new int[N+1];
        box[0] = 0;
        box[1] = 1;

        for (int i = 2; i <= N; i++) {
            box[i] = box[i-1] + box[i-2];
        }
        return box[N];
    }

    public static void main(String[] arg) {
        System.out.print(fib(30));
    }
}
