#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include <fstream>
#include <sstream>
#include <string>
#include "tuple"

template<int Ind, class... Types> struct _StringParser {
    void parse(char columnSep, std::stringstream &_fin, std::tuple<Types...> &to) {
        _StringParser<Ind - 1, Types...> prev;
        prev.parse(columnSep, _fin, to);

        std::stringstream _buffStream;
        std::string _buffString;
        std::getline(_fin, _buffString, columnSep);
        _buffStream << _buffString;

        _buffStream >> std::get<Ind>(to);
    }
};
template<class... Types> struct _StringParser<0, Types...> {
    void parse(char columnSep, std::stringstream &_fin, std::tuple<Types...> &to) {
        std::stringstream _buffStream;
        std::string _buffString;
        std::getline(_fin, _buffString, columnSep);
        _buffStream << _buffString;

        _buffStream >> std::get<0>(to);
    }
};

template<class... Types> struct _StringParser<-1, Types...> {
    void parse(char columnSep, std::stringstream &_fin, std::tuple<Types...> &to) {

    }
};

template<class... Types> class CSVParser {
    std::ifstream &_fin;
    int _shift;
    char _columnSep;
    char _lineSep;
public:
    CSVParser(std::ifstream &fin, int shift, char column = ',', char line = '\n') :
        _shift(shift), _fin(fin), _columnSep(column), _lineSep(line) {};

    class _ParserIterator {
        int _shift;
        CSVParser *_parent;
        std::ifstream &_fin;
        std::tuple<Types...> _current;
        char _columnSep;
        char _lineSep;

    public:
        _ParserIterator(int shift, CSVParser *creator ,std::ifstream& src, char column = ',', char line = '\n') :
                        _columnSep(column), _lineSep(line), _shift(shift), _parent(creator), _fin(src) {
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
            std::getline(_fin, _newLine, _lineSep);
            std::stringstream _nextLine;
            _nextLine << _newLine;
            parser.parse(_columnSep, _nextLine, _current);
        }
    };

    _ParserIterator begin() {
        std::ifstream &_finCopy = _fin;
        _finCopy.seekg(0, _finCopy.beg);

        std::string buff;
        for (int i = 0; i < _shift; i++)
            std::getline(_finCopy, buff);

        return _ParserIterator(_shift, this, _finCopy, _columnSep, _lineSep);
    };

    _ParserIterator end() {
        std::ifstream &_finCopy = _fin;
        _finCopy.seekg(0, _finCopy.end);
        return _ParserIterator(-1, this, _finCopy, _columnSep, _lineSep);
    };
};



#endif //LAB4_CSVPARSER_H