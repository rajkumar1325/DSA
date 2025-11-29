#include<bits/stdc++.h>
using namespace std;
// ....................................2 pointer approach..............................................
//.........note: For 2 pointer approach we always compare indexes inside the while loop, never compare values inside it.
/*
    KEY RULES TO REMEMBER -- {This ONLY works because the array is sorted.}
    ✔ If sum < target → move left forward
                    Because left forward means bigger numbers.

    ✔ If sum > target → move right backward
                    Because right backward means smaller numbers.
*/

int main(){
    int target = 10;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,23};
    int n = arr.size();

    // using 2 pointer
    int left = 0;
    int right = n-1;

    while (left<right)
    {
        if(arr[left] + arr[right] == target){
            cout<<"Found and the elements are "<< arr[left]<< "and" << arr[right];
            return 0;
        }

        else if((arr[left] + arr[right]) < target){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<"Not Found";


}
