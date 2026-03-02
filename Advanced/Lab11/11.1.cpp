#include <stdio.h>

int BinSearch(int data[], int n, int find);

int main() {
    int data[6] = { 1, 2, 3, 4, 5, 7 };
    int n = 6;
    int find = 5;
    
    int pos = BinSearch(data, n, find);
    
    if (pos != -1) {
        printf("Found %d at %d\n", find, pos);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}


int BinSearch(int data[], int n, int find) {
    int leftIndex = 0;
    int rightIndex = n - 1;
    int middleIndex;
    int position = -1;

    while (leftIndex <= rightIndex) {
        middleIndex = (leftIndex + rightIndex) / 2;

        if (data[middleIndex] == find) {
            position = middleIndex;
            break;
        } 
        else if (data[middleIndex] < find) {
            leftIndex = middleIndex + 1;
        } 
        else {
            rightIndex = middleIndex - 1;
        }
    }

    return position;
}