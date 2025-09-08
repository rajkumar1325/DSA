// Given strings txt and pat, count how many substrings of txt are anagrams of pat.
// Example: txt="cbaebabacd", pat="abc" → 2 (anagrams are "cba", "bac")

// ANAGRAM :: a word or phrase that is made by arranging the letters of another word or phrase in a different order
//  for Anagram solving: Simply sort and then compare both
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool Anagram(string pat, string target)
{

    sort(target.begin(), target.end());
    sort(pat.begin(), pat.end());

    if(pat == target){
        return true;
    }
    return false;
}

int main()
{
    string txt = "cbaebabacd";
    string target = "abc";

    vector<string> result;

    for (int i = 0; i <= txt.length() - target.length(); i++){
        string newOne = txt.substr(i, target.length()); //till 1 to 3
        // cout<<Anagram(target, newOne)<<" "; //prints  0-->false,   1-->true

        if (Anagram(target, newOne)){
            result.push_back(txt.substr(i, target.length()));
            
        }
        
    }

    for(string c: result){
        cout<<c<<" ";
    }

}
