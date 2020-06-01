import java.util.Deque;
import java.util.LinkedList;


// count 써서 다시해야함
public class Leet1249_MinimumRemovetoMakeValidParentheses {
    public String minRemoveToMakeValid(String s) {
        int balance =0;
        char[] chars = s.toCharArray();
        String newString = "";

        for (int i =0; i < chars.length; i++) {
            char ch = chars[i];
            if (Character.isLetter(ch)) {
                continue;
            }else if (ch == '(') {
                balance ++;
            } else {
                if (balance == 0) {
                    chars[i] = '*';
                } else {
                    balance --;
                }
            }
        }


        for (int i = chars.length; i >= 0; i--) {
            if (balance > 0 && chars[i] == '(') {
                chars[i] = '*';
                balance --;
            }
        }

        for (int i =0; i < chars.length; i++) {
            if(chars[i] != '*') {
                newString += chars[i];
            }
        }
        return newString;
    }
}

//
//public String minRemoveToMakeValid(String s) {
//        char[] chars = s.toCharArray();
//        int cnt = 0;
//        String newString = "";
//        Deque<Character> stack = new LinkedList<Character>();
//        for (char ch : chars) {
//            if (Character.isLetter(ch)) {
//                newString += ch;
//                continue;
//            }
//
//            if ((ch == '(' && (stack.isEmpty() || stack.getLast() == ')')) {
//
//            }
//
//            if ((ch == ')' && !stack.isEmpty() && stack.getLast() == '(')) {
//                newString += ch;
//                stack.addLast(ch);
//            }
//
//        }
//
//        if (!stack.isEmpty() && stack.getLast() == '(') {
//            int idx = newString.lastIndexOf('(');
//            newString = newString.substring(0, idx) + newString.substring(idx+1);
//        }
//
//        return newString;
//
//    }
//}
