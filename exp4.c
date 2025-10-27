#include <stdio.h>
// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray
    int L[n1], R[n2]; // Temporary arrays
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    // Merge the temp arrays back into arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;} 
    else {
            arr[k] = R[j];
            j++;}
        k++;}
    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;}
    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;}
}
// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        mergeSort(arr, left, mid);  // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half
        merge(arr, left, mid, right);   // Merge the sorted halves
    }
}
// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Original array:\n");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}
Enter number of elemet: 4
Enter 4 element 
12 43 13 1
original array
12 43 13 1 
sorted array
1 12 13 43
