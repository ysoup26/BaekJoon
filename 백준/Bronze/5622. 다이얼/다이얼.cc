
#include <iostream>

using namespace std;

int main()
{
    string word;
    int t=0;
    cin>>word;
    for(int i=0;i<word.length();i++)
    {
        char w=word[i];
        t+=1;
        if(w=='A'||w=='B'||w=='C')
            t+=2;
        else if(w=='D'||w=='E'||w=='F')
            t+=3;
        else if(w=='G'||w=='H'||w=='I')
            t+=4;
        else if(w=='J'||w=='K'||w=='L')
            t+=5;
        else if(w=='M'||w=='N'||w=='O')
            t+=6;
        else if(w=='P'||w=='Q'||w=='R'||w=='S')
            t+=7;
        else if(w=='T'||w=='U'||w=='V')
            t+=8;
        else if(w=='W'||w=='X'||w=='Y'||w=='Z')
            t+=9;
        else
            t+=10;
    }
    cout<<t;
    return 0;
}