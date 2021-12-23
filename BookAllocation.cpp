#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool isPossible(vector<int> arr, int n, int m,int mid){
    int studCount = 1;
    int pageSum = 0;
    for(int i =0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];  //1st stud k liye total pages alloted
            cout << "pg1=" << pageSum << " ";
        }else{
            studCount += 1;
            if(studCount > m || arr[i] > mid){
                return false;
            }
//             pageSum = 0;
            pageSum = arr[i];
            cout << "pg2=" << pageSum << " ";
        }
        if(studCount > m){
            return false;
        }
    }
    cout << "True, " << mid << endl;
    return true;
}

int main(){
    vector<int> arr{10,40,60,20,50};
    int n = 5;
    int m = 2;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int s = 0;
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid -1;
            cout <<" Found Possible" << endl;
        }else{
            s = mid + 1;
            cout << "Found Impossible" << endl;
        }
        mid = s + (e-s)/2;
    }
    cout << ans;
}