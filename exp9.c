#include <stdio.h>
int n, target;
int set[20], subset[20];
void displaySubset(int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}
void sumOfSubsets(int index, int currentSum, int subsetSize) {
    if (currentSum == target) {
        displaySubset(subsetSize); // Found a valid subset
        return;
    }
    if (index == n || currentSum > target)
        return;
    // Include current element
    subset[subsetSize] = set[index];
    sumOfSubsets(index + 1, currentSum + set[index], subsetSize + 1);
    // Exclude current element
    sumOfSubsets(index + 1, currentSum, subsetSize);
}
int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements of the set:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);
    printf("Subsets with sum %d are:\n", target);
    sumOfSubsets(0, 0, 0);
    return 0;
}
Output:
Enter number of elements: 5 
Enter elements of the set: 12345 
Enter target sum: 6 
Subsets with sum 6 are: {1 2 3} {1 5} {2 4} 
