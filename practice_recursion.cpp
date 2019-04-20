#include <iostream>
#include <math.h>
using namespace std;

//divide and conquer
int sumOfSquares(int arr[], int arrSize) {
    if(arrSize==1){
        return arr[0]*arr[0];
    }
    
    int mid = arrSize/2;
    int leftarr[arrSize/2];
    int rightarr[arrSize/2];
    int sumOfsuqres=0;
    
    for(int i=0; i<mid; i++){
        leftarr[i] = arr[i];
        rightarr[i] = arr[mid+i];
    }
    
    
    sumOfsuqres+=sumOfSquares(leftarr, mid);
    sumOfsuqres+=sumOfSquares(rightarr, arrSize-mid);
    return sumOfsuqres;
}

bool isSorted(int arr[], int arrSize){
    if(arrSize==1){
        return true;
    }else if(arrSize==2){
        if(arr[0]<=arr[1]){
            return true;
        }else
            return false;
    }
    
    int mid = arrSize/2;
    int leftarr[arrSize/2];
    int rightarr[arrSize/2];
    
    for(int i=0; i<mid; i++){
        leftarr[i] = arr[i];
        rightarr[i] = arr[mid+i];
    }
    
    if( isSorted(leftarr, mid)==true && isSorted(leftarr, arrSize-mid)==true)
        return true;
    else
        return false;
}

//efficient method

int sumOfSquares2(int arr[], int arrSize){
    int resSumOfSquares;
    
    if(arrSize==1){
        return pow(arr[0],2);
    }else{
        resSumOfSquares = sumOfSquares2(arr, arrSize-1);
        resSumOfSquares += pow(arr[arrSize-1],2);
        return resSumOfSquares;
        
    }
}

bool isSorted2(int arr[], int arrSize){
    
    if(arrSize==1){
        return true;
    }else{
        if(isSorted2(arr, arrSize-1)==true){
            return (arr[arrSize-2]<=arr[arrSize-1]);
        }else{
            return false;
        }
    }
}



int main(){
    int testArr[4] ={1,2,8,10};
    
    cout<<"total is "<<sumOfSquares(testArr, 4)<<endl;
    cout<<"Sorted is "<<isSorted(testArr, 4)<<endl;
    
    
}
