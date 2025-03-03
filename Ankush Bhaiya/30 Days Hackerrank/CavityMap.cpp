#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'cavityMap' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY grid as parameter.
 */

vector<string> cavityMap(vector<string> grid) {
    
    int n = grid.size()-1;
    for (int i=1; i<n; i++){ 
        
        for (int j=1; j<n; j++) {
            
            // grid[i-1][j] --> The cell above.
            // grid[i+1][j] --> The cell below.
            // grid[i][j-1] --> The cell to the left.
            // grid[i][j+1] --> The cell to the right.
            // If grid[i][j] is greater than all four, it means this cell is a cavity, so we replace it with 'X'.
            
            if (grid[i][j] > grid[i][j-1] && grid[i][j] > grid[i][j+1] && grid[i][j] > grid[i-1][j] && grid[i][j] > grid[i+1][j]) {
                    grid[i][j] = 'X';  // Replace with 'X'
                }
            
        }
        cout << endl;
    }
    
    
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
