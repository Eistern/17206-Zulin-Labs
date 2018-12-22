#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include "parserExceptions.h"

template<typename Type, int Ind, class... Types> struct _TuplePlacer {
    static void place(std::string &_buffString, std::tuple<Types...> &to) {
        std::stringstream _buffStream;
        _buffStream << _buffString;

        _buffStream >> std::get<Ind>(to);
        if (_buffStream.fail())
            throw columnFailure(Ind);
    }
};

template<int Ind, class... Types> struct _TuplePlacer<std::string, Ind, Types...> {
    static void place(std::string &_buffString, std::tuple<Types...> &to) {
        std::get<Ind>(to) = _buffString;
    }
};

template<int Ind, class... Types> struct _StringParser {
    void parse(char columnSep, std::stringstream &_fin, std::tuple<Types...> &to) {
        _StringParser<Ind - 1, Types...> prev;
        prev.parse(columnSep, _fin, to);

        std::string _buffString;
        std::getline(_fin, _buffString, columnSep);

        using currentType = typename std::tuple_element<Ind, std::tuple<Types...>>::type;
        _TuplePlacer<currentType, Ind, Types...>::place(_buffString, to);
    }
};
template<class... Types> struct _StringParser<0, Types...> {
    void parse(char columnSep, std::stringstream &_fin, std::tuple<Types...> &to) {
        std::string _buffString;
        std::getline(_fin, _buffString, columnSep);

        using currentType = typename std::tuple_element<0, std::tuple<Types...>>::type;
        _TuplePlacer<currentType, 0, Types...>::place(_buffString, to);
    }
};

template<class... Types> struct _StringParser<-1, Types...> {
    void parse(char columnSep, std::stringstream &_fin, std::tuple<Types...> &to) {

    }
};

template<class... Types> class CSVParser {
    std::ifstream &_fin;
    int _defaultShift;
    int _currentShift;
    char _columnSep;
    char _lineSep;
public:
    CSVParser(std::ifstream &fin, int shift, char column = ',', char line = '\n') :
        _defaultShift(shift), _fin(fin), _columnSep(column), _lineSep(line), _currentShift(shift) {};

    class _ParserIterator {
        int _shift;
        CSVParser *_parent;
        std::tuple<Types...> _current;
        char _columnSep;
        char _lineSep;

    public:
        _ParserIterator(int shift, CSVParser *creator, char column, char line) :
                        _columnSep(column), _lineSep(line), _shift(shift), _parent(creator) {
            if (_shift != -1 && !creator->_endOfStream())
                _tupleParse();
        };
        void operator++ () {
            if (_parent->_endOfStream()) {
                _shift = -1;
                return;
            }
            _shift++;
            _tupleParse();
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
            std::string _newLine = _parent->_getline(_shift, _lineSep);
            std::stringstream _nextLine;
            _nextLine << _newLine;
            try {
                parser.parse(_columnSep, _nextLine, _current);
            }
            catch (const columnFailure &num) {
                throw readFailure(num._columnNumber, _shift);
            }
        }
    };
    friend class _ParserIterator;

    _ParserIterator begin() {
        _fin.seekg(0, std::ios_base::beg);

        std::string buff;
        for (int i = 0; i < _defaultShift; i++)
            std::getline(_fin, buff);

        return _ParserIterator(_defaultShift, this, _columnSep, _lineSep);
    };

    _ParserIterator end() {
        return _ParserIterator(-1, this, _columnSep, _lineSep);
    };
private:
    bool _endOfStream() {
        return _fin.eof();
    }
    std::string _getline(int index, char lineSep) {
        if (index == -1)
            return "";

        std::string buff;
        if (index < _currentShift) {
            _fin.seekg(0, std::ios_base::beg);
            for (int i = 0; i <= index; i++)
                std::getline(_fin, buff, _lineSep);
            _currentShift = index + 1;
            return buff;
        } else {
            for (int i = 0; i <= index - _currentShift; i++)
                std::getline(_fin, buff, _lineSep);
            _currentShift = index + 1;
            return buff;
        }
    }
};



#endif //LAB4_CSVPARSER_H