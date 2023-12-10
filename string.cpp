#include "string.h"

//default constructor
String::String(){
    c_str_ = new char[1];
    c_str_[0] = '\0';
}

// copy constructor
String::String(const String& other){
    if(other.c_str() == nullptr) {
        c_str_ = nullptr;
    } else {
        size_t length = other.length();
        c_str_ = new char[length + 1];
        for (size_t i = 0; i <= length; ++i) {
            c_str_[i] = other.c_str()[i];
        }
    }    
}

// constructor from a c-string
String::String(char* strcopy){
    size_t len = 0;

    // loop until the null terminator is encountered
    while (strcopy[len] != '\0') {
        ++len;
    }

    if(len > MAX_LENGTH){
        // if the string is too long, print an error message and create an empty string
        std::cout << "Could not copy  " << strcopy << ". " << std::endl;
        std::cout << "The length of the c-string is too long! len = " << len << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        
        c_str_ = new char[1];
        c_str_[0] = '\0';

        std::cout << "An empty string was constructed instead" << std::endl;

    } else {
        // allocate memory
         c_str_ = new char[len + 1];
        // copy into the string
        for (size_t i = 0; i < len; ++i) {
            c_str_[i] = strcopy[i];
        }
        c_str_[len] = '\0';
    }

}

// destructor
String::~String(){
    delete[] c_str_;
}

// getter
const char* String::c_str() const{
    return c_str_;
}

// length
size_t String::length() const{
    size_t length = 0;
    // loop until the null terminator is encountered
    while (c_str_[length] != '\0') {
        ++length;
    }
    return length;
}

// size of allocated storage in bytes
size_t String::capacity() const{
    return (this->length() + 1) * sizeof(char); // size of char is one byte (* 1)
}

// length of the string, in terms of bytes
size_t String::size() const{
    return this->length() * sizeof(char); // size of char is one byte (* 1)
}

// maximum length the string can reach.
size_t String::max_size() const{
    return MAX_LENGTH;
}

// is the string empty?
bool String::empty() const {
    return this->length() == 0;
}

// erases the contents of the string, which becomes an empty string 
void String::clear(){
    delete[] c_str_;
    c_str_ = new char[1];
    c_str_[0] = '\0';
}

// resizes the string to a length of n characters
void String::resize(size_t n, char c = '\0') {

    if (n < this->length()) {
        // if n is smaller than the current size, make the string shorter
        c_str_[n] = '\0';
    } else if (n > this->length()) {
        // If n is greater than the current size, expand the string
        char* newStr = new char[n + 1];  // +1 for null terminator

        // copy into the new string
        for (size_t i = 0; i < this->length(); ++i) {
            newStr[i] = c_str_[i];
        }

        // fill the newly added space with the specified c or null character
        for (size_t i = this->length(); i < n; ++i) {
            newStr[i] = c;
        }

        // string becomes new string
        newStr[n] = '\0';
        delete[] c_str_;
        c_str_ = newStr;
    } else if (n > MAX_LENGTH){
        // if n is bigger than the authorized MAX_LENGTH print an error
        std::cout << "Resizing the string was not possible! n = " << n << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
    }
}

// request a change in capacity
void String::reserve(size_t n = 0){
    if (n > capacity()) {
        // if n is greater than the current capacity, increase the capacity
        char* newStr = new char[n + 1];  // +1 for null terminator

        // copy into the new string
        for (size_t i = 0; i < this->length(); ++i) {
            newStr[i] = c_str_[i];
        }

        // string becomes new string
        newStr[this->length()] = '\0'; 
        delete[] c_str_;
        c_str_ = newStr;
    } if (n > MAX_LENGTH){
        // if n is bigger than the authorized MAX_LENGTH print an error
        std::cout << "Resizing the string was not possible! n = " << n << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        return;
    }
}

// operator= functions

// the string is set to a single copy of character c
String& String::operator= (char c){
    clear();

    // allocate new storage for the character
    c_str_ = new char[2];
    c_str_[0] = c;
    c_str_[1] = '\0';
    return *this;

}

// the string is set to a copy of the c-string from String str
String& String::operator= (const String& str){
    clear();

    size_t len = str.length();

    //allocate memory
    c_str_ = new char[len + 1]; // +1 for null terminator
    // copy into the string
    for (size_t i = 0; i < len; ++i) {
        c_str_[i] = str.c_str()[i];
    }
    c_str_[len] = '\0';

    return *this;
}

