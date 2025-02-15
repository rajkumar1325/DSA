#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    int commonLength =0;
    for (int i=0; i<min(s.length(),t.length()); i++) {
        if (s[i]==t[i]) {
            commonLength++; 
        }
        else {break;}
    }
    cout<<"Common length: "<<commonLength<<endl; 
    
    int remain_s_Length = s.length()-commonLength; //5
    cout<<"Remaining s length "<<remain_s_Length<<endl;
    
    int remain_t_Length = t.length()-commonLength; //4
    cout<<"Remaining Length of t "<<remain_t_Length<<endl;
    
    int totalRequiredOper = remain_s_Length+remain_t_Length; 
    cout<<"Required Operation "<<totalRequiredOper<<endl; 
    
    /*
    Why Do We Check (k - totalRequiredOper) % 2 == 0?
If the required number of operations (totalRequiredOper) is less than k, we need to check whether we can use up the remaining operations in a valid way. The key idea is that you can only "waste" operations by doing pairs of operations (delete and re-add a character), which means the extra operations must be even.
    */
    
    
/*
* We only allow exact transformations.
* We only allow "waste" moves if k - totalRequiredOper is even.
* If k is large enough to delete and fully rebuild, return "Yes".
*/    
if (totalRequiredOper == k ||
    (totalRequiredOper < k && (k - totalRequiredOper) % 2 == 0) ||
    (s.length() + t.length() <= k)) 
    {
        return "Yes";
    }
    else{
        return "No";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

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
