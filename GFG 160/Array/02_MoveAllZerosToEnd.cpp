// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // logic: push all non-zero to first and then update the arr-size with 0
        
        vector<int>number; //initalise all with 0 first
        for(int i: arr){
            if(i ==0) continue; //skip
            
            else 
            number.push_back(i);
        }
        
        
        int sizeToRun = arr.size() - number.size();
        
        // fill the remaining index with 0
        for(int i=0; i<sizeToRun; i++){
            number.push_back(0);
        }
        
        arr = number;
        
    }
};
