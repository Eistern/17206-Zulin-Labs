#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include <string>
#include <fstream>
#include "tuple"

template<class... Types> class CSVParser {
    std::ifstream &_fin;
    int _shift;
public:
    CSVParser(std::ifstream &fin, int shift) : _shift(shift), _fin(fin) {};

    class _ParserIterator {
        CSVParser *_parent;
        std::ifstream &_fin;
        std::tuple<Types...> _current;

        template<int Ind> struct _StringParser {
            void parse(std::tuple<Types...>& to, std::ifstream &_fin) {
                _StringParser<Ind - 1> prev;
                prev.parse(to, _fin);

                _fin >> std::get<Ind>(to);
            }
        };
        template<> struct _StringParser<0> {
            void parse(std::tuple<Types...>& to, std::ifstream &_fin) {
                _fin >> std::get<0>(to);
            }
        };
    public:
        _ParserIterator(CSVParser *creator ,std::ifstream& src) :_parent(creator), _fin(src) {
            if (!src.eof()) {
                const int tupleLen = sizeof...(Types);

                _StringParser<tupleLen - 1> parser;
                parser.parse(_current, tupleLen);
            }
        };
        void operator++ () {
            const int tupleLen = sizeof...(Types);

            _StringParser<tupleLen - 1> parser;
            parser.parse(_current, tupleLen);
        };
        std::tuple<Types...> operator* () {
            return _current;
        };
        std::tuple<Types...>* operator-> () {
            return &(_current);
        };
        bool operator== (const _ParserIterator &second) const {
            if (_parent != second._parent)
                return false;

            std::ifstream &firstCopy = _fin;
            std::ifstream &secondCopy = second._fin;
            char firstBuff, secondBuff;

            while (!firstCopy.eof() && !secondCopy.eof()) {
                firstCopy >> firstBuff;
                secondCopy >> secondBuff;
            }

            return firstCopy.eof() && secondCopy.eof();
        }

        bool operator != (const _ParserIterator &second) const {
            return !(*(this) == second);
        }
    };

    _ParserIterator begin() {
        std::ifstream &_finCopy = _fin;
        _finCopy.seekg(0, _finCopy.beg);

        std::string buff;
        for (int i = 0; i < _shift; i++)
            std::getline(_finCopy, buff);

        return _ParserIterator(this, _finCopy);
    };
    _ParserIterator end() {
        std::ifstream &_finCopy = _fin;
        _finCopy.seekg(0, _finCopy.end);
        return _ParserIterator(this, _finCopy);
    };
};


#endif //LAB4_CSVPARSER_H