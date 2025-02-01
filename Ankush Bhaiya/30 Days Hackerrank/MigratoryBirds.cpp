#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    vector<int> frequency(10); // Array to store counts
    
    // Count each bird occurrences.     eg: 1st bird --> 3 times. therefore == 3
    for (int bird : arr) {
        frequency[bird]++;
    }
/*
Bird        freq-updates
    
1    frequency[1]++  [0, 1, 0, 0, 0, 0]
4    frequency[4]++  [0, 1, 0, 0, 1, 0]
4    frequency[4]++  [0, 1, 0, 0, 2, 0]
4    frequency[4]++  [0, 1, 0, 0, 3, 0]
5    frequency[5]++  [0, 1, 0, 0, 3, 1]
3    frequency[3]++  [0, 1, 0, 1, 3, 1]
*/

    // Find the bird type with the highest frequency
    int maxFreq = 0, result =0;
    
    for (int i = 1; i<frequency.size(); i++){ 
        if (frequency[i] > maxFreq) {
            maxFreq = frequency[i];
            result = i; //indexing is the result
        }
    }
    return result;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
