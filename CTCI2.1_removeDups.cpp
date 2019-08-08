//
//  CTCI2.cpp
//  algo
//
//  Created by Mina on 07/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//



#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;


LinkedList* removeDups(Node* start){
    map<int> hashtable;
    Node* cur=start, prev=NULL, temp;
    while(cur!=NULL){
        if(hashtable.count(cur->val)==0){ // find (x) --> COUNT
            hashtable.insert(cur->val);  // ADD(x) -> INSERT
            prev =cur;
            cur= cur-> next;
        }else{
            temp = cur->next;
            prev->next= cur->next;
            delete cur;
            cur= temp;
        }
    }
}
