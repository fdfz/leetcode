#include <cstring>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <tuple>
#include <numeric>
#include <ranges>
#include <print>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> v{2,1};
    sort(v.begin(),v.end(),[](auto& a, auto& b){b=90;return a<b;});
    for(auto& i:v){
        print("{}",i);
    }
}
