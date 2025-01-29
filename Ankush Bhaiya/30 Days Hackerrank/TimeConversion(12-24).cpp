#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    // 12:03:01PM   --> Total 10 character
    
    //substr(start, length)
    string hour = s.substr(0,2);    
    string min = s.substr(3,2);
    string sec = s.substr(6,2);
    string meridian = s.substr(8,2); // for AM or PM
    
    int hourInt = stoi(hour);//type-casting
    
    if (meridian == "AM" && hourInt==12) {
        hourInt = 00;    //reset
    }
    else if (meridian=="PM" && hourInt!=12) {    
        hourInt += 12;
    } 
        
    //If hour<10 --> add a leading zero to make it 2 digit.
    string hour24;
    if (hourInt < 10) {
        hour24 = "0" + to_string(hourInt);
    }
    else {
    hour24 = to_string(hourInt);
}

    return hour24 + ":" + min + ":" + sec; // Construct 24-hour format string
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
