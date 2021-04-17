#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for(int& i : A) cin >> i;
    for(int& i : B) cin >> i;
    vector<int> C;
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
    for(int i : C) cout << i << ' ';
}