//This is a hybrid advanced quick sort algorithm implemented by using quicksort and insertion sort

import java.io.*;
class GFG {
    private static int partition(int arr[], int high, int low){
        int pivot = arr[high];
        int i = low;
        int j = low;
 
        while (i <= high) {
            if (arr[i] > pivot)
                i++;
            else {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j++;
            }
        }
        return j - 1;
    }

    private static void insertionSort(int a[], int high, int low){
        for (int i = low + 1; i <= high; i++) {
            for (int j = i - 1; j >= low; j--) {
                if (a[j] > a[j + 1]) {
                    // Swap
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
                else
                    break;
            }
        }
    }
 
    public static void hybridAdvancedQuickSort(int arr[], int low, int high){
        while (low < high) {
            if (high - low < 10) {
                insertionSort(arr, high, low);
                break;
            }else {
             
                int pivot = partition(arr, high, low);

                if (pivot - low < pivot - high) {
                    hybridAdvancedQuickSort(arr, low, pivot - 1);
                    low = pivot + 1;
                }else {
                    hybridAdvancedQuickSort(arr, pivot + 1, high);
                    high = pivot - 1;
                }
            }
        }
    }
   
    // Main method
    public static void main(String[] args){
 
        int arr[] = { 24, 97, 40, 67, 88, 85, 15, 66, 53, 44, 26, 48, 16, 52, 45, 23, 90, 18, 49, 80, 23 };
 
        hybridAdvancedQuickSort(arr, 0, arr.length - 1);
        for (int i : arr)
            System.out.print(i + "  ");
    }
}
