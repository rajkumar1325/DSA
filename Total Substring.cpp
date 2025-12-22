// Find the total number of substring of a string.
// math formula = n(n+1)/2



#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    string s = "abcdef";
    
    string result;
        
    int n = s.size();
    
    for(int i=0; i< n; i++){
        for(int j=1; (i+j)<=n; j++){      //note :    i+j < n
            result = s.substr(i, j);
            cout<<result<< " ";
        }
        cout<<endl;
        
    }
    

    return 0;
}



/*
string s = "abc";
int n = s.size();

for (int i = 0; i < n; i++) {
    for (int len = 1; i + len <= n; len++) {
        string sub = s.substr(i, len);
        cout << sub << endl;
    }
}




- i = starting index
- len = length of substring

s.substr(i, len) = substring starting at i of length len

For "abc":



| i | len | substring |
| - | --- | --------- |
| 0 | 1   | "a"       |
| 0 | 2   | "ab"      |
| 0 | 3   | "abc"     |
| 1 | 1   | "b"       |
| 1 | 2   | "bc"      |
| 2 | 1   | "c"       |

*/
