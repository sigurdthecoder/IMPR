#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int top_row_1to6(int *ptr, int n, int which_side)
{
    int i, counter = 0;

    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) == which_side)
        {
            counter = counter + 1;
        }
    }

    return counter * which_side;
}

int pair_1(int *ptr, int n)
{
    int i, d, the_two = 0;

    for (i = 0; i < n; i++)
    {
        for (d = 0; d < n; d++)
        {

            if (*(ptr + i) == *(ptr + d) && *(ptr + i) + *(ptr + d) > the_two && i != d)
            {
                the_two = *(ptr + i) + *(ptr + d);
            }
        }
    }

    return the_two;
}

int pair_2(int *ptr, int n)
{
    int i, d, counter = 0, pairs[2] = {0, 0};
    
    //finding first pair
    for (i = 0; i < n; i++)
    {
        for (d = 0; d < n; d++)
        {

            if (*(ptr + i) == *(ptr + d) && *(ptr + i) + *(ptr + d) > pairs[0] && i != d)
            {
                pairs[0] = *(ptr + i) + *(ptr + d);
            }
        }
    }

    // eliminating first pair from the roll
    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) == pairs[0] / 2)
        {
            *(ptr + i) = 0;
            counter = counter + 1;
        }

        if (counter == 2)
        {
            break;
        }
    }

    // finding second pair
    for (i = 0; i < n; i++)
    {
        for (d = 0; d < n; d++)
        {

            if (*(ptr + i) == *(ptr + d) && *(ptr + i) + *(ptr + d) > pairs[1] && i != d)
            {
                pairs[1] = *(ptr + i) + *(ptr + d);
            }
        }
    }

    if (pairs[0] == 0 || pairs[1] == 0)
    {
        return 0;
    }
    else
    {
        return pairs[0] + pairs[1];
    }
}

int alike_3_4(int *ptr, int n, int number)
{
    int i, k, result = 0, counter = 0, dice[6] = {1, 2, 3, 4, 5, 6};

    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (*(ptr + k) == dice[i])
            {
                counter = counter + 1;
            }
        }

        if (counter >= number && (dice[i] * number) > result)
        {
            result = dice[i] * number;
        }

        counter = 0;
    }

    return result;
}

int small_straight(int *ptr, int n)
{
    int i, k, small_straight = 0, dice[6] = {1, 2, 3, 4, 5, 6};

    for (i = 0; i < 5; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (*(ptr + k) == dice[i])
            {
                small_straight = small_straight + dice[i];

                break;
            }
        }
    }

    if (small_straight == 15)
    {
        return 15;
    }
    else
    {
        return 0;
    }
}

int big_straight(int *ptr, int n)
{
    int i, k, big_straight = 0, dice[6] = {1, 2, 3, 4, 5, 6};

    for (i = 1; i < 6; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (*(ptr + k) == dice[i])
            {
                big_straight = big_straight + dice[i];
                break;
            }
        }
    }

    if (big_straight == 20)
    {
        return 20;
    }
    else
    {
        return 0;
    }
}

int fullhouse(int *ptr, int n)
{
    int i, k, j, counter = 0, the_three = 0, the_two = 0, dice[6] = {1, 2, 3, 4, 5, 6};

    // finding 3 biggest alike
    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (*(ptr + k) == dice[i])
            {
                counter = counter + 1;
            }
        }

        if (counter >= 3 && (dice[i] * 3) > the_three)
        {
            the_three = dice[i] * 3;
        }

        counter = 0;
    }

    // eliminating found three numbers
    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) == the_three / 3)
        {
            *(ptr + i) = 0;
        }
    }

    // finding 2 biggest alike
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((*(ptr + i) == *(ptr + j)) && (*(ptr + i) + *(ptr + j)) > the_two && i != j)
            {
                the_two = *(ptr + i) + *(ptr + j);
            }
        }
    }

    if (the_three == 0 || the_two == 0)
    {
        return 0;
    }

    else

    {
        return the_three + the_two;
    }
}

int chance(int *ptr, int n)
{
    int i, k, counter = 0, chance = 0, dice[6] = {6, 5, 4, 3, 2, 1};

    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (dice[i] == *(ptr + k))
            {
                counter = counter + 1;
                chance = chance + dice[i];

                if (counter == 5)
                {
                    break;
                }
            }
        }

        if (counter == 5)
        {
            break;
        }
    }

    return chance;
}

int yatzy(int *ptr, int n)
{
    int i, k, counter = 0, yatzy = 0, dice[6] = {1, 2, 3, 4, 5, 6};

    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < 15; k++)
        {
            if (*(ptr + k) == dice[i])
            {
                counter = counter + 1;
            }
        }

        if (counter >= 5 && (dice[i] * 5) > yatzy)
        {
            yatzy = dice[i] * 5;
        }

        counter = 0;
    }

    return yatzy;
}
