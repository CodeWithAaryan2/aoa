#include<stdio.h>
//Function to perform binary search
int binarySearch(int arr[], int left, int right, int key){
	if(left>right)//base case
		return -1;
	int mid=left+(right-left)/2;
	//if key is at middle index, return the index
	if(arr[mid]==key)
		return mid;
	//If key is smaller than middle element
	if(arr[mid]>key)
		return binarySearch(arr, left, mid-1, key);
	//If key is larger than middle element
	return binarySearch(arr, mid+1, right, key);}
int main(){
	int n, key;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements of array in ascending order:\n");
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("Enter the key value to search for: ");
	scanf("%d", &key);
	//Call binarySearch to search for key
	int result=binarySearch(arr,0, n-1, key);
	//Print the result
	if(result!=-1)
		printf("Element found at index: %d\n", result);
	else
		printf("Element not found.\n");
	return 0;
}

Enter number of elemet in the array: 4
Enter the element of arrat in ascending order: 
1 12 13 44
Enter the key value to search for: 12
Element found at index: 2
