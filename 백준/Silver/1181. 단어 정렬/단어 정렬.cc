#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int cmd_str(string s1,string s2){
    if(s1.length() == s2.length()) //단어 길이가 같을땐 사전비교
        return s1 < s2;
    return s1.length() < s2.length();
}


int main(){
    int N;
    cin>>N;
    vector<string> arr;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end(),cmd_str);
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=arr[i+1])
            cout<<arr[i]<<"\n";
    }
    return 0;
}