//
//  heapSort.cpp
//
//  Created by Mina on 18/06/2019.
//  Copyright © 2019 Mina. All rights reserved.
//


//Heap
// Parent(i) = floor(i/2)
// leftchild(i) = 2i
// rightchild(i) = 2i+1


#include <iostream>
#include <cmath>
using namespace std;


void maxHeapify(int array[], int index);
void Sort(int array[]);
int Maximum(int array[]);
int ExtractMax(int array[]);
void IncreaseKey(int array[], int index, int key);
void Insert(int array[]);
void swap(int array[], int a, int b);
void build(int array[]);
void print(int array[]);



void build(int array[]){
    
    int size= sizeof(array)/sizeof(int);
    int index = floor(size/2);
    for(int i = index; i>=0; i--){
        maxHeapify(array, i);
    }

}


void maxHeapify(int array[], int index){
    int left = index*2;
    int right = index*2 +1;
    int size= sizeof(array)/sizeof(int);
    int largest;
    
    //check left child
    if(left<= size && array[left]>array[index])
        largest = left;
    else
        largest = index;
    
    //check right child
    if(right<= size && array[right]>array[index])
        largest = right;
    
    if(largest!=index){
        swap(array, largest, index);
        maxHeapify(array, largest);
    }
    
    
}

void swap(int array[], int a, int b){
    int temp = array[a];
    array[a]= array[b];
    array[b]= temp;
}


void print(int array[]){
    int size= sizeof(array)/sizeof(*array); //why not working? kee saying the size is 2 eventhough it should be 5

    for(int i=0; i<size; i++){
        cout<<array[i]<<"\t";
    }
}



int main(){
    int arr2[5]= {4,5,2,1,8};
    print(arr2);
    
    maxHeapify(arr2, 0);
    print(arr2);
}
