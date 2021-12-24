#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void printArr(int n, vector<int> &arr){
    for(int i=0;i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int>arr{4,3,5,7,3,1,8};
    int n = arr.size();
	for(int i=1;i<n;i++){
        int temp = arr[i];
        int j=i-1;
        // cout << "temp"<<temp<<endl;
        for(; j>=0;j--){
            // cout << "changing j =" << j<<endl;                

            if(temp<arr[j]){
                //shift right
                // cout << "before arr[j+1]=" << arr[j+1] << endl;
                arr[j+1] = arr[j];
                // cout << "i=" << i << endl;
                // cout << "arr[j+1] assigned = " << arr[j+1] << " " << arr[j]<< endl;
            }else{
                break;
            }
            // printArr(n,arr);
        }
        // cout << "ooLoop"<< endl;
        arr[j+1] = temp;
    }
    printArr(n,arr);
}