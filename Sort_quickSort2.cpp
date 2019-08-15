
//When using the last element as a pivot
//DEBUGGING NEEDED

//MISSING POINTS
//1. Because we are using the last element, we need to move the last element as well.
// how? My first thought was swap ( mid, pivot)
// Actually, after moving the elements, we can place pivot at correct position by swapping
//2. Assign the left and right boundaries


#include <iostream>
using namespace std;

void swap(int array[], int left, int right){
    int temp = array[left];
    array[left]= array[right];
    array[right]= temp;
}

void printArray(int array[], int start, int end){
    for(int i=start; i<=end; i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}
void quickSort(int arr[], int start, int end){ //end is inclusive
    //base
    if(end-start<=1)
        return;
    
    int pivot = arr[end];
    //cout<<pivot<<endl;
    int left=start, right = end-1;
    
    //cout<<"start: "<<start<<" "<<"end: "<<end<<endl;
    
//    //To include the pivot in sorting, changing the position of the pivot to the middle
//    int mid = (end-start)/2;
//    swap(arr, mid, end);
//    printArray(arr,start,end);

    while(left<right){
        while(arr[left]<pivot  && left<=end-1) left++;
        while(arr[right]>=pivot && right>=0) right--;
        
        if(left<right)
            swap(arr, left, right);
        printArray(arr,start,end);
    }
    swap(arr, left,end);
    quickSort(arr, start, left-1);
    quickSort(arr, left, end);
    
}


int main(){
    int arr[6] = {10, 7, 8, 9, 1, 5};
    int arr2[10] = {5,10,2,4,33,3,7,6,9,8};
    //int arr2[5] = {5,8,2,4,10};

    quickSort(arr2, 0, 9);
    printArray(arr2, 0,9);
    
    quickSort(arr, 0, 5);
    printArray(arr, 0,5);
}
