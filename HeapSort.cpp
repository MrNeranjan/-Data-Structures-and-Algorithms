#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
   int right  = 2*root +2;
   int left  = 2*root +1;
   
   if (right < n && arr[right]> arr[largest]){
      largest = right;

   }
   if (left < n && arr[left]> arr[largest]){
      largest = left;

   }
   if (largest != root){
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;
      heapify(arr,n,largest);
   }
     
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int j  = (n/2) -1;
   for ( int i = j ; j>=0; j--){
       heapify(arr,n,j);
   }
   
  
   // extracting elements from heap one by one
   for (int i = n-1 ; i>=0;i--){
      int temp  = arr[i];
      arr[i] = arr[0];
      arr[0]= temp;
      heapify(arr,i,0);
   }

   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main 
int main(){

    // when array length is given, create the random array and then it short by heapsort algorithm
     int arrLength ;
     int arr[arrLength] ={};
     cout << "Enter the array length : ";
     cin>> arrLength;
     
      // generating random values 
     for (int i =0;i< arrLength;i++){
         arr[i]= rand()%100;
     } 
     cout << "Input array     : " ; 
     for (int i =0; i< arrLength;i++){
        cout << arr[i]<< " ";
     }
    cout << endl;
    heapSort (arr,arrLength);
    cout << "Sorted Array    : ";
    displayArray(arr,arrLength);

}
