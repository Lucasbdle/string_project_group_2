#include "string.h"

//default constructor
String::String(){
    str = new char[1];
    str[0] = '\0';
}

// copy constructor
String::String(const String& other){
    if(other.str == nullptr) {
        this->str = nullptr;
    } else {
        size_t length = other.length();
        this->str = new char[length + 1];
        for (size_t i = 0; i <= length; ++i) {
            this->str[i] = other.str[i];
        }
    }    
}

// constructor from a c-string
String::String(char* strcopy){
    size_t len = 0;

    // Loop until the null terminator is encountered
    while (strcopy[len] != '\0') {
        ++len;
    }

    this->str = new char[len];
    

}

// destructor
String::~String(){
    delete[] str;
}

// Getter
char* String::getStr(){
    return str;
}

// length
size_t String::length() const{
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}


