#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    unordered_set<char> alphabet;  //contains distinct element only
    
    for (char ch : s) {
        if (isalpha(ch)) {  //if alphabet found insert it into set
            alphabet.insert(tolower(ch)); //convert into lowercase, b/c set treats upper and lowercase different, as It misleads the count.
        }
    }
    
    if (alphabet.size() == 26) {
        cout<<"size"<<alphabet.size();
        return "pangram";
    }

    return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
