#include <iostream>
#include <fstream>
#include <tuple>

template <int Ind, class... Types> auto getValue(std::tuple<Types...> const& t) {
    return std::get<Ind>(t);
}

template <class CharT, class Traits, class... Types> auto operator<<(std::basic_ostream<CharT, Traits>& os, std::tuple<Types...> const& t) {
    int typesLength = sizeof...(Types);
    for (int i = 0; i < typesLength; ++i)
        const auto buff = std::get<i, Types...>(t);

    return os;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << std::make_tuple(1, "Lol", 3.0) << std::endl;
    return 0;
}