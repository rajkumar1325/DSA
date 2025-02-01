#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    //1700 - 1917 --> Julian calender {leapYr = /4}
    //1918  --> feb14 was 32nd day.
    // >1918  --> Geoagorian calender  {leap yr =/400 || /4 && !/100}
    
/*
In simple
    yr==1918 --> 26sept
    yr<1918 --> check learYr --> yes 12sept  || no 13 sept
    yr>1918 --> check leapYr --> yes 12sept  || no 13 sept
*/

    if (year == 1918) {
        return "26.09."+ to_string(year);
    }   

// JULIAN CALENDER 
    else if(year<1918){
        if (year%4==0) {    //leap year
            return "12.09."+ to_string(year);
        }
        else{
            return "13.09."+ to_string(year);
        }
    }

// GEOAGORIAN CALENDER
    else if(year>1918){
        if (year%400==0 || (year%4==0 && year%100!=0)) {    //leap year
            return  "12.09."+to_string(year);
        }
        else{
            return "13.09."+ to_string(year);   
        }
    }
    return NULL;  //if year doesn't match any case --> return NULL
}
int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
