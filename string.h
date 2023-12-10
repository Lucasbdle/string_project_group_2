#ifndef STRING_H_
#define STRING_H_
#define MAX_LENGTH  100

#include <iostream>

class String{
    public:
        // default constructor
        String();
        // copy constructor
        String(const String& other);
        // constructor from a c-string
        String(char* strcopy);
        // destructor
        ~String();

        // Student A
        const char* c_str() const;
        size_t size() const;
        void clear();
        String& operator= (char c);
        String operator_plus (const String& lhs, const char* rhs);

        // Student B
        size_t length() const;
        size_t max_size() const;
        void resize (size_t n, char c);
        String& operator= (const String& str);
        String operator_plus (const String& str, char c);

        // Student C
        size_t capacity() const;
        bool empty() const;
        void reserve (size_t n = 0);
        String& operator= (const char* s);
        String operator_plus (const String& lhs, const String& rhs);

    private:
        char* c_str_ = nullptr;

};
#endif  //STRING_H_