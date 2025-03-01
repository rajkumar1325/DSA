#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
// Approach : 
// --> split the string
// --> use a hashmap to strore frequency 
// --> reduce the frequency if element found in second hashmap 
// --> count the remaining frequency

    int count=0;
    
    // for string which cant be splitted into half
    if(s.length()%2!=0) return -1;
    
    // spllitting
    int mid = s.length()/2;
    string left = s.substr(0,mid);
    string right = s.substr(mid, s.length()-1);
    
    // frequency count
    unordered_map<char, int> freq;
    
    // increment the frequency count
    for(char c : left){
        freq[c]++;
    }
    
    // decreemt the freq count
    for(char ch: right){
        if(freq[ch]>0){
            freq[ch]--;
        }
    }
    
    // counting the remaining freqency 
    for(auto x: freq){
        count += x.second;
    }
    cout<<"count "<<count;
    
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
