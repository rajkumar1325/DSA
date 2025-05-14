// Find the longest substring without repeating character (USING SLIDING WINDOW)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string name = "abcdeadfsg";
    vector<bool> count(256,false); //initialise 256 size array with all elements false --> total ASCII = 256
    int first =0, second =0;

    int length =0;
    while (second< name.size()){
        while (count[name[second]]){ //Repeating characters found
            count[name[first]] = false;
            first++;
        }
        count[name[second]] = true;
        
        length = max(length, (second-first+1));
        second++;
    }
    cout<< length;
}

/*
while (count[name[second]])

        if second is at d --> at index 3
        name[second] = d
        count[name[second]] --> go to the array and count[ASCII-of-d] --> let say 45 --> it makes 45--true;
                        --> It means this character is seen 
*/
