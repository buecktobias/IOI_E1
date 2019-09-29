#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
int main ( ) {
    int n ;
    cin >> n ;
    vector <long long> a (n) ;
    for(int i = 0 ; i < n ; i ++ ) cin >> a[i] ;



    vector<long long > p ;
    for(int i = 0 ; i < n ; i ++ ) {
        for(int j = 0 ; j < n ; j ++ ) {
            for(int k = 0 ; k < n ; k ++ ) {
                p.push_back(a[i]*a[j]*a[k]) ;
            }
        }
    }

    sort(p.begin(), p.end()) ;

    cout << p[p.size() - 1]<<endl;
    return 0 ;
}