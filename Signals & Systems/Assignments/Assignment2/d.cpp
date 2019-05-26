#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define For(i,n) for(int i = 0; i < n; i++)
#define ForI(i,n) for(int i = 1; i <= n; i++)
#define ll long long
#define V(a) vector<a>
#define List(a) vector<a>
#define Mat(a) vector<vector<a>>
#define NL cout << '\n' 
#define ListInput(arr,n) For(i,n){ cin >> arr[i]; }
#define MatInput(arr, n, m) For(j,n){ ListInput(arr[i],m) }
#define MOD 1000000007
using namespace std;

ll FIBO[10000] = {0};
//  [0 , 1, -1, -1, -1, -1, -1, ...]


ll fib2(ll n){
    if(FIBO[n] == -1){
        if(FIBO[n-1] == -1)
            FIBO[n-1] = fib2(n-1);
        if(FIBO[n-2] == -1)
            FIBO[n-2] = fib2(n-2);
        FIBO[n] = FIBO[n-1] + FIBO[n-2];
        return FIBO[n];
    }
    else{
        return FIBO[n];
    }
}

int main(int argc, const char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i,10000){
        FIBO[i] = -1;
    }
    FIBO[0] = 0;
    FIBO[1] = 1;
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cout << fib2(i) << '\n';
    } 

    return 0;
}