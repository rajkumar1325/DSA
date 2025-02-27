#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */

int gemstones(vector<string> arr) {
    unordered_map<int, int>freq;
    
    for (string name : arr) {  // Iterate over each string
        unordered_set<char> uniqChar; 
        
        for (char ch : name) { // Iterate over subString
            uniqChar.insert(ch); //stores unique character only.
        }
        
        // // printing / debugging
        // cout<<"printing only unique char inside the array"<<endl;
        // for(char c: uniqChar){
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        
        
        // Update frequency count (only once per string)
        for (char ch : uniqChar) {
            freq[ch]++;
        }
    }

    int count = 0;
    for (auto n : freq) {
        if (n.second == arr.size()) { // If character appears in all strings
            count++;
        }
    }   
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

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
