/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Minesweeper{
    char** grid;
    int* mineLocations;
    int size;
    int mines;
    int opened;

public:

    Minesweeper(int size, int mines) : size(size), mines(mines), opened(0){
        srand(time(0));
        grid = new char*[size];
        for(int i=0;i<size;i++){
            grid[i] = new char[size];
            for(int j=0;j<size;j++) grid[i][j] = '#';
        }
        mineLocations = new int[mines];
        setMines();
    }
    ~Minesweeper(){
        for(int i=0;i<size;i++) delete[] grid[i];
        delete[] grid;
        delete[] mineLocations;
    }

    void reset(){
        for(int i=0;i<size;i++) for(int j=0;j<size;j++) grid[i][j] = '#';
        setMines();
    }
    void revealAll(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                
            }
        }
    }
    bool revealCell(int row, int col, bool checkMine){
        for(int i=0;i<mines;i++){
            if(mineLocations[i]/size == row && mineLocations[i]%7 == col){
                grid[row][col] = '*';
                revealAll();
                return false;
            }   
        }
        grid[row][col] = checkSurrounding(row, col) + '0';
        opened++;
        if(grid[row][col] == '0'){
            return revealCell(row+1, col+1, false);
            return revealCell(row, col+1, false);
            return revealCell(row-1, col+1, false);
            return revealCell(row-1, col, false);
            return revealCell(row-1, col-1, false);
            return revealCell(row, col-1, false);
            return revealCell(row+1, col-1, false);
            return revealCell(row+1, col, false);
        }
        return true;
    }
    void flagCell(int row, int col){
        grid[row][col] = 'P';
    }
    int checkSurrounding(int row, int col){
        int count = 0;
        for(int i=0;i<mines;i++){
            if(mineLocations[i]/size == row+1 && mineLocations[i]%7 == col+1) count++;
            if(mineLocations[i]/size == row && mineLocations[i]%7 == col+1) count++;
            if(mineLocations[i]/size == row-1 && mineLocations[i]%7 == col+1) count++;
            if(mineLocations[i]/size == row-1 && mineLocations[i]%7 == col) count++;
            if(mineLocations[i]/size == row-1 && mineLocations[i]%7 == col-1) count++;
            if(mineLocations[i]/size == row && mineLocations[i]%7 == col-1) count++;
            if(mineLocations[i]/size == row+1 && mineLocations[i]%7 == col-1) count++;
            if(mineLocations[i]/size == row+1 && mineLocations[i]%7 == col) count++;
        }
        return count;
    }
    bool checkWin(){
        return opened == (size*size) - mines;
    }
    void setMines(){
        for(int i=0;i<mines;i++){
            bool valid;
            do{
                valid = true;
                mineLocations[i] = rand()%(size*size);
                for(int j=0;j<i;j++){
                    if(mineLocations[j] == mineLocations[i]){
                        valid = false;
                        break;
                    }
                }
            }while(!valid);
        }
    }
    void displayGrid(){
        cout<<"  ";
        for(int i=0;i<size;i++) cout<<i+1<<" ";
        cout<<endl;
        for(int i=0;i<size;i++){
            cout<<i+1<<" ";
            for(int j=0;j<size;j++) cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;

        for(int i=0;i<mines;i++){
            cout<<mineLocations[i]<<" ";
        }
    }




};

int main(){

    Minesweeper game(7, 10);
    while(game.checkWin()){
        game.displayGrid();
        

    }
    

    return 0;
}