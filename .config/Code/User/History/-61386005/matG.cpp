// /*
// Rafay Ahmad
// 23I-2526
// */
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

int findMax(int arr[], int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }
}

int countTriplets(int arr[], int n){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                count++;
            }
        }
    }
    return count;
}

// void merge(int *arr, int left, int mid, int right){
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     int leftArr[n1];
//     int rightArr[n2];

//     for(int i=0;i<n1;i++) leftArr[i] = arr[left+i];
//     for(int i=0;i<n2;i++) rightArr[i] = arr[mid+i+1];

//     int i = 0;
//     int j = 0;
//     int k = left;

//     while(i<n1 && j<n2){
//         if(leftArr[i] <= rightArr[j]){
//             arr[k] = leftArr[i];
//             i++;
//         }
//         else{
//             arr[k] = rightArr[i];
//             j++;
//         }
//         k++;
//     }
//     while(i<n1){
//         arr[k] = leftArr[i];
//         i++;
//         k++;
//     }
//     while(j<n2){
//         arr[k] = rightArr[i];
//         j++;
//         k++;
//     }
// }

// void mergeSort(int *arr, int left, int right){
//     if(left < right){
//         int mid = left + (right - left)/2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid+1, right);
//         merge(arr, left, mid, right);
//     }
// }

void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;  // Initial index of the first subarray
    int j = 0;  // Initial index of the second subarray
    int k = left;  // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Clean up memory
    delete[] L;
    delete[] R;
}

// Function to implement merge sort
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}


int binarySearch(int arr[], int n, int x){
    int left = 0;
    int right = n-1;

    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int* readData(string fileName){
    ifstream infile;
    int dummy;
    infile.open(fileName);
    int i = 0;
    while(infile >> dummy) i++; 
    int* arr = new int[i];
    i = 0;
    infile.close();
    infile.open(fileName);
    while(infile >> arr[i]) i++; 
    infile.close();
    return arr;
}


int main(){

    int* arr100 = readData("data_100.txt");
    int* arr1000 = readData("data_1000.txt");
    int* arr5000 = readData("data_5000.txt");
    int* arr10000 = readData("data_10000.txt");
    
    
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr10000, 0, 9999);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout<<duration.count()<<"ms\n";

    
    auto start = std::chrono::high_resolution_clock::now();
    findMax(arr10000, 10000);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout<<duration.count()<<"ms\n";
    
    

    return 0;
}