//
//  CTCI_8.7_.cpp
//  graph_dfs
//
//  Created by Mina on 04/07/2019.
//
//8.7 Permutations without Dups: Write a method to compute all permutations of a string of unique characters.


#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


vector<string> genPerm(string word, map<string, vector<string>> hashtable){
    
    int size =(int) word.size();
    
    //sort word --sort가 필요한 이유는?
    string sortedWord = word;
    sort(sortedWord.begin(), sortedWord.end());
    
    //if memoization value -> use it
    if(hashtable.count(sortedWord)==1){
        return hashtable.find(sortedWord)->second;
    }
    
    //if not --> generate the vector string list
    vector<string> permList;
    
    //Base case
    //    if(size==0){
    //        return NULL;
    //    }else
    if(size ==1){
        permList.push_back(sortedWord);
        hashtable.insert(pair<string, vector<string>>(sortedWord, permList));
        
        return permList;
    }
    
    //other cases
    for(int i=0; i<size; i++){
        string left= sortedWord.substr(0,i);
        string right= sortedWord.substr(i+1,size);
        
        vector<string> beforePermList = genPerm(left+right, hashtable);
        
        for(int j=0; j<beforePermList.size(); j++){
            permList.push_back(sortedWord[i]+beforePermList[j]);
        }
    }
    
    
    hashtable.insert(pair<string, vector<string>>(sortedWord, permList));
    
    return permList;
}

//memoization list array table

vector<string> permutations(string word){
    
    //Create the hash table for memoization
    map<string, vector<string>> hashmap;
    
    return genPerm(word, hashmap);
}
void print(vector<string> vec){
    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << ' ';
}

int main(){
    string str = "abc";
    print(permutations(str));
}


/*
 // function to print string in sorted order
 void sortString(string &str)
 {
 // Hash array to keep count of characters.
 // Initially count of all charters is
 // initialized to zero.
 int charCount[MAX_CHAR] = {0};
 
 // Traverse string and increment
 // count of characters
 for (int i=0; i<str.length(); i++)
 
 // 'a'-'a' will be 0, 'b'-'a' will be 1,
 // so for location of character in count
 // array we wil do str[i]-'a'.
 charCount[str[i]-'a']++;
 
 // Traverse the hash array and print
 // characters
 for (int i=0;i<MAX_CHAR;i++)
 for (int j=0;j<charCount[i];j++)
 cout << (char)('a'+i);
 }
 */
