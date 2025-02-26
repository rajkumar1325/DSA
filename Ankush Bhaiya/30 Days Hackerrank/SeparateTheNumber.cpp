#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
int len = s.length();

    for (int i = 1; i <= len / 2; i++) { 
        string firstNum = s.substr(0, i); // Extract first number

        // Skip leading zeros (except single "0")
        if (firstNum[0] == '0' && firstNum != "0") continue;

        long long num = stoll(firstNum); // Convert to integer
        string seq = firstNum; // Start forming sequence

        // Build sequence dynamically
        while (seq.length() < len) {
            seq += to_string(++num);
        }

        // Check if the built sequence matches the input
        if (seq == s) {
            cout << "YES " << firstNum << endl;
            return;
        }
    }

    cout << "NO" << endl; // No valid sequence found
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
