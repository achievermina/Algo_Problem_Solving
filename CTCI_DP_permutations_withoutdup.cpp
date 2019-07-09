//
//  CTCI_8.7_.cpp
//  graph_dfs
//
//  Created by Mina on 04/07/2019.
//
//8.7 Permutations without Dups: Write a method to compute all permutations of a string of unique characters.


#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

//memoization list array table

vector<string> permutations(string word){
    
    //Create the hash table for memoization
    
    
    //initialize the table


    return genPerm(string word, hashMap hashtable);
}

vector<string> genPerm(string word, hashMap hashtable){
    int size =(int) word.size();

    //sort word
    string sortedWord = mergesort(word);
    
    
    //if memoization value -> use it
    if(isEmpty(sortedWord)!=NULL)
        return findList(sortedWord);

    
    //if not --> generate the list
    vector<string> permList;
    
    //Base case
    if(size==0){
        return NULL;
    }else if(size ==1){
        permList.append(sortedWord);
        return permList;
    }
    
    //other cases
    for(int i=0; i<size; i++){
        string left= sortedWord.substr(0,i);
        string right= sortedWord.substr(i+1,size);
        
        vector<list> beforePermList = permutations(left+right);
        
        for(int j=0; j<beforePermList.size(); j++){
            permList.append(sortedWord[i]+beforePermList[j]);
        }
    }
    
    
    addToHashtable(calculateKey(), permList);
    
    return permList;
}

