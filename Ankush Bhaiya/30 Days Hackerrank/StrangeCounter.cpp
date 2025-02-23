#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'strangeCounter' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER t as parameter.
 */

long strangeCounter(long t) {
    /*
        timeStarting sequence : 1 4 10 22...  --> nest = (prev*2)+2
        value sequence   : 3 6 12 24...     --> next = prev*2
        
    Cycle	cycleStart	cycleValue	cycleEnd (cycleStart + cycleValue)
    1st	    1	            3	        4 (because it runs at times 1, 2, 3)
    2nd	    4	            6	        10 (runs at times 4, 5, 6, 7, 8, 9)
    3rd	    10              12	        22 (runs at times 10, 11, 12,..., 21)
        
    */
    
    long cycleStartTime =1;
    long cycleStartValue = 3;
        
    while (t>= cycleStartTime+cycleStartValue) {    //17>= 1+3 --> 17>=4+6 --> 17>=10+12 (false)
        // cout<<"Time "<< cycleStartTime<<endl;
        // cout<<"Value "<< cycleStartValue<<endl;
        
        cycleStartTime = cycleStartValue + cycleStartTime;  //4 --> 10
        cycleStartValue = cycleStartValue*2;    //6  --> 12
        
    }
    //return value according to time
    return cycleStartTime + cycleStartValue - t; //10+12-17 --> 5

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    long t = stol(ltrim(rtrim(t_temp)));

    long result = strangeCounter(t);

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
