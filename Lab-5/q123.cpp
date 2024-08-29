
#include<iostream>
#include<vector>
using namespace std;

void heapify(int* arr,int n,int i){
        int largest=i;
        int lchild=2*i;
        int rchild=2*i+1;
        if(lchild<n && arr[largest]<arr[lchild]){
           largest=lchild;
        }
         if(rchild<n && arr[largest]<arr[rchild]){
             largest=rchild;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        return;
        }


class max_heap{
    public:
        int size;
        vector <int> arr;

        max_heap(){
            arr.push_back(-1);
            size=0;
        }
        

        void increase_key(int ele,int val){
            if (arr[ele]>val){
                cout<<"New key is smaller"<<endl;
                return;
            }
            arr[ele]=val;
            while(ele>1 && arr[ele/2]<arr[ele]){
                swap(arr[ele/2],arr[ele]);
                ele=ele/2;
            }
        }

        void print(){
            for (int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
        int deleteheap(){
            if(size==0){
                cout<<"Heap is empty"<<endl;
                return 0;
            }
            int k=arr[1];
            arr[1]=arr[size];
            size--;
            int index=1;
            while(index<size){
                int lchild=index*2;
                int rchild=index*2+1;
                if(lchild<size && arr[lchild]>arr[index]){
                    swap(arr[lchild],arr[index]);
                    index=lchild;
                }
                if(rchild<size && arr[rchild]>arr[index]){
                    swap(arr[rchild],arr[index]);
                    index=rchild;
                }
                    return k ;
            }
        }

        void insert(int val){
            int index=++size;
            arr.push_back(val);
            while(index>1){
                int parent=index/2;
                if(arr[index]>arr[parent]){
                    swap(arr[index],arr[parent]);
                    index=parent;
                }else{
                    return;
                }
            }
        }
};

void heapsort(int arr[],int n){
    int size=n;

    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main(){
    max_heap h;
    int n;
    cout<<"Number of Elements:";
    cin>>n;
    for(int j=1;j<=n;j++){
        int temp;
        cin>>temp;
        h.insert(temp);
    }
    cout<<"Max-heap:"<<endl;
    h.print();
    cout<<"element deleted:"<<h.deleteheap()<<endl;
    h.print();
    h.increase_key(3,65);
    cout<<"increased key 3 to 65"<<endl;
    h.print();

    int test[8]={-1,1,2,3,1,1,1,1};
    int t=7;
    cout<<"Print array:"<<endl;
    for(int i=1;i<=t;i++){
        cout<<test[i]<<" ";
    }cout<<endl;


    for(int i=t/2;i>0;i--){
        heapify(test,t,i);
    }
    cout<<"Print heapified array:"<<endl;
    for(int i=1;i<=t;i++){
        cout<<test[i]<<" ";
    }cout<<endl;


    heapsort(test,n);
    cout<<"Print sorted array"<<endl;
    for(int i=1;i<=t;i++){
        cout<<test[i]<<" ";
    }cout<<endl;

    return 0;
}
