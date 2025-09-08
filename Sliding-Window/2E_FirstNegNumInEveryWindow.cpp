// For each window, print the first negative number (or 0 if none).
// Example: [12, -1, -7, 8, -15, 30, 16, 28], k=3 → [-1, -1, -7, -15, -15, 0]

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int>result; //to store result

    for(int i=0; i<=nums.size()-k; i++){
        bool flag = false;

        for (int j = 0; j < k; j++){
            cout<<nums[i+j]<<" ";

            if(nums[i+j] <0){
                result.push_back(nums[i+j]);
                flag = true;
                break;
            }
        }
        if(flag == false){
            result.push_back(0);
        }
        cout<<endl;
        
    }

    cout<<"\n\n";
    for(int i: result){
        cout<<i<< " ";
    }
}
