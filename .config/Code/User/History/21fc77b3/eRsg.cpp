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
        Matrix result(this->row, m.col, "multiplied");
        for(int i=0;i<result.row;i++){
            for(int j=0;j<result.col;j++){
                int no = 0;
                for(int x=0;x<this->col;x++){
                    no += this->matrix[i][x]*m.matrix[x][j];
                }
                result.matrix[i][j] = no;
            }
        }
        return result;
    }



};

int main(){

    

    return 0;
}