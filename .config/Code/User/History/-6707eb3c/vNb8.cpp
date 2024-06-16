#include <iostream>
#include <string>

using namespace std;

class MatrixManipulator{
    char **matrix;      // Pointer to a 2D character array
    int numRows;        // Number of rows in the array
    int numColumns;     // Number of columns in the array
    string dictionary[109] = {  // Array of strings containing words to be searched for
        "cat", "dog", "bat", "hat", "run", "sun", "red", "blue", "pen", "cup",
        "fish", "bird", "rose", "tree", "lake", "moon", "star", "fork", "lamp", "book",
        "play", "pool", "rose", "silk", "soft", "ship", "tile", "vest", "wish", "zoom",
        "case", "drop", "face", "gold", "jump", "kick", "lime", "nose", "ring", "tail",
        "cloud", "crawl", "dream", "fresh", "grain", "happy", "juice", "lucky", "music", "piano",
        "queen", "quick", "smile", "storm", "toast", "umbra", "video", "wrist", "zebra", "world",
        "apple", "brave", "chess", "drink", "flame", "grape", "jazz", "lemon", "novel", "pride",
        "quest", "route", "shoe", "trace", "unity", "vivid", "water", "xerox", "yellow", "zesty",
        "silver", "orange", "camera", "travel", "window", "floral", "banana", "purple", "turkey", 
        "magnet", "branch", "guitar", "impact", "castle", "pickle", "forest", "oliver", "planet", "summer",
        "a", "i", "on", "up", "by", "go", "no", "eat", "it", "as"
    };

public:

    MatrixManipulator(int numRows, int numColumns) : numRows(numRows), numColumns(numColumns){

    }

    ~MatrixManipulator(){
        for(int i=0;i<numRows;i++) delete[] matrix[i];
        delete[] matrix;
    }

    void allocateMemory(){
        matrix = new char*[numRows];
        for(int i=0;i<numRows;i++) matrix[i] = new char[numColumns];
    }

    void initializeMatrix(){
        cout<<"Enter values:\n";
        for(int i=0;i<numRows;i++) for(int j=0;j<numColumns;j++) cin>>matrix[i][j];
    }

    void getWordsFromRows(){
        for(int i=0;i<numRows*numColumns;i++){
            for(int j=0;j<109;j++){
                if(matrix[i/numRows][i%numColumns] == dictionary[j][0]){
                    for(int k=1;k<dictionary[j].length();k++){
                        
                    }
                }
            }
        }
    }

};

int main() {

    return 0;
}