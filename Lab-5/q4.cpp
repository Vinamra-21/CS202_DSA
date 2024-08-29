#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    cout<<"Enter the number of lists:";
    int k;
    cin >> k;

    vector<vector<int>> a(k);

    for(int i = 0; i < k; i++){
        cout<<"Size of list "<<i+1<<":";
        int size;
        cin >> size;
        cout<<"Enter elements:";
        a[i] = vector<int>(size);
        for(int j = 0; j < size; j++){
            cin >> a[i][j];
        }
    }

    vector<int> idx(k,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // Push the first element of each array into the priority queue
    for(int i = 0; i < k; i++){
        pair<int,int> p;
        p.first = a[i][0];
        p.second = i; // Index of the array
        pq.push(p);
    }

    vector<int> ans;

    // Continue until all arrays are exhausted
    while(true){
        if(pq.empty()){
            break;
        }
        pair<int,int> x = pq.top();
        pq.pop();
        ans.push_back(x.first); // Store the popped element
        if(idx[x.second] + 1 < a[x.second].size()){
            pair<int,int> p;
            p.first = a[x.second][idx[x.second] + 1];
            p.second = x.second;
            pq.push(p);
        }
        idx[x.second] += 1;
    }

    // Print the merged array
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
