#include<bits/stdc++.h>

using namespace std;

void print_array(int arr[],int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}

void bubblesort_ASC(int arr[], int n){
    bool is_swap = false;
    int count = 0;
    int c =0;
    for(int i = 0; i<n-1;i++){
        for(int j = 0; j<n-i-1;j++){
             is_swap = false;     
            c++;
            if(arr[j]>arr[j+1]){
                count ++;
                swap(arr[j],arr[j+1]);
                is_swap = true;
            }
        }
        if(!is_swap){
            cout<< "no of times it entered == "<<c<<" no of times swap done == "<<count<<endl;
            return;
        }
    }
    cout<< "no of times it entered == "<<c<<" no of times swap done == "<<count<<endl;
}

void bubblesort_DSC(int arr[], int n){
    bool is_swap;
    for(int i = 0; i < n-1; i++){   // Outer loop should run n-1 times
        is_swap = false;           // Reset is_swap for each outer loop iteration
        for(int j = 0; j < n-i-1; j++){  // Inner loop should start from 0
            if(arr[j] < arr[j+1]){       // For descending order, swap if arr[j] < arr[j+1]
                swap(arr[j], arr[j+1]);
                is_swap = true;
            }
        }
        if(!is_swap){  // If no swaps were made, the array is sorted
            break;
        }
    }
}

void selectionsort_ASC(int arr[], int n){
    for(int i =0 ; i <n-1;i++){
        int si = i;
        for(int j = i;j<n;j++){
            if(arr[si]>arr[j]) si = j;
        }
        if(si != i){
            swap(arr[si],arr[i]);
        }
    }
}

void selectionsort_DSC(int arr[], int n) {
    // Outer loop to iterate over each element of the array (except the last one)
    for (int i = 0; i < n - 1; i++) {
        int si = i;  // si holds the index of the current largest element found
        
        // Inner loop to find the largest element in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[si] < arr[j]) {  // If a larger element is found, update si
                si = j;
            }
        }
        
        // Swap the largest element found with the current position (i)
        if (si != i) {
            swap(arr[si], arr[i]);  // Swap only if a larger element is found
        }
    }
}
void insertionsort_ASC(int arr[], int n){
    for(int i =1;i<n;i++){
        int p = i-1;
        int c = arr[i];
        while(p>=0 && arr[p]>c){
            arr[p+1] = arr[p];
            p--;
        }
        arr[p+1] = c;
    }
}

void insertionsort_DSC(int arr[], int n) {
    // Start from the second element (index 1) and iterate over the array
    for (int i = 1; i < n; i++) {
        int p = i - 1;  // p is the previous index
        int c = arr[i]; // c is the current element to be inserted
        
        // Shift elements of arr[0..i-1], that are smaller than c, to one position ahead
        while (p >= 0 && arr[p] < c) {
            arr[p + 1] = arr[p];  // Shift the element one position to the right
            p--;
        }
        
        // Place the current element at its correct position in the sorted part of the array
        arr[p + 1] = c;
    }
}

int main(){
    int arr[] = {1,2,32,366,34,4,5};
    // int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    print_array(arr,n);
    bubblesort_ASC(arr,n);
    cout << "Sorted array in ascending order:--BUBBLE SORT ";
    print_array(arr,n);
    bubblesort_DSC(arr,n);
    cout << "Sorted array in Desending order:--BUBBLE SORT ";
    print_array(arr,n);


    int arr1[] = {1,2,32,366,34,4,5};
    // int arr[] = {1,2,3,4,5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    cout << "Original array: ";
    print_array(arr1,n1);
    selectionsort_ASC(arr1,n1);
    cout << "Sorted array in ascending order:--selection SORT ";
    print_array(arr1,n1);
    selectionsort_DSC(arr1,n1);
    cout << "Sorted array in Desending order:--selection SORT ";
    print_array(arr1,n1);

     int arr2[] = {1,2,32,366,34,4,5};
    // int arr[] = {1,2,3,4,5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Original array: ";
    print_array(arr2,n2);
    insertionsort_ASC(arr2,n2);
    cout << "Sorted array in ascending order:--insertion SORT ";
    print_array(arr2,n2);
    insertionsort_DSC(arr2,n2);
    cout << "Sorted array in Desending order:--insertion SORT ";
    print_array(arr2,n2);


    
    
}