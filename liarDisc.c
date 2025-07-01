#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DICE 5

typedef struct {
    int dice[MAX_DICE];
    int num_dice;
} Player;

void roll_dice(Player* player) {
    for (int i = 0; i < player->num_dice; i++) {
        player->dice[i] = (rand() % 6) + 1;
    }
}

void print_dice(Player* player) {
    for (int i = 0; i < player->num_dice; i++) {
        printf("%d ", player->dice[i]);
    }
    printf("\n");
}

int count_dice(Player* player, int value) {
    int count = 0;
    for (int i = 0; i < player->num_dice; i++) {
        if (player->dice[i] == value) {
            count++;
        }
    }
    return count;
}

int is_valid_bet(int new_num, int new_val, int cur_num, int cur_val) {
    if (new_num > cur_num || (new_num == cur_num && new_val > cur_val)) {
        return 1;
    }
    return 0;
}

void ai_make_bet(int *bet_num, int *bet_val, int cur_num, int cur_val) {
    do {
        *bet_num = (rand() % MAX_DICE) + 1;
        *bet_val = (rand() % 6) + 1;
    } while (!is_valid_bet(*bet_num, *bet_val, cur_num, cur_val));
}

void print_game_info(Player *human, Player *ai, int bet_num, int bet_val) {
    printf("Game State:\n");
    printf("Opponent Hand Size: %d\n", ai->num_dice);
    printf("Your Hand Size: %d\n", human->num_dice);
    printf("Dice you rolled: ");
    print_dice(human);
    printf("Opponent Bet: %d %d's\n", bet_num, bet_val);
}

int main() {
    srand(time(NULL));
    
    Player human = {.num_dice = MAX_DICE};
    Player ai = {.num_dice = MAX_DICE};
    
    int bet_num = 0, bet_val = 0;
    char choice[10];
    
    while (human.num_dice > 0 && ai.num_dice > 0) {
        roll_dice(&human);
        roll_dice(&ai);
        
        // AI makes the first bet
        ai_make_bet(&bet_num, &bet_val, 0, 0);
        printf("New Round!\n");
        printf("Opponent Bet: %d %d's\n", bet_num, bet_val);
        
        while (1) {
            print_game_info(&human, &ai, bet_num, bet_val);
            
            printf("Make your play:\n0 - Raise\n1 - Call Bluff\n");
            scanf("%s", choice);
            
            if (strcmp(choice, "0") == 0) {
                int new_bet_num, new_bet_val;
                printf("Enter your bet: ");
                scanf("%d %d", &new_bet_num, &new_bet_val);
                
                if (!is_valid_bet(new_bet_num, new_bet_val, bet_num, bet_val)) {
                    printf("Invalid bet. Try again.\n");
                } else {
                    bet_num = new_bet_num;
                    bet_val = new_bet_val;
                    printf("You make a new bet.\n");
                    // AI responds with a bet or call
                    if (rand() % 2 == 0) { // AI decides to call
                        printf("Opponent calls your bluff!\n");
                        int total_count = count_dice(&human, bet_val) + count_dice(&ai, bet_val);
                        printf("There were %d %d's\n", total_count, bet_val);
                        
                        if (total_count >= bet_num) {
                            printf("Opponent successfully called the bluff, you lose a dice.\n");
                            human.num_dice--;
                        } else {
                            printf("You successfully called the bluff, opponent loses a dice.\n");
                            ai.num_dice--;
                        }
                        break;
                    } else { // AI makes a new bet
                        ai_make_bet(&bet_num, &bet_val, bet_num, bet_val);
                        printf("Opponent makes a new bet.\n");
                    }
                }
            } else if (strcmp(choice, "1") == 0) {
                printf("You call the bluff!\n");
                int total_count = count_dice(&human, bet_val) + count_dice(&ai, bet_val);
                printf("There were %d %d's\n", total_count, bet_val);
                
                if (total_count >= bet_num) {
                    printf("Opponent successfully called the bluff, you lose a dice.\n");
                    human.num_dice--;
                } else {
                    printf("You successfully called the bluff, opponent loses a dice.\n");
                    ai.num_dice--;
                }
                break;
            }
        }
        
        printf("\n");
    }
    
    if (human.num_dice == 0) {
        printf("Opponent wins the game!\n");
    } else {
        printf("You win the game!\n");
    }
    
    return 0;
}
