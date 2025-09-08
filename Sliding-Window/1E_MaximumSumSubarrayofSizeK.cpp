// Find the maximum sum of any contiguous subarray of size k.
// Example: [2, 1, 5, 1, 3, 2], k=3 → 9


#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> num = {2, 1, 5, 1, 3, 2};
    int k=3;

    int maxSum = INT_MIN;

    for (int i = 0; i < num.size()-k; i++){ //we have used -k as we move k times inside nested 
        int sum =0;
        for (int j = 0; j < k; j++){
            sum += num[i+j];
        }
        maxSum = max(maxSum, sum); //current-sum VS max-sum
        
    }

    cout<<maxSum;
}
