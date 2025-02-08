#include <iostream>
using namespace std;

// PASS BY VALUE 
// Any changes made inside the function do not affect the original n in main().
// Pass-by-value (int a) --> Original variable remains unchanged.
/*
int increment(int a){
    a++;
    cout<<"The inner value "<< a<<endl;
    return a;
}
int main(){
    int n=5;
    increment(n);   //can't able to update this n
    cout<<n;

}
*/


//PASS BY REFERENCE.
// Pass-by-reference (int &a) --> Original variable gets modified.
/*
int increment(int &a){
    a++;
    cout<<"The inner value "<< a<<endl;
    return a;
}
int main(){
    int n=5;
    increment(n);   //can't able to update this n
    cout<<n;

}
*/


// ------------------------------SWAPPING EXAMPLE-------------------------------


//USING CALL BY VALUE
/*
#include<iostream>
using namespace std;
void swap(int p, int q){
    int temp;
    temp = p;
    p =q;
    q = temp;
    cout<<"Value after swap "<<p<<q <<endl;

}
int main(){
    int a=5, b=7;
    cout<<"Value before swap "<<a<<b <<endl;
    swap(a,b);
    cout<<"Value after swap "<<a<<b <<endl;
}
*/


// USING CALL BY REFERENCE

#include<iostream>
using namespace std;
void swap(int &p, int &q){
    int temp;
    temp = p;
    p =q;
    q = temp;
}
int main(){
    int a=5, b=7;
    cout<<"Value before swap "<<a<<b <<endl;
    swap(a,b);
    cout<<"Value after swap "<<a<<b <<endl;
}
