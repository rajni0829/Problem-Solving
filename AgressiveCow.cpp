//Aggressive Cow : Advanced BS Problem
#include <iostream>
using namespace std;
#include <utility>
#include<vector>

bool isPossible(vector<int> &stalls,int mid,int k){
    int cowCount=1;
    int lastPos = stalls[0];
    cout << "mid= "<< mid;
    for(int i=0;i<stalls.size();i++){
        // cout << "LP=" << lastPos << endl;
        // cout << "Stalls[i]=" << stalls[i] << endl; 
        // cout << "stalls[i]-lastPos= " << stalls[i]-lastPos << endl;
        if(stalls[i]-lastPos >= mid){
            cowCount ++;
            // cout << "cowCount= " << cowCount << " Mid=" <<mid <<endl;
            if(cowCount == k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}


int main()
{
    vector<int> stalls{1,2,3,4,6};
    int k = 2;
    sort(stalls.begin(),stalls.end());
    int maxi = stalls[0];
    for(int i=0; i<stalls.size();i++){
        if(maxi < stalls[i]){
            maxi = stalls[i];
        }
    }

    int s = 0;
    int e = maxi;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(isPossible(stalls,mid,k)){
            // cout << "Possible"<<endl;
            ans = mid;
            s = mid + 1;
            // cout << "mid" << mid << endl;
        }else{
            cout << "Not" << endl;
            e = mid - 1;
        }
        mid = s + (e-s)/2;
        // cout << s << e <<mid << endl;
    }
    cout<< ans;
}
