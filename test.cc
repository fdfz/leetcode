#include<cstring>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include<tuple>
#include<numeric>
using namespace std;
int main() {
    vector<int> v(10);
    iota(v.begin(),v.end(),0);
    for(const auto& e:v){
        cout<<e<<" ";
    }
    return 0;
}
