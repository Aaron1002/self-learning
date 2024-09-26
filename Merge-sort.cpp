// Complexity: O(nlogn) -> using Recusive tree
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

void mergeSort(int*, int, int);     //排序
void merge(int*, int, int, int);    //合併

int main()
{
    int n;
    cout << "Enter the number of random element: ";
    cin >> n;
    
    srand(time(0));
    int *arr = new int[n];
    for (int i=0; i<n; i++){
        arr[i] = rand() % 1000; //產生1000以內的隨機數
    }
    
    mergeSort(arr, 0, n-1); //pass array index
    
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";    
    }

    delete[] arr;
    
    return 0;
}

void mergeSort(int* arr, int start, int end){
    if (start < end){   // **when start==mid==end,recursion終止**
        int mid = floor( (start+end)/2 );   
        mergeSort(arr, start, mid); //前半sort
        mergeSort(arr, mid+1, end); //後半sort
        merge(arr, start, mid, end);    
    }
}

void merge(int* arr, int start, int mid, int end){  //sort前半&後半
    int n1 = mid - start + 1;   //前半的元素數量
    int n2 = end - mid; //後半的元素數量
    int *L = new int[n1+1]; 
    int *R = new int[n2+1]; 
    
    for (int i=0; i<n1; i++){   //放前半元素
        L[i] = arr[start+i];
    }
    for (int i=0; i<n2; i++){   //放後半元素
        R[i] = arr[mid+i+1];
    }
    
    L[n1] = INT_MAX;    
    R[n2] = INT_MAX;    
/*  設終止條件給下面i,j的移動，當一陣列空時，INT_MAX(sentinel value)
    會讓該陣列不再被選取。其中，INT_MAX為int之最大值(可視為無限大)  */

    int i = 0;
    int j = 0;
    for (int k=start; k<end+1; k++){    //比較前半&後半個元素大小並放入原array
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
    delete[] L;
    delete[] R;
    
}