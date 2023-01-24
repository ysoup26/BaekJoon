
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char,int> word;
    string input;
    char max_k;
    bool isSame=false;
    
    cin>>input;
    //for to insert (map)word
    for(int i=0;i<input.length();i++)
    {
        char w=toupper(input[i]);
        word[w]++;
    }
    for(auto w:word)
	{
	    int max_v=word.find(max_k)->second;
	    if(max_v<w.second)
	    {
	        max_k=w.first;
	        isSame=false;
	    }else if(max_v==w.second)
	        isSame=true;   
	    //for문 종료시 isSame이 true라면 가장 많이 사용된 알파벳이 여러개,
	    //새로운 가장 많이 사용된 알파벳이 등장하면 isSame을 false
	} 
    if(isSame)
        max_k='?';
    cout<<max_k;
    return 0;
}
