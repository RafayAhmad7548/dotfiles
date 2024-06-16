/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class String{
    char* data;
    int size;

public:

    String() : data(nullptr), size(0){}
    String(int size) : size(size){
        data = new char[size];
    }
    String(char* str){
        int length = 0;
        for(int i=0;str[i]!='\0';i++) length++;
        this->size = length+1;
        data = new char[size];
        for(int i=0;i<this->size;i++) data[i] = str[i];
        data[size - 1] = '\0';
    }
    String(const String &str){
        this->size = str.size+1;
        data = new char[size];
        for(int i=0;str.size;i++) data[i] = str.data[i];
        data[size-1] = '\0';
    }
    ~String(){
        delete[] data;
    }

    int strLength(){
        return size;
    }
    void clear(){
        delete[] data;
        size = 0;
    }
    bool empty(){
        return size == 0;
    }
    int charAt(char c){
        for(int i=0;i<this->size;i++) if(data[i] == c) return i;
        return -1;
    }
    char* getData(){
        return data;
    }
    bool equals(char* str){
        int length = 0;
        for(int i=0;str[i]!='\0';i++) length++;
        if(length != this->size) return false;
        for(int i=0;i<this->size;i++) if(data[i] != str[i]) return false;
        return true;
    }
    bool equalsIgnoreCase(char* str){ // TODO
        for(int i=0;str[i]!='\0' && i<this->size;i++)
            if(data[i] != str[i]) return false;
        return true;
    }
    char* substring(int startIndex, int endIndex){
        char* result = new char[endIndex-startIndex+1];
        for(int i=startIndex;i<endIndex;i++) result[i-startIndex] = data[i];
        result[endIndex-startIndex] = '\0';
        return result;
    }
    char* substring(char* substr, int startIndex){
        char* result;
        for(int i=startIndex;i<this->size;i++){
            if(this->equals(substr)){
                return substring(startIndex, this->size);
            }
        }
        return NULL;
    }
    char* substring(char* substr, int startIndex, int endIndex){
        char* result;
        for(int i=startIndex;i<endIndex;i++){
            if(this->equals(substr)){
                return substring(startIndex, endIndex);
            }
        }
        return NULL;
    }
    void print(){
        if(this->size == 0) cout<<"NULL\n";
        else{
            for(int i=0;i<this->size;i++) cout<<data[i];   
            cout<<endl;
        }
    }
    bool startsWith(char* substr) const{
        String str1(data);
        String str2(substr);
        String str3(str1.substring(0, str2.strLength()));
        return str3.equals(substr);
    }
    bool endsWith(char* substr) const{
        String str1(substr);
        String str2(data);
        String str3(str2.substring(str2.strLength()-str1.strLength(), str2.strLength()));
        return str3.equals(substr);
    }
    void concatenate(char* str){
        String str1(str);
        char* newStr = new char[str1.strLength()+this->size+1];
        for(int i=0;i<this->size;i++) newStr[i] = data[i];
        for(int i=0;i<str1.strLength();i++) newStr[i+this->size] = str[i];
        newStr[str1.strLength()+this->size] = '\0';
        delete[] data;
        data = newStr;
        this->size += str1.strLength();
    }
    void insert(int index, char* str){
        String str1(str);
        char* newStr = new char[str1.strLength()+this->size+1];
        for(int i=0;i<str1.strLength()+this->size;i++){
            if(i<index) newStr[i] = data[i];
            else if(i<str1.strLength()+index) newStr[i] = str[i-index];
            else newStr[i] = data[i-index];
        }
        newStr[str1.strLength()+this->size] = '\0';
        delete[] data;
        data = newStr;
        this->size += str1.strLength();
    }
    void remove(char* substr){
        
    }
    void trim(){
        int start = 0, end = this->size;
        for(int i=0;this->data[i] == ' ';i++) start++;
        
        
    }


};

int main(){

    

    return 0;
}