#include <stdio.h>

int main()
{
    char p[1000];
    int i, length;
    int l, u, s;

    while (1)
    {
        l = 0;
        u = 0;
        s = 0;
        length = 0;

        printf("Enter password: ");
        scanf("%s", p);

        for (i = 0; p[i] != '\0'; i++)
        {
            length++;

            // Uppercase and lowercase check
            if (p[i] >= 'A' && p[i] <= 'Z')
                u++;

            else if (p[i] >= 'a' && p[i] <= 'z')
                l++;

            // Special character check
            else if (p[i] == '@' ||
                     p[i] == '#' ||
                     p[i] == '$' ||
                     p[i] == '&' ||
                     p[i] == '/' ||
                     p[i] == '*' ||
                     p[i] == '|')
                s++;
        }

        if (length < 8)
        {
            printf("Password Error: Minimum 8 characters required.\n\n");
            continue;
        }

        if (u == 0)
        {
            printf("Password Error: Uppercase letter required.\n\n");
            continue;
        }

        if (l == 0)
        {
            printf("Password Error: Lowercase letter required.\n\n");
            continue;
        }

        if (s == 0)
        {
            printf("Password Error: Special character required.\n\n");
            continue;
        }

        printf("Password accepted successfully.\n");
        break;
    }

    return 0;
}
