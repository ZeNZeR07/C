#include <stdio.h>


void TowerHanoi(int discCount, int sourcePeg, int destinationPeg);

int main() {

    TowerHanoi(3, 1, 3);
    
    return 0;
}


void TowerHanoi(int discCount, int sourcePeg, int destinationPeg) {
    int auxiliaryPeg = 6 - (sourcePeg + destinationPeg);

    if (discCount == 1) {
        printf("Disc 1 from %d to %d\n", sourcePeg, destinationPeg);
    } 
    else {
        TowerHanoi(discCount - 1, sourcePeg, auxiliaryPeg);
        
        printf("Disc %d from %d to %d\n", discCount, sourcePeg, destinationPeg);
        
        TowerHanoi(discCount - 1, auxiliaryPeg, destinationPeg);
    }
}