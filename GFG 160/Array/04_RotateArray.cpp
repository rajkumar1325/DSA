// we use a method (reversal algorithm)
//  12345  d=2
//          1. reverse k elements            21 345
//          2. reverse remaining elements    21 543    
//          3. reverse all element           345 12

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        
        // code here
        
        // handle edge cases
        if(d>=arr.size()){
            d = d % arr.size();
        }
        
        reverse(arr.begin(), arr.begin()+d); //1st
        
        reverse(arr.begin()+d, arr.end()); //2nd
        
        reverse(arr.begin(), arr.end()); //3rd
        
    }
};
