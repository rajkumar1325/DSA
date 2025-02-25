#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int count =0;
    int smsLength = 3; //given
    int totalSmsReceived = s.length()/smsLength;
    cout<<"Total number of sms received "<<totalSmsReceived<<endl;
    
    for (int i =0; i<s.length(); i++) {

        if (i%3==0 && s[i]!='S') count++; //checks 1st character
        if (i%3==1 && s[i]!='O') count++; //checks 2nd character
        if (i%3==2 && s[i]!='S') count++; //checks 3rd character

    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
