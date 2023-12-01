#include <iostream> 

class self_String {
    private : 
    size_t longueur_max ; 
    size_t length(const char* string){
        size_t length = 0 ; 
        while (string[length] != '\0'){
            length+=1 ; 
        }
        return length ; 
    }
    
    void copy(char* data , const char* input){
        size_t i = 0 ; 
        while(input[i] != '\0'){
            data[i] = input[i]  ; 
            i++ ; 
        }
        data[i] = '\0' ;
    }
    public : 

    char* data ; 
    self_String(const char* input){
        size_t longueur = length(input) ; 
        data = new char[longueur+1] ; 
        longueur_max = longueur+1 ; 
        copy(data,input) ; 
    }

    void destructor_string(){
        delete[] data ;
    }

    void display(const char* unstring){
        std::cout << unstring << std::endl;
    }

    const char* c_str(const char* unstring){
        size_t longueur = length(unstring) ; 
        char* str_c = new char[longueur+1] ; 
        for (int i = 0 ; i <= longueur ; ++i){
            str_c[i] = unstring[i] ; 
        }
        return str_c ; 
    }

    size_t size(const char* unstring){
        return length(unstring) ; 
    }
    size_t length_public(const char* unstring){
        return length(unstring) ; 
    }
    const char* clear(const char* unstring){
        if (unstring == data){
            data = "" ; 
        }
        unstring = "" ; 
        return unstring ; 
    }
    void resize(size_t longueur , const char* unstring){
        if (unstring == data){
            char* new_data = new char[longueur] ; 
            longueur_max = longueur ; 
            copy(new_data,data) ; 
        }
    }
    size_t max_size(){
        return longueur_max ;  
    }
    bool empty(){
        if (length(data) == 0){
            return true ; 
        }
        return false ; 
    }
    void operator= (auto unstring){
        data = const_cast<char*>(unstring) ; 
    }
    void operator+ (auto unstring){
        char* unstring_1 = const_cast<char*>(unstring) ; 
        size_t longueur_1 = length(unstring) ; 
        char* new_data = new char [length(data) + longueur_1 ] ; 
        for (int i = 0 ; i < length(data)  ; i++){
            new_data[i] = data[i] ; 
        }
        for (int i = length(data) ; i < (longueur_1+length(data)) ; i++){
            new_data[i] = unstring_1[i-length(data)] ; 
        }
        longueur_max = longueur_1 + length(data) ; 
        data = new_data ; 
        
    }
    void reserve (size_t longueur){
        char* new_data = new char[length(data) + longueur] ; 
        for (int i = 0 ; i < (length(data) + longueur ) ; i++){
            new_data[i] = data[i] ; 
        }
        longueur_max = length(data) + longueur ; 
        new_data = data ;      
    }
} ; 


int main(){
    self_String unstring("Hello World") ; 
    unstring.display(unstring.data) ; 
    const char* cc_string = unstring.c_str(unstring.data);
    self_String unstring_1("Hello") ; 
}