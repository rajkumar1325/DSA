#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
/*
1. Checks if the character is a letter (isalpha(c)).
2. Determines if it's uppercase or lowercase using isupper(c).
3. Computes the new character with modulo wrapping:
         c - a shifts the character to a 0-based index ('A' -> 0, 'B' -> 1, etc.).
        (c - a + k) % 26 shifts the index within the 26-letter range.
        a + shifts it back to its correct ASCII range.
4. Ignores non-alphabetic characters, leaving them unchanged.

*/
    
    
    for(char &c:s) {
       if(isalpha(c)){
           char a = isupper(c)? 'A':'a';
           c = a + (c - a + k) % 26;
       }
   }
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

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
