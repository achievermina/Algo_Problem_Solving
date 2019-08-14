//
//  Leet146_LRUcache.cpp
//  algo
//
//  Created by Mina on 11/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <queue>
#include <vector>
#include <map>

using namespace std;
/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 
 */

//start from the queue
//BUT realized maybe queue is not the best datastructure
//It is hard to find the element from the queue, and delete it and update it

//Maybe priority-queue?
//how can I update the priority queue's priority? Impossible

//queue 에 중복으로 넣고 뺄때 혹시 큐가 중복이 있는지를 먼저 보구 그러면 리무브 안하고 다음껄 리무브 하는 방식으로 가야함
//Dijkstra 알고리즘 할 때 이렇게 많이씀 --> 이때는 근데 다른매트릭스에서 저장된 코스트를 비교하니까 가능한데 지금은 모르겠음


/*
 From Dijkstra algo :
 priority_queue<pair<int,int>> pq;
 pq.push(make_pair(0,src);
 while(!pq.empty()){
     int cost = -pq.top().first();
     int here= pq.top().second;
     pq.pop();
    if( dist[here] <cost)
        continue;
 */


class LRUCache {
    int maxSize;
    int currentSize;
    map<int, int> hash;
    deque<int> q;
    
    public:
    LRUCache(int capacity) {
        maxSize = capacity;
        currentSize =0;
    }
    
    int get(int key) {
        if(hash.count(key)==1){
            updateQueue(key); //delete key and re enter to the back
            return hash.find(key)->second;
            
        }else
        return -1;
        
    }
    
    void put(int key, int value) {
        
        //Check if the key is existing
        if(hash.count(key)==1){
            hash.find(key)->second = value;
            updateQueue(key); //delete key and re-enter to the back
        }else{
            //Make a space
            if(currentSize>=maxSize){
                int LSU = q.front();
                q.pop_front();
                hash.erase(LSU);
                currentSize--;
            }
            //Enter new key, value
            hash.insert(pair<int, int>(key, value));
            q.push_back(key);
            currentSize++; //Increase the current Size
        }
    }
    
    void updateQueue(int key){
        q.erase(remove(q.begin(), q.end(), key), q.end());
        q.push_back(key);
        //update queue - find the key from the queue and push it to the back
    }
};


//FIRST ATTEMPT
//class LRUCache {
//    int maxSize;
//    int currentSize;
//    map<int, int> hash;
//    deque<int> q;
//
//public:
//    LRUCache(int capacity) {
//        maxSize = capacity;
//        currentSize =0;
//    }
//
//    int get(int key) {
//        if(hash.count(key)==1){
//            updateQueue(key); //delete key and re enter to the back
//            return hash.find(key)->second;
//
//        }else
//            return -1;
//
//    }
//
//    void put(int key, int value) {
//
//
//        if(currentSize>=maxSize){
//            int LSU = q.front();
//            q.pop_front();
//            hash.erase(LSU);
//            q.push_back(key);
//            hash.insert(pair<int, int>(key, value));
//        }
//
//        if(hash.count(key)==1){
//            hash.find(key)->second = value;
//            updateQueue(key); //delete key and re enter to the back
//        }else{
//            hash.insert(pair<int, int>(key, value));
//            q.push_back(key);
//        }
//    }
//
//    void updateQueue(int key){
//        //update queue - find the key from the queue and push it to the back
//        q.erase(remove(q.begin(), q.end(), key), q.end());  //이렇게 하니까 도네!
//        q.push_back(key);
//    }
//};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
