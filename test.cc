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
int main()
{
    for (auto i : views::iota(10)|views::take(3))
        print("{}", i);
    return 0;
}
