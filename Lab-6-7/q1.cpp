#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int>& arr){
    int max=arr[0];
    for(int i=1;i<arr.size();i++){
        if (arr[i]>max){
        max=arr[i];}
    }
    return max;
}

void countSort(vector<int>& arr,int exp){
    vector<int> output(arr.size());
    vector<int> count(10,0);

    for(int i=0;i<arr.size();i++){
        count[(arr[i]/exp)%10]++;
    }
    for (int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=arr.size()-1;i>=0;i--){
        output[--count[(arr[i]/exp)%10]]=arr[i];
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=output[i];
    }
}

void radixSort(vector<int> & arr){
    int max=getMax(arr);

    for(int exp=1;max/exp>0;exp*=10){
        countSort(arr,exp);
    }
}

void printArray(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    vector<int> arr={170,45,75,90,882,24,2,66};
    cout<<"Original Array: ";
    printArray(arr);

    radixSort(arr);

    cout<<"Sorted Array: ";
    printArray(arr);
    return 0;

}