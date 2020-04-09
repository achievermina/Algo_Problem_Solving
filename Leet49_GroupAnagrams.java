import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.List;


public class Leet49_GroupAnagrams {
    public static List<List<String>> groupAnagrams(String[] strs) {

        Map<String, List<String>> groups = new HashMap<String, List<String>>();

        for (String str:strs) {
            char[] ar = str.toCharArray();
            Arrays.sort(ar);
            String sorted = String.valueOf(ar);
            if(!groups.containsKey(sorted)) groups.put(sorted, new ArrayList<String>());
            groups.get(sorted).add(str);
        }

        return new ArrayList(groups.values()); //change to simpler answer instead of using another for loop.
    }

}
