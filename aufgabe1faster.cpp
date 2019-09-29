#include<iostream>
#include<vector>

using namespace std;

int aufgabe1(){
    int n ;
    cin >> n ;
    vector <long long> a (n) ;
    for(int i = 0 ; i < n ; i ++ ) cin >> a[i] ;
    vector<long long > p;

    long biggestNumber = p[0];
    for(long long i : p){
        if(i > biggestNumber){
            biggestNumber = i;
        }
    }
    cout << biggestNumber*biggestNumber*biggestNumber << endl;
    return 0;
}