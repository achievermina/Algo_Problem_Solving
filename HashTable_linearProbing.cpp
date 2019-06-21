//
//  HashTable_linearProbing.cpp
//
//  Created by Mina on 20/06/2019.
//Reference: https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp

#include <iostream>
#include <string>
using namespace std;


class hashNode{
    
    int key;
    string value;
    
    hashNode(int key, string value):key(key), value(value){}
    

    friend class hashMap;
    
};

class hashMap{
    
    int size;
    int element;
    hashNode* node;
    hashNode** hashArr;
    
public:
    
    hashMap(int arrSize):size(arrSize),element(0), node(NULL){
        
        //First, need to define hashArr in the class
        //Second, define dynamic allocation
        hashArr = new hashNode*[arrSize]; //왜 hashNode*[size]? not *hashNode[size]?
        
        for(int i=0; i<arrSize; i++){
            hashArr[i]=NULL;
        }
        
    }
    
    void insert(int key, string value){
        int originalIdx = calculateIndex(key);
        int idx = originalIdx;
        
        if(element>size){
            cout<<"No more space size: "<<size<<" and filled: "<<element<<endl;
            return;
        }
        
        hashNode* newNode = new hashNode(key,value);
  
        if(hashArr[idx] == NULL || hashArr[idx]->key==key ){ //the second case should not increase the element
            hashArr[idx] = newNode;
            element ++;
        }else{
        
            while(hashArr[idx] != NULL){
                idx ++;
                if(idx>=size)
                    idx=0;
            }
            hashArr[idx] = newNode;
            element++;
        }
        
    }
    
    int calculateIndex(int key){
        int index = key%size;
        return index;
    }
    
    
    void deleteKey(int key){
        
    }
    
    void get(int searchKey){
        int originalIdx = calculateIndex(searchKey);
        int idx =originalIdx;
        
        if(hashArr[idx]->key ==  searchKey){
            cout<<"Found key: "<<searchKey<<" and value: "<<hashArr[idx]->value<<endl;
        }else{
            while(hashArr[idx]->key !=  searchKey){
                idx ++;
                if(idx>=size)
                    idx=0;
                
                if(idx==originalIdx){
                    cout<<" No such key found"<<endl;
                    return;
                }
            }
            cout<<"Found key: "<<searchKey<<" and value: "<<hashArr[idx]->value<<endl;
            
        }
    }
    
    void display(){
        for(int i=0; i<size ; i++)
        {
            if(hashArr[i] != NULL)
                cout << "key = " << hashArr[i]->key
                <<"  value = "<< hashArr[i]->value << endl;
        }
    }
};


int main(){
    hashMap *h = new hashMap(5);
    h->insert(1,"a");
    h->insert(2,"b");
    h->insert(2,"c");
    h->insert(7,"d");

    h->display();
    
    h->insert(3,"d");
    h->insert(5,"e");
    h->insert(0,"f");
    
    h->display();
    
    h->get(2);
    
    return 0;
}
