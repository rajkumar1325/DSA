#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    unordered_map<char, int> freqCount;
    bool emptySpace = false;
    
    for (auto n : b) {
        if (n == '_') { //if empty space is present
            emptySpace = true;
        }
        else {
            freqCount[n]++; //count frequency
        
        }
    }
    
    // If any ladybug appears only once, they can never be happy
    for (auto x : freqCount) {
        if (x.second == 1) {  
            return "NO";
        }
    }
    
    //if space is +nt then It can be arranged and be happy.
    if (emptySpace) {
        return "YES";
    }
    
    
    //checking both adjacent side for if it already happy
    for (int i=1; i<b.length()-1; i++) {
        if (b[i]!=b[i+1]&& b[i]!=b[i-1]) {  //if both side are not same
            return "NO";
        }
    }   
    return "YES";   //if adjacent side have same then it is happy
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

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
