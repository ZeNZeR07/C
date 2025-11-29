#include <stdio.h>


int main() {
    int N_CALCULATETIONS;
    int attkLvl, oppLvl, oppArmor;
    float baseAttack, damageReduction, netDamage, damageDeficit;
    const float WORTH_THRESHOLD = 50.0;



    if(scanf("%d", &N_CALCULATETIONS) != 1) {
        return 1;
    }
    for(int i = 0; i < N_CALCULATETIONS; i++) {
        if(scanf("%d %d %d", &attkLvl, &oppLvl, &oppArmor) != 3) {
            return 1;
        }

        baseAttack = attkLvl * 10.0;


        if(oppArmor < 50) {
            damageReduction = 0.20;
        } else {
            damageReduction = 0.40;
        }

        netDamage = baseAttack * (1.0 - damageReduction);

        if(netDamage >= WORTH_THRESHOLD){
            printf("SUCCESS! Net Damage: %.2f\n", netDamage);
        }
        else {
            damageDeficit = WORTH_THRESHOLD - netDamage;
            printf("FAILURE! Damage Deficit: %.2f\n", damageDeficit);
        }   
    }

    return 0;
}