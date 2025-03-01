#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
// Approach:
//  --> find the freq of 2 strings element
//  --> compare 1st string key-value with second.
// --> if not fount -> count++;
// --> return count;

    unordered_map<char, int>freq1;
    unordered_map<char, int> freq2;
    
    for(char ch: s1){
        freq1[ch]++;
    }
    
    for(char ch: s2){
        freq2[ch]++;
    }
    
    int count=0;
    
    for(auto [ch, frequen]: freq1){
        count += abs(frequen - freq2[ch]);
        freq2.erase(ch); //remove checked character
    }
        
    // add reminaing char in freq1 that are not in freq2
    
    /*
        The reason you must add the remaining characters in freq2 (that were not found in freq1) is that these characters are extra in s2 and need to be deleted to make both strings anagrams.
    
    */
    
    for(auto [ch, fre]: freq2){
        count += fre;
    }
    return count;;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
