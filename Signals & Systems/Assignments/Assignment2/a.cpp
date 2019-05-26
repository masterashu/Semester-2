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
#define NL cout << '' 
#define ListInput(arr,n) For(i,n){ cin >> arr[i]; }
#define MatInput(arr, n, m) For(j,n){ ListInput(arr[i],m) }
#define MOD 1000000007
using namespace std;

void fn(int &x){
    x = 15;
}

int main(int argc, const char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x= 10;
    fn(x);
    cout << x;
    return 0;
}