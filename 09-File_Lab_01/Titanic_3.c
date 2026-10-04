#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total[2][3][4] = {0};
int survived[2][3][4] = {0};

int find_sex(const char *line)
{
    if (strstr(line, ",female,"))
        return 0;
    if (strstr(line, ",male,"))
        return 1;
    return -1;
}

int get_age_cat(const char *line)
{
    if (strstr(line, "Senior Citizen"))
        return 2;
    if (strstr(line, "Child"))
        return 1;
    if (strstr(line, "Adult"))
        return 0;
    if (strstr(line, "Unknown"))
        return 3;
    return -1;
}

int main(void)
{
    FILE *f = fopen("titanic_edited.csv", "r");
    if (!f)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[1024];
    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f))
    {
        int id, surv, pclass;

        if (sscanf(line, "%d,%d,%d", &id, &surv, &pclass) == 3)
        {
            int s = find_sex(line);
            int a = get_age_cat(line);
            int p = pclass - 1;

            if (s != -1 && p >= 0 && p < 3 && a != -1)
            {
                total[s][p][a]++;
                if (surv == 1)
                {
                    survived[s][p][a]++;
                }
            }
        }
    }
    fclose(f);

    const char *sexes[] = {"Female", "Male"};
    const char *ages[] = {"Adult", "Child", "Senior Citizen", "Unknown"};

    printf("%-8s %-8s %-16s %-8s %-8s %-12s\n", "Sex", "Pclass", "Age Category", "Total", "Survived", "Rate (%)");
    printf("-------------------------------------------------------------------\n");

    for (int s = 0; s < 2; s++)
    {
        for (int p = 0; p < 3; p++)
        {
            for (int a = 0; a < 4; a++)
            {
                int t = total[s][p][a];
                int surv_cnt = survived[s][p][a];
                double rate = (t > 0) ? (surv_cnt * 100.0 / t) : 0.0;

                printf("%-8s %-8d %-16s %-8d %-8d %-12.2f\n", sexes[s], p + 1, ages[a], t, surv_cnt, rate);
            }
        }
    }

    return 0;
}