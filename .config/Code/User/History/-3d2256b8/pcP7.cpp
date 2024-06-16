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
    Vector(const Vector& other) : size(other.size){
        arr = new int[size];
        for(int i=0;i<size;i++){
            arr[i] = other.arr[i];
        }
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
        *this = *this + other;
        return *this;
    }
    Vector operator-=(Vector& other){
        *this = *this - other;
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
istream& operator>>(istream& input, Vector& other){
    cout<<"Enter Size: ";
    input>>other.size;
    cout<<"Enter values\n";
    for(int i=0;i<other.size;i++) input>>other.arr[i];
    return input;
}

int main(){
    Vector v1(5);
    Vector v2(5);

    cout<<"Enter values for v1: ";
    cin>>v1;
    cout<<"Enter values for v2: ";
    cin>>v2;

    cout<< "v1: "<<v1<< endl;
    cout<<"v2: "<<v2<< endl;

    Vector v3 = v1 + v2;
    cout<<"v1 + v2: "<<v3<<endl;

    Vector v4 = v1 - v2;
    cout<<"v1 - v2: "<<v4<<endl;

    Vector v5 = v1 * 2;
    cout<<"v1 * 2: "<<v5<<endl;

    Vector v6 = v1 / 2;
    cout<<"v1 / 2: "<<v6<<endl;

    v1 += v2;
    cout<<"v1 += v2: "<<v1<<endl;

    v1 -= v2;
    cout<<"v1 -= v2: "<<v1<<endl;

    bool isEqual = v1 == v2;
    cout<< "v1 == v2: "<<(isEqual ? "true" : "false")<<endl;

    bool isNotEqual = v1 != v2;
    cout<<"v1 != v2: "<<(isNotEqual ? "true" : "false")<<endl;

    return 0;
}    