#ifndef STRING_H_
#define STRING_H_
#define MAX_LENGTH  100

#include <iostream>

class String{
    public:
    //default constructor
    String();
    //copy constructor
    String(const String&);
    
    // constructor from a c-string

    size_t length();
    size_t max_size();
    void resize (size_t n, char c);
    String& operator= (const String& str);
    String& operator_plus (const String& str, char c);

    //private:
     char* str;





};
#endif  //STRING_H_