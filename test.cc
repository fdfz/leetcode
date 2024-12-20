#include <vector>
#include <iostream>
#include<cmath>
#include<algorithm>
#include<ranges>
using namespace std;
int main(){
    vector<int> v;
    min(v.begin(),v.end());
    cout<<(v.begin()==v.end());
    return 0;
}