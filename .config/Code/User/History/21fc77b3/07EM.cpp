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
        cout<<"Enter values: ";
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>matrix[i][j];
            }
        }
    }

    Matrix operator*(Matrix m){
        
    }



};

int main(){

    

    return 0;
}