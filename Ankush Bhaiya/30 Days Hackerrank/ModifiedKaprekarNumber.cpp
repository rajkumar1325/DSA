#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p --> lowest range
 *  2. INTEGER q --> upper range
 */

void kaprekarNumbers(int p, int q) {
    vector<int> krapster;
    long square;
    for (long i=p; i<=q; i++) {
        square = i*i;
        string str = to_string(square);   //convert into string
        
        int diff = to_string(i).length();
        
        
        // splitting
        string left = str.substr(0, str.length() - diff); // Left part
        string right = str.substr(str.length() - diff);   // Right part
        
        //If left is an empty string (for 1, where 1^2 = 1), stoi(left) will cause an error.
        int num1 = (left.empty()) ? 0 : stoi(left); //convert only if not empty.
        int num2 = stoi(right);
        
        if (num1+num2 == i) {
            krapster.push_back(i);
        }
        
    }
    
    if (krapster.empty()) {
        cout<< "INVALID RANGE";
        return;
    }
    
    //printing the array
    for (int i=0; i<krapster.size(); i++) {
        cout<<krapster[i]<<" ";
    }
    
    
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
