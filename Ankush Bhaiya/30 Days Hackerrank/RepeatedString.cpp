#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */


/*
            Approach
    1. find the perfect total number of repeatation
    2. find the remaining character repeatation
    3. add total + remainder.
*/
long repeatedString(string s, long n) {
    
    int count =0;
    //counting number of 'a' inside given string
    for(size_t i : s){
        if (i =='a') {
            count++;
        }
    }
    cout<<"The numbr of a inside string is "<<count<<endl;
    
    //Finding total perfect repeatation
    int arraySize = s.length();
    cout<<"length " <<s.length();
    
    long perfectRepeat = n/arraySize; //perfect repeatation
    cout<<"Total perfect repeatation "<<perfectRepeat<<endl;
    
    long remainder = n%arraySize;
    cout<<"remainder "<<remainder<<endl;
    
    //checking if character is 'a' or not?
    int remainderCount=0;
    for (int i=0; i<remainder; i++) {
        if (s[i] == 'a') {
            remainderCount++;
        }
    }
    cout<<"Remainder Count "<<remainderCount<<endl;
    
    
return (count*perfectRepeat)+remainderCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

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
