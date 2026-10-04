#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *in = fopen("titanic.csv", "r");
    FILE *out = fopen("titanic_edited.csv", "w");

    if (in == NULL || out == NULL)
    {
        printf("Error: Could not open files.\n");
        return 1;
    }

    char line[1024];
    if (fgets(line, sizeof(line), in) != NULL)
    {
        line[strcspn(line, "\r\n")] = '\0';
        fprintf(out, "%s,Age_Category\n", line);
    }

    while (fgets(line, sizeof(line), in) != NULL)
    {
        line[strcspn(line, "\r\n")] = '\0';

        int comma_count = 0;
        int in_quotes = 0;
        char age_str[50] = "";
        int age_idx = 0;

        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] == '"')
            {
                in_quotes = !in_quotes;
            }
            else if (line[i] == ',' && !in_quotes)
            {
                comma_count++;
            }
            else if (comma_count == 5)
            {
                age_str[age_idx++] = line[i];
            }
        }
        age_str[age_idx] = '\0';

        char category[20];
        if (strlen(age_str) == 0)
        {
            strcpy(category, "Unknown");
        }
        else
        {
            int age = atof(age_str);
            if (age < 18)
            {
                strcpy(category, "Child");
            }
            else if (age <= 40)
            {
                strcpy(category, "Adult");
            }
            else
            {
                strcpy(category, "Senior Citizen");
            }
        }

        fprintf(out, "%s,%s\n", line, category);
    }

    fclose(in);
    fclose(out);

    printf("Successfully Created 'titanic_edited.csv' with 'Age_Category'.\n");
    return 0;
}