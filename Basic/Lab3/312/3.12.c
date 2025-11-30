#include <stdio.h>

int main() {
    int numberOfCalculations;
    int attackerLevel, opponentLevel, opponentArmor;
    float baseAttack;
    float damageReduction;
    float netDamage;
    float damageDeficit;
    const float WORTH_THRESHOLD = 50.0f;  


    if (scanf("%d", &numberOfCalculations) != 1) {
        return 1;
    }


    for (int i = 0; i < numberOfCalculations; i++) {


        if (scanf("%d %d %d",
                  &attackerLevel,
                  &opponentLevel,
                  &opponentArmor) != 3) {
            return 1;
        }


        baseAttack = attackerLevel * 10.0f;


        if (opponentArmor < 50) {
            damageReduction = 0.20f;
        } else {
            damageReduction = 0.40f;
        }


        netDamage = baseAttack * (1.0f - damageReduction);


        if (netDamage >= WORTH_THRESHOLD) {
            printf("SUCCESS! Net Damage: %.2f\n", netDamage);
        } else {
            damageDeficit = WORTH_THRESHOLD - netDamage;
            printf("FAILURE! Damage Deficit: %.2f\n", damageDeficit);
        }
    }

    return 0;
}
