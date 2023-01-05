#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int *roll_multiple_die(int j, int n);
void score_and_print(int *ptr, int *result_ptr, int j, int n);

int main()
{
    int n = 10, j;
    int *rmd_ptr;
    int result_ptr[16];

    srand(time(NULL));

    printf("\nYatzy with 10 dies :) ");
    printf("\n\n|SCOREBOARD|\n\n");

    for (j = 0; j < 17; j++)
    {
        rmd_ptr = roll_multiple_die(j, n);
        score_and_print(rmd_ptr, result_ptr, j, n);
        free(rmd_ptr);
    }

    return 0;
}

int *roll_multiple_die(int j, int n)
{
    int *dynamic_array = (int *)malloc(n * sizeof(int));
    int i;

    if (dynamic_array == NULL)
    {
        printf("\nMEMORY COULD NOT BE ALLOCATED\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        *(dynamic_array + i) = (rand() % 6) + 1;
    }

    // printing dies
    if (j != 15 && j != 16)
    {
        printf("\nThe roll: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", *(dynamic_array + i));
        }
        printf("\n");
    }

    return dynamic_array;
}

void score_and_print(int *ptr, int *result_ptr, int j, int n)
{
    int i, bonus_mellemregning, bonus = 0, final_result = 0, final_result_mellemregning;

    switch (j)
    {

    // 1's-6's
    case 0:
        *(result_ptr + j) = top_row_1to6(ptr, n, 1);

        printf("1'S : %d\n", *(result_ptr + j));

        break;

    case 1:

        *(result_ptr + j) = top_row_1to6(ptr, n, 2);

        printf("2'S : %d\n", *(result_ptr + j));

        break;

    case 2:

        *(result_ptr + j) = top_row_1to6(ptr, n, 3);

        printf("3'S : %d\n", *(result_ptr + j));

        break;

    case 3:

        *(result_ptr + j) = top_row_1to6(ptr, n, 4);

        printf("4'S : %d\n", *(result_ptr + j));

        break;

    case 4:

        *(result_ptr + j) = top_row_1to6(ptr, n, 5);

        printf("5'S : %d\n", *(result_ptr + j));

        break;

    case 5:

        *(result_ptr + j) = top_row_1to6(ptr, n, 6);

        printf("6'S : %d\n\n", *(result_ptr + j));

        for (i = 0; i < 6; i++)
        {
            bonus_mellemregning = *(result_ptr + i);
            bonus = bonus_mellemregning + bonus;
        }

        if (bonus >= 63)
        {
            *(result_ptr + 15) = 50;
            printf("BONUS : %d\n\n", *(result_ptr + 15));
        }
        else
        {
            *(result_ptr + 15) = 0;
            printf("BONUS : %d\n\n", *(result_ptr + 15));
        }
        break;

    // one pair and two pairs
    case 6:

        *(result_ptr + j) = pair_1(ptr, n);

        printf("ONE PAIR : %d\n", *(result_ptr + j));

        break;

    case 7:

        *(result_ptr + j) = pair_2(ptr, n);

        printf("TWO PAIRS : %d\n", *(result_ptr + j));

        break;

    // 3 alike and 4 alike
    case 8:

        *(result_ptr + j) = alike_3_4(ptr, n, 3);

        printf("THREE ALIKE : %d\n", *(result_ptr + j));

        break;

    case 9:

        *(result_ptr + j) = alike_3_4(ptr, n, 4);

        printf("FOUR ALIKE : %d\n", *(result_ptr + j));

        break;

    // small- and big straight
    case 10:

        *(result_ptr + j) = small_straight(ptr, n);

        printf("SMALL STRAIGHT : %d\n", *(result_ptr + j));

        break;

    case 11:

        *(result_ptr + j) = big_straight(ptr, n);

        printf("BIG STRAIGHT : %d\n", *(result_ptr + j));

        break;

    // full house, chance and yatzy
    case 12:

        *(result_ptr + j) = fullhouse(ptr, n);

        printf("FULL HOUSE : %d\n", *(result_ptr + j));

        break;

    case 13:

        *(result_ptr + j) = chance(ptr, n);

        printf("CHANCE : %d\n", *(result_ptr + j));

        break;

    case 14:

        *(result_ptr + j) = yatzy(ptr, n);

        printf("YATZY : %d\n\n", *(result_ptr + j));

        break;

    // TOTAL
    case 16:

        for (i = 0; i < 16; i++)
        {
            final_result_mellemregning = *(result_ptr + i);
            final_result = final_result + final_result_mellemregning;
        }
        printf("TOTAL : %d\n", final_result);
        break;
    }
}
