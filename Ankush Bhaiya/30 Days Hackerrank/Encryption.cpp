#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end()); // Remove spaces
    
    int l = s.length();
    int row = floor(sqrt(l));
    int col = ceil(sqrt(l));
    
    cout<<"Length " <<l<<endl;
    
    
    string encrypted;
    for (int i=0; i<col; i++) { //iterate column wise
        for (int j=i ; j<l ; j+=col) {  //iterate over char in col, escaping col number in each iteratiom(j+=col)
            encrypted += s[j];
        
        }
        encrypted += " ";   //spacing b/w words

    }
    return encrypted;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
