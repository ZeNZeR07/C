#include <stdio.h>

float calculate_win_odds(int outs);

int main(void) {
    int card_outs;
    float win_probability;

   
    card_outs = 6;


    win_probability = calculate_win_odds(card_outs);

    printf("\n--- POKER PROBABILITY REPORT (2 Cards Remaining) ---\n");
    printf("Calculated Outs: %d\n", card_outs);
    printf("Win Probability (Odds x 4): %.2f%%\n", win_probability);

    printf("Assessment: ");
    if (win_probability >= 30.0f) {
        printf("HIGH Win Probability\n");
    } else {
        printf("LOW Win Probability\n");
    }

    return 0;
}


float calculate_win_odds(int outs) {
    return (float)outs * 4.0f;
}
