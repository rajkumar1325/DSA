#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    
/*Approach: 
    --> Use a hash map, store how many times each character appears in the given string.    
    -->Traverse through the frequency table and count how many characters have an odd frequency.
    --> If odd frequency count <= 1, the string can be rearranged into a palindrome --> Return "YES".
    --> Otherwise, return "NO".
*/    
    unordered_map<char, int> freq;
    // counting occurances/ frequency
    for(char h: s){
        freq[h]++;
    }
    
    
    // traversing freq table
    int oddFreqCount=0;
    for(auto c: freq){
        if (c.second%2 !=0) {
            oddFreqCount ++;
        }
    }
    
    if (oddFreqCount<=1) {
        return "YES";
    }
    else {
    return "NO";
    }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
