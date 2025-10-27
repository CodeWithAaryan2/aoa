#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value, weight;
};
// Compare items by value/weight ratio (descending)
int cmp(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r2 > r1) - (r2 < r1);
}
double knapsack(int cap, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), cmp);
    double val = 0.0;
    for (int i = 0; i < n && cap > 0; i++) {
        if (arr[i].weight <= cap) {
            cap -= arr[i].weight;
            val += arr[i].value;
        } 
        else {
            val += arr[i].value * (double)cap / arr[i].weight;
            break;
        }
    }
    return val;
}
int main() {
    int n, cap;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &cap);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("\nMaximum value in Knapsack = %.2f\n", knapsack(cap, items, n));
    return 0;
}
Output:

Enter number of items: 3
Enter knapsack capacity: 50
Enter value and weight for item 1: 60 10
  Enter value and weight for item 2:100 20
  Enter value and weight for item 3: 120 30
