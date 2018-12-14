#include <iostream>
#include <fstream>
#include <tuple>

template<int Ind, class CharT, class Traits, class... Types> struct forEach {
    void printElement(std::basic_ostream<CharT, Traits>& os, std::tuple<Types...> const& t) {
        forEach<Ind - 1, CharT, Traits, Types...> prev;
        prev.printElement(os, t);
        os << std::get<Ind>(t) << " ";
    }
};

template<class CharT, class Traits, class... Types> struct forEach<0, CharT, Traits, Types...> {
    void printElement(std::basic_ostream<CharT, Traits>& os, std::tuple<Types...> const& t) {
        os << std::get<0>(t) << " ";
    }
};

template<class CharT, class Traits, class... Types> struct forEach<-1, CharT, Traits, Types...> {
    void printElement(std::basic_ostream<CharT, Traits>& os, std::tuple<Types...> const& t) {

    }
};

template <class CharT, class Traits, class... Types> auto& operator<<(std::basic_ostream<CharT, Traits>& os, std::tuple<Types...> const& t) {
    const int tupleSize = sizeof...(Types);
    forEach<tupleSize - 1, CharT, Traits, Types...> printer;
    printer.printElement(os, t);
    return os;
}

int main() {
    std::cout << std::make_tuple(1, "Test", 3.0) << std::endl;
    return 0;
}