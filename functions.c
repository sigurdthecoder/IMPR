#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"

void get_data(match_data md_array[102])
{
    FILE *file = fopen("kampe-2022-2023.txt", "r");
    char line[100];
    int i = 0;

    for (i = 0; i < 102; i++)
    {
        fgets(line, 100, file);

        sscanf(line, "%s %s %s %s - %s %d - %d %d", md_array[i].week_day, md_array[i].date, md_array[i].time_of_day, md_array[i].home_team, md_array[i].away_team, &md_array[i].home_team_goals, &md_array[i].away_team_goals, &md_array[i].audience);
    }

    fclose(file);
}

void arrange_teams(team_data teams[12])
{
    strcpy(teams[0].team_name, "FCM");
    strcpy(teams[1].team_name, "RFC");
    strcpy(teams[2].team_name, "VFF");
    strcpy(teams[3].team_name, "AaB");
    strcpy(teams[4].team_name, "LBK");
    strcpy(teams[5].team_name, "SIF");
    strcpy(teams[6].team_name, "FCK");
    strcpy(teams[7].team_name, "ACH");
    strcpy(teams[8].team_name, "BIF");
    strcpy(teams[9].team_name, "AGF");
    strcpy(teams[10].team_name, "OB");
    strcpy(teams[11].team_name, "FCN");
}

int name_to_index(char team_name[MAX_LENGHT])
{

    if (strcmp(team_name, "FCM") == 0)
    {
        return 0;
    }
    else if (strcmp(team_name, "RFC") == 0)
    {
        return 1;
    }
    else if (strcmp(team_name, "VFF") == 0)
    {
        return 2;
    }
    else if (strcmp(team_name, "AaB") == 0)
    {
        return 3;
    }
    else if (strcmp(team_name, "LBK") == 0)
    {
        return 4;
    }
    else if (strcmp(team_name, "SIF") == 0)
    {
        return 5;
    }
    else if (strcmp(team_name, "FCK") == 0)
    {
        return 6;
    }
    else if (strcmp(team_name, "ACH") == 0)
    {
        return 7;
    }
    else if (strcmp(team_name, "BIF") == 0)
    {
        return 8;
    }
    else if (strcmp(team_name, "AGF") == 0)
    {
        return 9;
    }
    else if (strcmp(team_name, "OB") == 0)
    {
        return 10;
    }
    else if (strcmp(team_name, "FCN") == 0)
    {
        return 11;
    }
}

void play_matches(match_data md_array[102], team_data teams[12])
{
    int i;

    for (i = 0; i < 102; i++)
    {
        if (md_array[i].home_team_goals == md_array[i].away_team_goals)
        {
            teams[name_to_index(md_array[i].home_team)].goals_by_team += md_array[i].home_team_goals;
            teams[name_to_index(md_array[i].away_team)].goals_by_team += md_array[i].away_team_goals;

            teams[name_to_index(md_array[i].home_team)].goals_against_team += md_array[i].away_team_goals;
            teams[name_to_index(md_array[i].away_team)].goals_against_team += md_array[i].home_team_goals;

            teams[name_to_index(md_array[i].home_team)].points += 1;
            teams[name_to_index(md_array[i].away_team)].points += 1;
        }

        else if (md_array[i].home_team_goals > md_array[i].away_team_goals)
        {
            teams[name_to_index(md_array[i].home_team)].goals_by_team += md_array[i].home_team_goals;
            teams[name_to_index(md_array[i].away_team)].goals_by_team += md_array[i].away_team_goals;

            teams[name_to_index(md_array[i].home_team)].goals_against_team += md_array[i].away_team_goals;
            teams[name_to_index(md_array[i].away_team)].goals_against_team += md_array[i].home_team_goals;

            teams[name_to_index(md_array[i].home_team)].points += 3;
        }

        else if (md_array[i].home_team_goals < md_array[i].away_team_goals)
        {
            teams[name_to_index(md_array[i].home_team)].goals_by_team += md_array[i].home_team_goals;
            teams[name_to_index(md_array[i].away_team)].goals_by_team += md_array[i].away_team_goals;

            teams[name_to_index(md_array[i].home_team)].goals_against_team += md_array[i].away_team_goals;
            teams[name_to_index(md_array[i].away_team)].goals_against_team += md_array[i].home_team_goals;

            teams[name_to_index(md_array[i].away_team)].points += 3;
        }
    }
}

void sort_teams(team_data teams[12])
{
    qsort(teams, 12, sizeof(team_data), &compare);
}

int compare(const void *a, const void *b)
{
    team_data *ptr1 = (team_data *)a;
    team_data *ptr2 = (team_data *)b;

    if (ptr1->points > ptr2->points)
    {
        return -1;
    }

    else if (ptr1->points < ptr2->points)

    {
        return 1;
    }

    else if (ptr1->points == ptr2->points)
    {
        int goal_diff1 = ptr1->goals_by_team - ptr1->goals_against_team;
        int goal_diff2 = ptr2->goals_by_team - ptr2->goals_against_team;

        if (goal_diff1 > goal_diff2)
        {
            return -1;
        }

        else if (goal_diff1 < goal_diff2)
        {
            return 1;
        }

        else if (goal_diff1 == goal_diff2)

        {
            return 0;
        }
    }
}

void print_result(team_data teams[12])
{
    int i;

    printf("\n -------------------------------------------------------------------\n|THE POSITION OF EACH TEAM AFTER 102 MATCHES PLAYED IN THE SUPERLIGA|\n -------------------------------------------------------------------");

    for (i = 0; i < 12; i++)
    {

        if (strlen(teams[i].team_name) == 2)
        {
            printf("\n\n|Position %d      ", i + 1);
            printf("Team name: %s     Points: %d    Goals by team: %d    Goals against team: %d", teams[i].team_name, teams[i].points, teams[i].goals_by_team, teams[i].goals_against_team);
        }

        else if (teams[i].points < 10)
        {
            printf("\n\n|Position %d    ", i + 1);
            printf(" Team name: %s    Points: %d     Goals by team: %d    Goals against team: %d", teams[i].team_name, teams[i].points, teams[i].goals_by_team, teams[i].goals_against_team);
        }

        else if (i + 1 > 9)
        {
            printf("\n\n|Position %d     ", i + 1);
            printf("Team name: %s    Points: %d    Goals by team: %d    Goals against team: %d", teams[i].team_name, teams[i].points, teams[i].goals_by_team, teams[i].goals_against_team);
        }

        else
        {
            printf("\n\n|Position %d      ", i + 1);
            printf("Team name: %s    Points: %d    Goals by team: %d    Goals against team: %d", teams[i].team_name, teams[i].points, teams[i].goals_by_team, teams[i].goals_against_team);
        }
    }

    printf("\n");
}
