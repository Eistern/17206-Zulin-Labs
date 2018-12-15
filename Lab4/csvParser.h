#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include "fstream"
#include "tuple"

template<class... Types> class CSVParser {
    std::ifstream &_fin;
    int _shift;
public:
    CSVParser(std::ifstream &fin, int shift) : _shift(shift), _fin(fin) {};

    class _ParserIterator {
        std::tuple<Types...> _out;
        template<int Ind> class StringParser {
            void parse() {

            }
        };
        template<> class StringParser<0> {
            void parse() {

            }
        };
    public:
        void operator++ () {

        };
        std::tuple<Types...> operator* () {
            const int tupleSize = sizeof... (Types);
            StringParser<tupleSize - 1> parser;
            parser.parse();
            return _out;
        };
        std::tuple<Types...>* operator-> () {

        };
    };
    _ParserIterator begin() {

    };
    _ParserIterator end() {

    };

    bool operator== (const _ParserIterator &first, const _ParserIterator &second) const {

    }
    bool operator!= (const _ParserIterator &first, const _ParserIterator &second) const {
        return !(first == second);
    }
};


#endif //LAB4_CSVPARSER_H