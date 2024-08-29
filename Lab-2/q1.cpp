#include<bits/stdc++.h>
using namespace std;
// // insertion sort
int main(){
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
    int counter_compare=0;
    int counter_swap=0;
    for(int i=1 ;i<k;i++){
        int key=arr[i];
        int j=i-1;
        counter_compare+=j+1;
        while(j>=0 and arr[j]>key){
            arr[j+1]=arr[j];
            counter_swap++;
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<k;i++){cout<<arr[i]<<" ";}
    cout<<endl;
    cout<<"Numer of compares:"<<counter_compare<<endl;
    cout<<"Numer of swaps:"<<counter_swap<<endl;
}