/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Matrix{
    int rows;
    int cols;
    int **matrix;
public:

    Matrix(int rows, int cols) : rows(rows), cols(cols){
        matrix = new int*[rows];
        for(int i=0;i<rows;i++) matrix[i] = new int[cols];
        input();
    }

    void input(){
        
    }



};

int main(){

    

    return 0;
}