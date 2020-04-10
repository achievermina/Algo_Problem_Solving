public class Leet844_BackspaceStringCompare {

    public boolean backspaceCompare(String S, String T) {

        if(S.length() == 0 || T.length() == 0 ) return false;
        int i = 0, j = 0, cnt =0;
        String newS = "", newT = "";
        while (i<S.length()) {
            if (S.charAt(i) == '#'){
                cnt=0;
                while(i<S.length() && S.charAt(i) == '#'){
                    i++; cnt++;
                }
                newS = newS.substring(0, Math.max(0, newS.length()-cnt));
            } else {
                newS = newS+S.charAt(i);
                i++;
            }
        }

        while (j<T.length()) {
            if (T.charAt(j) == '#'){
                cnt=0; i++;
                while(j<T.length() && T.charAt(j) == '#'){
                    j++; cnt++;
                }
                newT = newT.substring(0, Math.max(0, newT.length()-cnt));
            } else {
                newT = newT+T.charAt(j);
                j++;
            }
        }
        return newS.equals(newT);

    }
}
