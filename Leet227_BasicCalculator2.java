import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

public class Leet227_BasicCalculator2 {
    public int calculate(String s) {
        Deque<Integer> stack = new ArrayDeque<Integer>();
        char[] string = s.toCharArray();
        String prev = ""; //1 int 2 char
        for(int i=0; i < s.length(); i++) {
            if(Character.isDigit(string[i])){
                if (prev == "") {
                    prev += string[i];
                    stack.addLast(prev);
                } else {
                    stack.peekLast();
                    prev += string[i];
                    stack.addLast(prev);
                }

            }else{
                if(string[i] == '+' || string[i] == '-' ) {
                    stack.addLast(string[i]);
                }else {
                    if(string[i] == '*') {
                        ++i;
                        int last = stack.peekLast()-'0';
                        int next = string[i] - '0';
                        int calc = last*next;
                        char temp = (char)(calc+'0');
                        stack.addLast(temp);
                    }else{
                        ++i;
                        int last = stack.peekLast()-'0';
                        int next = string[i] - '0';
                        char temp = (char)(last/next+'0');
                        stack.addLast(temp);
                    }
                }
            }
        }

        while(!stack.isEmpty()) {
            int q.peekFirst()
        }
    }
}
