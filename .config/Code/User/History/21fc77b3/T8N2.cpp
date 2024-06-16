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
    }

    void input(){
        cout<<"Enter values: ";
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>matrix[i][j];
            }
        }
    }

    void print(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    Matrix operator*(Matrix m){
        Matrix result(this->rows, m.cols);
        for(int i=0;i<result.rows;i++){
            for(int j=0;j<result.cols;j++){
                int no = 0;
                for(int x=0;x<this->cols;x++){
                    no += this->matrix[i][x]*m.matrix[x][j];
                }
                result.matrix[i][j] = no;
            }
        }
        return result;
    }

};

int main(){

    Matrix m1(3, 2);
    m1.input();
    Matrix m2(2, 3);
    m2.input();

    Matrix m3 = m1*m2;
    m3.print();

    return 0;
}