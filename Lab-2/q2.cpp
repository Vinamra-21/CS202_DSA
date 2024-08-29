#include<bits/stdc++.h>
using namespace std;
// //merge sort
int merge(int* arr,int s,int e,int& counter){
    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1+1];
    int *second = new int[len2+1];
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }
    first[len1]=INT_MAX;
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }
    second[len2]=INT_MAX;
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while(index1 <len1 || index2 <len2) {
        if(first[index1] < second[index2]) {
            counter++;
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            counter++;
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    delete []first;
    delete []second;
}
void mergesort(int* arr,int s,int e,int& counter){
    if(s>=e){return;}
    int mid=(s+e)/2;
    mergesort(arr,s,mid,counter);
    mergesort(arr,mid+1,e,counter);
    merge(arr,s,e,counter);
}
int main(){
    int counter=0;
    cout<<"Number of elements:";
    string n;
    cin>>n;
    for(int i=0;i<n.length();i++){if(!(isdigit(n[i]))){cout<<"invalid input:enter positive integer";exit(0);}}
    int k=stoi(n);
    int arr[k];
    cout<<"Enter the elements with space between 2 elements"<<endl;
    for(int i=0;i<k;i++){
        string temp;
        cin>>temp;
        for(int i=0;i<temp.length();i++){if(!(isdigit(temp[i]))){if(temp[i]=='-'){}else{cout<<"invalid input:enter positive integer";exit(0);}}}
        arr[i]=stoi(temp);}
    mergesort(arr,0,k-1,counter);
    for(int i=0;i<k;i++){cout << arr[i] << " ";} 
    cout << endl;
    cout<<"Number of comparisons: "<<counter;
    return 0;
}