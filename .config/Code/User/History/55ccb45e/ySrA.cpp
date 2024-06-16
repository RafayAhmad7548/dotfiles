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
        for(int i=0;i<mines;i++){
            grid[mineLocations[i]/7][mineLocations[i]%7] = '*';
        }
    }
    bool revealCell(int row, int col, bool checkMine){
        if(checkMine){
            for(int i=0;i<mines;i++){
                if(mineLocations[i]/size == row && mineLocations[i]%size == col){
                    grid[row][col] = '*';
                    revealAll();
                    return false;
                }   
            }
        }
        grid[row][col] = checkSurrounding(row, col) + '0';
        opened++;
        if(grid[row][col] == '0'){
            if(row<size-1 && col<size-1 && grid[row+1][col+1] == '#') revealCell(row+1, col+1, false);
            if(col<size-1 && grid[row][col+1] == '#') revealCell(row, col+1, false);
            if(row>0 && col<size-1 && grid[row-1][col+1] == '#') revealCell(row-1, col+1, false);
            if(row>0 && grid[row-1][col] == '#') revealCell(row-1, col, false);
            if(row>0 && col>0 && grid[row-1][col-1] == '#') revealCell(row-1, col-1, false);
            if(col>0 && grid[row][col-1] == '#') revealCell(row, col-1, false);
            if(row<size-1 && col>0 && grid[row+1][col-1] == '#') revealCell(row+1, col-1, false);
            if(row<size-1 && grid[row+1][col] == '#') revealCell(row+1, col, false);
        }
        return true;
    }
    void flagCell(int row, int col){
        grid[row][col] = 'P';
    }
    int checkSurrounding(int row, int col){
        int count = 0;
        for(int i=0;i<mines;i++){
            if(row<size-1 && col<size-1 && mineLocations[i]/size == row+1 && mineLocations[i]%size == col+1) count++;
            if(col<size-1 && mineLocations[i]/size == row && mineLocations[i]%size == col+1) count++;
            if(row>0 && col<size-1 && mineLocations[i]/size == row-1 && mineLocations[i]%size == col+1) count++;
            if(row>0 && mineLocations[i]/size == row-1 && mineLocations[i]%size == col) count++;
            if(row>0 && col>0 && mineLocations[i]/size == row-1 && mineLocations[i]%size == col-1) count++;
            if(col>0 && mineLocations[i]/size == row && mineLocations[i]%size == col-1) count++;
            if(row<size-1 && col>0 && mineLocations[i]/size == row+1 && mineLocations[i]%size == col-1) count++;
            if(row<size-1 && mineLocations[i]/size == row+1 && mineLocations[i]%size == col) count++; 
        }
        return count;
    }
    bool checkWin(){
        return opened == ((size*size) - mines);
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
        for(int i=0;i<size;i++) cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<" ";
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

    int row, col;
    char c;
    int size, mines;
    cout<<"Enter size of the game board: ";
    cin>>size;
    cout<<"Enter no Of mines: ";
    cin>>mines;
    Minesweeper game(size, mines);

    bool win = true;

    while(!game.checkWin()){
        game.displayGrid();
        cout<<"Enter row: ";
        cin>>row;
        cout<<"Enter col: ";
        cin>>col;
        cout<<"Enter F to flag or R to reveal: ";
        cin>>c;

        if(row<size && col<size && (c == 'F' || c == 'R')){
            if(c == 'R' && !game.revealCell(row, col, true)){
                game.displayGrid();
                win = false;
                cout<<"You Lost\n";
                break;
            }
            else if(c == 'F') game.flagCell(row, col);
        }
        else cout<<"Invalid input\n";

    }

    if(win){
        game.displayGrid();
        cout<<"You Won!\n";
    }
    

    return 0;
}