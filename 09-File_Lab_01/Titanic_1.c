#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("titanic.csv", "r");
    if (file == NULL)
    {
        printf("Could not open the file!\n");
        return 1;
    }

    char line[500];
    int total_passengers = 0;
    int total_males = 0;
    int total_females = 0;
    int males_survived = 0;
    int females_survived = 0;

    if (fgets(line, sizeof(line), file) == NULL)
    {
        printf("File is empty!\n");
        fclose(file);
        return 1;
    }
    while (fgets(line, sizeof(line), file))
    {
        char *fields[20];
        int field_count = 0;
        int in_quotes = 0;
        char *start = line;

        for (char *p = line; *p != '\0'; p++)
        {
            if (*p == '"')
            {
                in_quotes = !in_quotes;
            }
            else if (*p == ',' && !in_quotes)
            {
                *p = '\0';
                fields[field_count++] = start;
                start = p + 1;
            }
        }
        fields[field_count++] = start;

        if (field_count >= 5)
        {
            int survived = atoi(fields[1]);
            char *sex = fields[4];

            if (strstr(sex, "female") != NULL)
            {
                total_passengers++;
                total_females++;
                if (survived == 1)
                {
                    females_survived++;
                }
            }
            else if (strstr(sex, "male") != NULL)
            {
                total_passengers++;
                total_males++;
                if (survived == 1)
                {
                    males_survived++;
                }
            }
        }
    }

    fclose(file);

    if (total_passengers == 0)
    {
        printf("No valid data.\n");
        return 0;
    }

    printf("\nTitanic Survival Statistics\n");
    printf("Male Survival - \n");
    printf("Percentage among Total Males: %.2f%%\n", (total_males > 0) ? ((float)males_survived / total_males) * 100 : 0.0);
    printf("Percentage among Total Passengers: %.2f%%\n\n", ((float)males_survived / total_passengers) * 100);

    printf("Female Survival -\n");
    printf("Percentage among Total Females: %.2f%%\n", (total_females > 0) ? ((float)females_survived / total_females) * 100 : 0.0);
    printf("Percentage among Total Passengers: %.2f%%\n", ((float)females_survived / total_passengers) * 100);

    return 0;
}