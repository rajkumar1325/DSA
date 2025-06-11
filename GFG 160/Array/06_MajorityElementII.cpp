class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        vector<int> result;
        int size = arr.size();
        
        // create a frequency mapping.
        unordered_map<int,int> freq;
        for(auto &x: arr){
            freq[x]++;
        }
        
        
        for(auto &x: freq){
            if(x.second > size/3){
                result.push_back(x.first);
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};


// ques link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote
