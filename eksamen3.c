#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"

int main()
{
    match_data md_array[102];
    team_data teams[12];

    get_data(md_array);

    arrange_teams(teams);

    play_matches(md_array, teams);

    sort_teams(teams);

    print_result(teams);

    return 0;
}