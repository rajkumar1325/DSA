#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n -- length of password
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    

    bool hasDigit=false, hasLower=false, hasUpper=false, hasSpecial=false;
    int count=0; //counts how much more needed 
    
    
    // '\0'  :: termination cond as it measn null     
    for (int i=0; password[i] !='\0'; i++) {
        
        // has digit
        if (password[i]>='0' && password[i]<='9') {
            hasDigit = true;    
        }
        
        // has lowerCase
        else if (password[i]>='a' && password[i]<='z') {
            hasLower = true;
        }
        
        // has UpperCase
        else if (password[i]>='A' && password[i]<='Z') {
            hasUpper = true;
        }
        
        //checking special character
        else if (!((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (password[i] >= '0' && password[i] <= '9'))) {
            hasSpecial = true;
        }
    }
    
    
    if (!hasDigit) count++;
    if (!hasLower) count++;
    if (!hasUpper) count++;
    if (!hasSpecial) count++;
    
    
    return max(count, 6-n);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
