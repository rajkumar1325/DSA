#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

/*
    5 3      -->  N = 5 (Board size), K = 3 (Number of obstacles)
    4 3      -->  Queen's position at (Row = 4, Column = 3)
    5 5      -->  Obstacle at (Row = 5, Column = 5)
    4 2      -->  Obstacle at (Row = 4, Column = 2)
    2 3      -->  Obstacle at (Row = 2, Column = 3)
*/

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Step 1: Store obstacles in a set for quick lookup
    set<pair<int, int>> obs;
    for (auto ob : obstacles) {
        obs.insert({ob[0], ob[1]});
    }

    int count = 0; // Stores the number of attackable squares

    // Step 2: Define 8 possible movement directions for the queen
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0},  // Vertical (up, down)
        {0, 1}, {0, -1},  // Horizontal (right, left)
        {1, 1}, {1, -1},  // Diagonal (right_down, left_down)
        {-1, 1}, {-1, -1} // Diagonal (right-up, left-up)
    };

    // Step 3: Move in each direction until we hit an obstacle or the board's boundary
    for (auto dir : directions) {
        int r = r_q + dir.first, c = c_q + dir.second; // Start moving in the direction

        // Continue moving while within the board and no obstacle encountered
        while (r >= 1 && r <= n && c >= 1 && c <= n && obs.find({r, c}) == obs.end()) {
            count++; // Increment attackable squares
            r += dir.first; // Move further in the same direction
            c += dir.second;
        }
    }

    return count; // Return total attackable squares
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
