class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largestNumber = INT_MIN;
        int secondLargest = INT_MIN;
        
        for(int i: arr){
            if(i>largestNumber){
                secondLargest = largestNumber; //it meams it automatically greater than 2nd
                largestNumber = i;
            }
            
            else if(i>secondLargest && i != largestNumber){  //i != largestNumber --> checks for same number
                secondLargest = i;
            }
        }
        
        if(secondLargest == INT_MIN) return -1;
        else return secondLargest;
    }
};
