#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "tuple"

template<int Ind, class... Types> struct _StringParser {
    void parse(const std::string &Separators, std::stringstream &_fin, std::tuple<Types...> &to) {
        _StringParser<Ind - 1, Types...> prev;
        prev.parse(Separators, _fin, to);

        std::stringstream _buffStream;
        char c = 0;

        if (!_fin.eof())
            _fin >> c;
        while (!_fin.eof() && strchr(Separators.c_str(), c) == nullptr) {
            _buffStream << c;
            _fin >> c;
        }
        _buffStream >> std::get<Ind>(to);
    }
};
template<class... Types> struct _StringParser<0, Types...> {
    void parse(const std::string &Separators, std::stringstream &_fin, std::tuple<Types...> &to) {
        std::stringstream _buffStream;
        char c = 0;

        if (!_fin.eof())
            _fin >> c;
        while (!_fin.eof() && strchr(Separators.c_str(), c) == nullptr) {
            _buffStream << c;
            _fin >> c;
        }
        _buffStream >> std::get<0>(to);
    }
};

template<class... Types> struct _StringParser<-1, Types...> {
    void parse(const std::string &Separators, std::stringstream &_fin, std::tuple<Types...> &to) {

    }
};

template<class... Types> class CSVParser {
    std::ifstream &_fin;
    int _shift;
    std::string _columnSep;
    std::string _lineSep;
public:
    CSVParser(std::ifstream &fin, int shift, std::string column = ",") :
        _shift(shift), _fin(fin), _columnSep(std::move(column)) {};

    class _ParserIterator {
        int _shift;
        CSVParser *_parent;
        std::ifstream &_fin;
        std::tuple<Types...> _current;
        std::string _columnSep;

    public:
        _ParserIterator(int shift, CSVParser *creator ,std::ifstream& src, std::string column = ",") :
                        _columnSep(std::move(column)), _shift(shift), _parent(creator), _fin(src) {
            if (!src.eof())
                _tupleParse();
        };
        void operator++ () {
            _tupleParse();

            _shift++;
            if (_fin.eof())
                _shift = -1;
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

            return _shift == second._shift;
        }

        bool operator != (const _ParserIterator &second) const {
            return !(*(this) == second);
        }
    private:
        void _tupleParse() {
            const int tupleLen = sizeof...(Types);

            _StringParser<tupleLen - 1, Types...> parser;
            std::string _newLine;
            std::getline(_fin, _newLine);
            std::stringstream _nextLine;
            _nextLine << _newLine;
            parser.parse(_columnSep, _nextLine, _current);
            _shift++;
            if (_fin.eof())
                _shift = -1;
        }
    };

    _ParserIterator begin() {
        std::ifstream &_finCopy = _fin;
        _finCopy.seekg(0, _finCopy.beg);

        std::string buff;
        for (int i = 0; i < _shift; i++)
            std::getline(_finCopy, buff);

        return _ParserIterator(_shift, this, _finCopy, _columnSep);
    };

    _ParserIterator end() {
        std::ifstream &_finCopy = _fin;
        _finCopy.seekg(0, _finCopy.end);
        return _ParserIterator(-1, this, _finCopy, _columnSep);
    };
};



#endif //LAB4_CSVPARSER_H