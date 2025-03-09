#include <iostream>
using namespace std;

int main(){
    int number = 6; 
    char ch = 'A'; //CREATING A STARTING VARIABLE

    for (int c = 0; c <= number && ch<='Z'; c++)
    {
        for (int a = 0; a <= number && ch<= 'Z'; a++)
        {
            cout << ch << " ";
            ch++;
            // RESETTING THE ALPHABET
            if (ch > 'Z')
            {
                ch = 'A';
            }
            
        }
        cout << endl;
    }
    return 0;
}
