#pragma once

#include <string>
#include <iostream>
#include <vector>

class PyString : public std::string
{
private:
    std::string _char_to_charptr(char c) { char C[1] = { c }; return std::string(C); }

public:
    // Constructors
    PyString() : std::string() {};
    PyString(const PyString& s) : std::string(s) {};
    PyString(const PyString* s) : std::string(*s) {};
    PyString(const std::string& s) : std::string(s) {};
    PyString(const std::string* s) : std::string(*s) {};
    PyString(char* c) : std::string(c) {};
    PyString(char c) : std::string(_char_to_charptr(c)) {};

    // Python functions
    std::vector<PyString> split(PyString ToFind = " ", int MaxSplit = -1); // Need a split function that is "OR" instead of "AND".
    std::vector<PyString> rsplit(PyString ToFind = " ", int MaxSplit = -1);
    PyString strip(PyString ToStrip = "\n\t\r ");
    char index(int i) { return i >= 0 ? std::string::operator[](i) : std::string::operator[](this->length() - 1); }
    PyString lower();
    PyString upper();
    PyString join(PyString*, uint64_t size);
    PyString join(std::vector<PyString> vec) { return this->join(&vec[0], vec.size()); }
    bool startswith(PyString Start);
    bool endswith(PyString End);

    // Convertors
    operator std::string() { return *this; }
    operator const char* () { return this->c_str(); }

    // Operators
    char operator[](int i) { return index(i); }
    
};