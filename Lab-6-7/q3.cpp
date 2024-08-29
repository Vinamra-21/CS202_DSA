#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int>& arr ,int left, int right){
    if(left<right){
        int pivot=arr[right];
        int i=left-1;
        for(int j=left;j<right;j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[right]);
        int partition_index=i+1;
        quick_sort(arr,left,partition_index-1);
        quick_sort(arr,partition_index+1,right);
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

    quick_sort(arr,0,7);

    cout<<"Sorted Array: ";
    printArray(arr);
    return 0;

}