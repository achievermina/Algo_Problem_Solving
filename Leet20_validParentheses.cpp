bool isValid(string s) {
        stack<int> st;
        map<char,char> map;
        map['(']=')';
        map['{']='}';
        map['[']=']';
        
        for(char c : s){
            if(c =='(' ||c =='{' ||c =='[' ){
                st.push(c);
            }else if(st.empty())
                return false;
            else if(map[st.top()]== c){
                st.pop();
                continue;
            }else
                return false;
                
        }
        if(st.empty())
            return true;
        else
            return false;
    }
