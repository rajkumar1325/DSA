#include<iostream>
using namespace std;

// PRINTING NUMBER MATRIX IN INCREASING ORDER 
int main(){
    int number =3;
    // cout<<"Enter your number";
    // cin >> number;
    int sum =1;
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            cout<<sum << " ";
            sum++;
        }
        cout<<endl;    
    }
    
}
