/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Vector{
    int size;
    int *arr;
public:

    Vector(int size) : size(size){
        arr = new int[size];
    }

    Vector operator+(Vector& other){
        Vector *result = new Vector(size);
        for(int i=0;i<this->size && i<other.size;i++){
            result->arr[i] = this->arr[i] + other.arr[i];
        }
        if(this->size > other.size) for(int i=this->size-other.size;i<this->size;i++) result->arr[i] = this->arr[i];
        else for(int i=other.size-this->size;i<other.size;i++) result->arr[i] = other.arr[i];
        return *result;
    }
    Vector operator-(Vector& other){
        Vector *result = new Vector(size);
        for(int i=0;i<this->size && i<other.size;i++){
            result->arr[i] = this->arr[i] - other.arr[i];
        }
        if(this->size > other.size) for(int i=this->size-other.size;i<this->size;i++) result->arr[i] = this->arr[i];
        else for(int i=other.size-this->size;i<other.size;i++) result->arr[i] = other.arr[i];
        return *result;
    }

    Vector operator*(int n){
        for(int i=0;i<this->size;i++) this->arr[i] *= n;
        return *this;
    }
    Vector operator/(int n){
        if(n != 0) for(int i=0;i<this->size;i++) this->arr[i] /= n;
        return *this;
    }

    Vector operator+=(Vector& other){
        return *this + other;
    }
    Vector operator-=(Vector& other){
        return *this - other;
    }

    bool operator==(Vector& other){
        if(this->size != other.size) return false;
        for(int i=0;i<this->size;i++) if(this->arr[i] != other.arr[i]) return false;
        return true;
    }
    bool operator!=(Vector& other){
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& output, Vector& other);
    friend istream& operator>>(istream& output, Vector& other);

    ~Vector(){
        delete[] arr;
    }


};

ostream& operator<<(ostream& output, Vector& other){
    output<<"Size: "<<other.size<<endl;
    for(int i=0;i<other.size;i++) output<<other.arr[i]<<" ";
    return output;
}
istream& operator>>(istream& output, Vector& other){
    
}




int main(){

    

    return 0;
}