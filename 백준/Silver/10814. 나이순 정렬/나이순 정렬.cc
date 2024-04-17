#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct People{
    int age;
    string pName;
};

int cmd_People(People p1,People p2){
    return p1.age < p2.age;
}

int main(){
    int N;
    cin>>N;
    vector <People> P;
    for(int i=0;i<N;i++){
        People tmp;
        cin>>tmp.age>>tmp.pName;
        P.push_back(tmp);
    }
    stable_sort(P.begin(),P.end(),cmd_People);
    for(int i=0;i<N;i++){
        cout<<P[i].age<<" "<<P[i].pName<<"\n";
    }
    return 0;
}