// the string is set to a copy of c-string s
String& String::operator= (const char* s){
    clear();

    size_t len = 0;

    // loop until the null terminator is encountered
    while (s[len] != '\0') {
        ++len;
    }

    if(len > MAX_LENGTH){
        // if the string is too long, print an error message and create an empty string
        std::cout << "Could not copy  " << s << ". " << std::endl;
        std::cout << "The length of the c-string is too long! len = " << len << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        std::cout << "An empty string was constructed instead" << std::endl; // this was done in the clear() function

    } else {

        //allocate memory
        c_str_ = new char[len + 1]; // +1 for null terminator
        // copy into the string
        for (size_t i = 0; i < len; ++i) {
            c_str_[i] = s[i];
        }
        c_str_[len] = '\0';
    }

    return *this;
}

// operator+ functions
// Return a newly constructed string object with its value being 
// the concatenation of the characters in lhs followed by those of rhs.

// For some reason VS Code does not want me to name the functions operator+()
// Used operator_plus() instead

// concatenates a c-string from object lhs and a c-string rhs
String String::operator_plus (const String& lhs, const char* rhs){
    size_t lhsLen = lhs.length();

    size_t rhsLen = 0;

    // loop until the null terminator is encountered
    while (rhs[rhsLen] != '\0') {
        ++rhsLen;
    }

    if(lhsLen + rhsLen > MAX_LENGTH){
         // if the constructed string object would be too long, print an error message and use default constructor
        std::cout << "Could not concatenate " << lhs.c_str() << " and " << rhs << std::endl;
        std::cout << "The length  is too long! Together they have length " << lhsLen + rhsLen << ". That exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        std::cout << "The default constructor was called instead!" << std::endl; // this was done in the clear() function
        return String();
    }

    char* resultStr = new char[lhsLen + rhsLen + 1];  // +1 for null terminator

    // copy characters from lhs
    for (size_t i = 0; i < lhsLen; ++i) {
        resultStr[i] = lhs.c_str()[i];
    }

    // copy characters from rhs
    for (size_t i = 0; i < rhsLen; ++i) {
        resultStr[lhsLen + i] = rhs[i];
    }
    resultStr[lhsLen + rhsLen] = '\0';

    return String(resultStr);
}

// concatenates a c-string from object str and a character c
String String::operator_plus (const String& str, char c){
    size_t len = str.length();

    if(len + 1 > MAX_LENGTH){
         // if the constructed string object would be too long, print an error message and use default constructor
        std::cout << "Could not concatenate " << str.c_str() << " with " << c << std::endl;
        std::cout << "The length  is too long! Together they have length " << len + 1 << ". That exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        std::cout << "The default constructor was called instead!" << std::endl; // this was done in the clear() function
        return String();
    }

    char* resultStr = new char[len + 2];  // +1 for null terminator

    // copy characters from lhs
    for (size_t i = 0; i < len; ++i) {
        resultStr[i] = str.c_str()[i];
    }

    // add the character and the null terminator
    resultStr[len + 1] = c;
    resultStr[len + 2] = '\0';

    return String(resultStr);

}

// concatenates the c-strings from objects lhs and rhs
String String::operator_plus (const String& lhs, const String& rhs){
    size_t lhsLen = lhs.length();
    size_t rhsLen = rhs.length();

    if(lhsLen + rhsLen > MAX_LENGTH){
         // if the constructed string object would be too long, print an error message and use default constructor
        std::cout << "Could not concatenate " << lhs.c_str() << " and " << rhs.c_str() << std::endl;
        std::cout << "The length  is too long! Together they have length " << lhsLen + rhsLen << ". That exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        std::cout << "The default constructor was called instead!" << std::endl; // this was done in the clear() function
        return String();
    }

    char* resultStr = new char[lhsLen + rhsLen + 1];  // +1 for null terminator

    // copy characters from lhs
    for (size_t i = 0; i < lhsLen; ++i) {
        resultStr[i] = lhs.c_str()[i];
    }

    // copy characters from rhs
    for (size_t i = 0; i < rhsLen; ++i) {
        resultStr[lhsLen + i] = rhs.c_str()[i];
    }
    resultStr[lhsLen + rhsLen] = '\0';

    return String(resultStr);

}


