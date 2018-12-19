#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include <string>
#include <fstream>
#include "tuple"

template<int Ind, class... Types> struct _StringParser {
    void parse(std::ifstream &_fin, std::tuple<Types...> &to) {
        _StringParser<Ind - 1, Types...> prev;
        prev.parse(_fin, to);

        _fin >> std::get<Ind>(to);
    }
};
template<class... Types> struct _StringParser<0, Types...> {
    void parse(std::ifstream &_fin, std::tuple<Types...> &to) {
        _fin >> std::get<0>(to);
    }
};

template<class... Types> struct _StringParser<-1, Types...> {
    void parse(std::ifstream &_fin, std::tuple<Types...> &to) {
        _fin >> std::get<0>(to);
    }
};

template<class... Types> class CSVParser {
    std::ifstream &_fin;
    int _shift;
public:
    CSVParser(std::ifstream &fin, int shift) : _shift(shift), _fin(fin) {};

    class _ParserIterator {
        CSVParser *_parent;
        std::ifstream &_fin;
        std::tuple<Types...> _current;

    public:
        _ParserIterator(CSVParser *creator ,std::ifstream& src) :_parent(creator), _fin(src) {
            if (!src.eof()) {
                const int tupleLen = sizeof...(Types);

                _StringParser<tupleLen - 1, Types...> parser;
                parser.parse(_fin, _current);
            }
        };
        void operator++ () {
            const int tupleLen = sizeof...(Types);

            _StringParser<tupleLen - 1, Types...> parser;
            parser.parse(_fin, _current);
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
            int cur1 = _fin.seekg(0, _fin.cur).tellg();
            int cur2 = second._fin.seekg(0, second._fin.cur).tellg();
            return cur1 == cur2;
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