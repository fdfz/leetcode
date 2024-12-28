#include <cstring>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <tuple>
#include <numeric>
#include <ranges>
#include <print>
using namespace std;
void f(vector<int> &v){
    v.push_back(1);
}
int main()
{
    vector<int> v;
    f(v);
    print("{}",v.empty());
    return 0;
}
