#define MAX_LENGHT 50

struct match_data
{
    char week_day[MAX_LENGHT];
    char date[MAX_LENGHT];
    char time_of_day[MAX_LENGHT];
    char home_team[MAX_LENGHT];
    char away_team[MAX_LENGHT];

    int home_team_goals;
    int away_team_goals;
    int audience;
};
typedef struct match_data match_data;

struct team_data
{
    char team_name[MAX_LENGHT];
    int points;
    int goals_by_team;
    int goals_against_team;
};
typedef struct team_data team_data;

void get_data(match_data md_array[102]);

void arrange_teams(team_data teams[12]);

int name_to_index(char team_name[MAX_LENGHT]);

void play_matches(match_data md_array[102], team_data teams[12]);

void sort_teams(team_data teams[12]);

int compare(const void *a, const void *b);

void print_result(team_data teams[12]);
