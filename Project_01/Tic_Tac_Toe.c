#include <stdio.h>

int main()
{
    int c1, c2, c3,
        c4, c5, c6,
        c7, c8, c9;

    int pos, winner, moves;
    int again;
    /* value == 0 means empty, 1 == X (bot), 2 == O (human) */
    do
    {
        c1 = 0;
        c2 = 0;
        c3 = 0;
        c4 = 0;
        c5 = 0;
        c6 = 0;
        c7 = 0;
        c8 = 0;
        c9 = 0;

        winner = 0;
        moves = 0;

        printf("\n=========================================\n");
        printf("       TIC TAC TOE  -  You vs Bot\n");
        printf("=========================================\n");
        printf("       [You are O   |   Bot is X]\n");
        printf("\nBoard Positions:\n");
        printf("   1 | 2 | 3\n");
        printf("  -----------\n");
        printf("   4 | 5 | 6\n");
        printf("  -----------\n");
        printf("   7 | 8 | 9\n\n");

        while (winner == 0 && moves < 9)
        {
            /*  display board  */
            printf("Current Board:\n");

            if (c1 == 0)
                printf("   1");
            else if (c1 == 1)
                printf("   X");
            else
                printf("   O");
            printf(" |");
            if (c2 == 0)
                printf(" 2");
            else if (c2 == 1)
                printf(" X");
            else
                printf(" O");
            printf(" |");
            if (c3 == 0)
                printf(" 3");
            else if (c3 == 1)
                printf(" X");
            else
                printf(" O");
            printf("\n  ----------\n");

            if (c4 == 0)
                printf("   4");
            else if (c4 == 1)
                printf("   X");
            else
                printf("   O");
            printf(" |");
            if (c5 == 0)
                printf(" 5");
            else if (c5 == 1)
                printf(" X");
            else
                printf(" O");
            printf(" |");
            if (c6 == 0)
                printf(" 6");
            else if (c6 == 1)
                printf(" X");
            else
                printf(" O");
            printf("\n  ----------\n");

            if (c7 == 0)
                printf("   7");
            else if (c7 == 1)
                printf("   X");
            else
                printf("   O");
            printf(" |");
            if (c8 == 0)
                printf(" 8");
            else if (c8 == 1)
                printf(" X");
            else
                printf(" O");
            printf(" |");
            if (c9 == 0)
                printf(" 9");
            else if (c9 == 1)
                printf(" X");
            else
                printf(" O");
            printf("\n\n");

            /*HUMAN TURN  (O = 2)*/

            /* auto-fill if only 1 cell left */
            int free_cells = (c1 == 0) + (c2 == 0) + (c3 == 0) +
                             (c4 == 0) + (c5 == 0) + (c6 == 0) +
                             (c7 == 0) + (c8 == 0) + (c9 == 0);

            if (free_cells == 1)
            {
                if (c1 == 0)
                    pos = 1;
                else if (c2 == 0)
                    pos = 2;
                else if (c3 == 0)
                    pos = 3;
                else if (c4 == 0)
                    pos = 4;
                else if (c5 == 0)
                    pos = 5;
                else if (c6 == 0)
                    pos = 6;
                else if (c7 == 0)
                    pos = 7;
                else if (c8 == 0)
                    pos = 8;
                else
                    pos = 9;

                printf("  Only one cell left! Your move is automatically placed at position %d.\n\n", pos);

                if (pos == 1)
                    c1 = 2;
                else if (pos == 2)
                    c2 = 2;
                else if (pos == 3)
                    c3 = 2;
                else if (pos == 4)
                    c4 = 2;
                else if (pos == 5)
                    c5 = 2;
                else if (pos == 6)
                    c6 = 2;
                else if (pos == 7)
                    c7 = 2;
                else if (pos == 8)
                    c8 = 2;
                else
                    c9 = 2;

                moves++;

                if (
                    (c1 == 2 && c2 == 2 && c3 == 2) ||
                    (c4 == 2 && c5 == 2 && c6 == 2) ||
                    (c7 == 2 && c8 == 2 && c9 == 2) ||
                    (c1 == 2 && c4 == 2 && c7 == 2) ||
                    (c2 == 2 && c5 == 2 && c8 == 2) ||
                    (c3 == 2 && c6 == 2 && c9 == 2) ||
                    (c1 == 2 && c5 == 2 && c9 == 2) ||
                    (c3 == 2 && c5 == 2 && c7 == 2))
                {
                    winner = 2;
                }

                break;
            }

            printf("Your turn, enter a position (1-9): ");
            scanf("%d", &pos);

            if (pos < 1 || pos > 9)
            {
                printf("  Invalid! Enter 1-9.\n\n");

                int ch;
                while (1)
                {
                    scanf("%c", &ch);

                    if (ch == '\n')
                    {
                        break;
                    }
                }
                continue;
            }

            do
            {
                if (pos < 1 || pos > 9)
                {
                    printf("  Invalid! Enter 1-9.\n\n");
                }
                else if (pos == 1 && c1 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 2 && c2 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 3 && c3 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 4 && c4 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 5 && c5 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 6 && c6 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 7 && c7 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 8 && c8 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else if (pos == 9 && c9 != 0)
                {
                    printf("\n  Cell taken! Try again.\n\n");
                }
                else
                {
                    break; /* valid move */
                }

                {
                    int ch;

                    while (1)
                    {
                        scanf("%c", &ch);

                        if (ch == '\n')
                        {
                            break;
                        }
                    }
                }

                printf("Your turn, enter a position (1-9): ");
                int result = scanf("%d", &pos);

                if (result != 1)
                {
                    pos = 0;
                }

            } while (1);

            if (pos == 1)
                c1 = 2;
            else if (pos == 2)
                c2 = 2;
            else if (pos == 3)
                c3 = 2;
            else if (pos == 4)
                c4 = 2;
            else if (pos == 5)
                c5 = 2;
            else if (pos == 6)
                c6 = 2;
            else if (pos == 7)
                c7 = 2;
            else if (pos == 8)
                c8 = 2;
            else if (pos == 9)
                c9 = 2;

            moves++;

            if (
                (c1 == 2 && c2 == 2 && c3 == 2) ||
                (c4 == 2 && c5 == 2 && c6 == 2) ||
                (c7 == 2 && c8 == 2 && c9 == 2) ||
                (c1 == 2 && c4 == 2 && c7 == 2) ||
                (c2 == 2 && c5 == 2 && c8 == 2) ||
                (c3 == 2 && c6 == 2 && c9 == 2) ||
                (c1 == 2 && c5 == 2 && c9 == 2) ||
                (c3 == 2 && c5 == 2 && c7 == 2))
            {
                winner = 2;
            }

            if (winner != 0 || moves == 9)
                break;

            /*BOT TURN  (X = 1)(making it unbeatable)*/

            pos = 0;

            /*1. BOT WIN */
            if (pos == 0 && c1 == 1 && c2 == 1 && c3 == 0)
                pos = 3;
            if (pos == 0 && c1 == 1 && c3 == 1 && c2 == 0)
                pos = 2;
            if (pos == 0 && c2 == 1 && c3 == 1 && c1 == 0)
                pos = 1;

            if (pos == 0 && c4 == 1 && c5 == 1 && c6 == 0)
                pos = 6;
            if (pos == 0 && c4 == 1 && c6 == 1 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 1 && c6 == 1 && c4 == 0)
                pos = 4;

            if (pos == 0 && c7 == 1 && c8 == 1 && c9 == 0)
                pos = 9;
            if (pos == 0 && c7 == 1 && c9 == 1 && c8 == 0)
                pos = 8;
            if (pos == 0 && c8 == 1 && c9 == 1 && c7 == 0)
                pos = 7;

            if (pos == 0 && c1 == 1 && c4 == 1 && c7 == 0)
                pos = 7;
            if (pos == 0 && c1 == 1 && c7 == 1 && c4 == 0)
                pos = 4;
            if (pos == 0 && c4 == 1 && c7 == 1 && c1 == 0)
                pos = 1;

            if (pos == 0 && c2 == 1 && c5 == 1 && c8 == 0)
                pos = 8;
            if (pos == 0 && c2 == 1 && c8 == 1 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 1 && c8 == 1 && c2 == 0)
                pos = 2;

            if (pos == 0 && c3 == 1 && c6 == 1 && c9 == 0)
                pos = 9;
            if (pos == 0 && c3 == 1 && c9 == 1 && c6 == 0)
                pos = 6;
            if (pos == 0 && c6 == 1 && c9 == 1 && c3 == 0)
                pos = 3;

            if (pos == 0 && c1 == 1 && c5 == 1 && c9 == 0)
                pos = 9;
            if (pos == 0 && c1 == 1 && c9 == 1 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 1 && c9 == 1 && c1 == 0)
                pos = 1;

            if (pos == 0 && c3 == 1 && c5 == 1 && c7 == 0)
                pos = 7;
            if (pos == 0 && c3 == 1 && c7 == 1 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 1 && c7 == 1 && c3 == 0)
                pos = 3;

            /*  2. BLOCK HUMAN WIN */
            if (pos == 0 && c1 == 2 && c2 == 2 && c3 == 0)
                pos = 3;
            if (pos == 0 && c1 == 2 && c3 == 2 && c2 == 0)
                pos = 2;
            if (pos == 0 && c2 == 2 && c3 == 2 && c1 == 0)
                pos = 1;

            if (pos == 0 && c4 == 2 && c5 == 2 && c6 == 0)
                pos = 6;
            if (pos == 0 && c4 == 2 && c6 == 2 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 2 && c6 == 2 && c4 == 0)
                pos = 4;

            if (pos == 0 && c7 == 2 && c8 == 2 && c9 == 0)
                pos = 9;
            if (pos == 0 && c7 == 2 && c9 == 2 && c8 == 0)
                pos = 8;
            if (pos == 0 && c8 == 2 && c9 == 2 && c7 == 0)
                pos = 7;

            if (pos == 0 && c1 == 2 && c4 == 2 && c7 == 0)
                pos = 7;
            if (pos == 0 && c1 == 2 && c7 == 2 && c4 == 0)
                pos = 4;
            if (pos == 0 && c4 == 2 && c7 == 2 && c1 == 0)
                pos = 1;

            if (pos == 0 && c2 == 2 && c5 == 2 && c8 == 0)
                pos = 8;
            if (pos == 0 && c2 == 2 && c8 == 2 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 2 && c8 == 2 && c2 == 0)
                pos = 2;

            if (pos == 0 && c3 == 2 && c6 == 2 && c9 == 0)
                pos = 9;
            if (pos == 0 && c3 == 2 && c9 == 2 && c6 == 0)
                pos = 6;
            if (pos == 0 && c6 == 2 && c9 == 2 && c3 == 0)
                pos = 3;

            if (pos == 0 && c1 == 2 && c5 == 2 && c9 == 0)
                pos = 9;
            if (pos == 0 && c1 == 2 && c9 == 2 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 2 && c9 == 2 && c1 == 0)
                pos = 1;

            if (pos == 0 && c3 == 2 && c5 == 2 && c7 == 0)
                pos = 7;
            if (pos == 0 && c3 == 2 && c7 == 2 && c5 == 0)
                pos = 5;
            if (pos == 0 && c5 == 2 && c7 == 2 && c3 == 0)
                pos = 3;

            /*3. BLOCK ALL FORK THREATS */

            if (pos == 0 && c1 == 2 && c9 == 2 && c5 == 1 && c2 == 0)
                pos = 2;
            if (pos == 0 && c3 == 2 && c7 == 2 && c5 == 1 && c2 == 0)
                pos = 2;

            if (pos == 0 && c1 == 2 && c7 == 2 && c4 == 0)
                pos = 4;
            if (pos == 0 && c1 == 2 && c3 == 2 && c2 == 0)
                pos = 2;
            if (pos == 0 && c3 == 2 && c9 == 2 && c6 == 0)
                pos = 6;
            if (pos == 0 && c7 == 2 && c9 == 2 && c8 == 0)
                pos = 8;

            if (pos == 0 && c1 == 2 && c9 == 2 && c5 == 1 && c4 == 0)
                pos = 4;
            if (pos == 0 && c1 == 2 && c9 == 2 && c5 == 1 && c6 == 0)
                pos = 6;
            if (pos == 0 && c3 == 2 && c7 == 2 && c5 == 1 && c4 == 0)
                pos = 4;
            if (pos == 0 && c3 == 2 && c7 == 2 && c5 == 1 && c6 == 0)
                pos = 6;

            if (pos == 0 && c1 == 2 && c9 == 2 && c5 == 1)
            {
                if (c2 == 0)
                    pos = 2;
                else if (c4 == 0)
                    pos = 4;
                else if (c6 == 0)
                    pos = 6;
                else if (c8 == 0)
                    pos = 8;
            }
            if (pos == 0 && c3 == 2 && c7 == 2 && c5 == 1)
            {
                if (c2 == 0)
                    pos = 2;
                else if (c4 == 0)
                    pos = 4;
                else if (c6 == 0)
                    pos = 6;
                else if (c8 == 0)
                    pos = 8;
            }

            if (pos == 0 && c1 == 2 && c7 == 2 && c9 == 2)
            {
                if (c4 == 0)
                    pos = 4;
                else if (c8 == 0)
                    pos = 8;
            }

            if (pos == 0 && c1 == 2 && c9 == 2 && c5 == 1 && c3 == 0 && c7 == 0)
            {
                if (c2 == 0)
                    pos = 2;
            }

            if (pos == 0 && c1 == 2 && c7 == 2 && c5 == 1 && c4 == 0)
                pos = 4;
            if (pos == 0 && c7 == 2 && c9 == 2 && c5 == 1 && c8 == 0)
                pos = 8;
            if (pos == 0 && c1 == 2 && c3 == 2 && c5 == 1 && c2 == 0)
                pos = 2;
            if (pos == 0 && c3 == 2 && c9 == 2 && c5 == 1 && c6 == 0)
                pos = 6;

            if (pos == 0 && c5 == 1)
            {
                /* Blocking Corners
                 hc = human occupied corners
                 bc = bot occupied corners
                 */
                int hc = (c1 == 2) + (c3 == 2) + (c7 == 2) + (c9 == 2);
                int bc = (c1 == 1) + (c3 == 1) + (c7 == 1) + (c9 == 1);
                if (hc >= 2 && bc == 0)
                {
                    if (c2 == 0)
                        pos = 2;
                    else if (c4 == 0)
                        pos = 4;
                    else if (c6 == 0)
                        pos = 6;
                    else if (c8 == 0)
                        pos = 8;
                }
            }

            if (pos == 0 && c2 == 2 && c4 == 2 && c1 == 0)
                pos = 1;
            if (pos == 0 && c2 == 2 && c6 == 2 && c3 == 0)
                pos = 3;
            if (pos == 0 && c4 == 2 && c8 == 2 && c7 == 0)
                pos = 7;
            if (pos == 0 && c6 == 2 && c8 == 2 && c9 == 0)
                pos = 9;

            /* 4. CENTER */
            if (pos == 0 && c5 == 0)
                pos = 5;

            /* 5. OPPOSITE CORNER */
            if (pos == 0 && c1 == 2 && c9 == 0)
                pos = 9;
            if (pos == 0 && c9 == 2 && c1 == 0)
                pos = 1;
            if (pos == 0 && c3 == 2 && c7 == 0)
                pos = 7;
            if (pos == 0 && c7 == 2 && c3 == 0)
                pos = 3;

            /* 6. ANY CORNER */
            if (pos == 0 && c1 == 0)
                pos = 1;
            if (pos == 0 && c3 == 0)
                pos = 3;
            if (pos == 0 && c7 == 0)
                pos = 7;
            if (pos == 0 && c9 == 0)
                pos = 9;

            /* 7. ANY SIDE */
            if (pos == 0 && c2 == 0)
                pos = 2;
            if (pos == 0 && c4 == 0)
                pos = 4;
            if (pos == 0 && c6 == 0)
                pos = 6;
            if (pos == 0 && c8 == 0)
                pos = 8;

            /* place bot mark */
            if (pos == 1)
                c1 = 1;
            else if (pos == 2)
                c2 = 1;
            else if (pos == 3)
                c3 = 1;
            else if (pos == 4)
                c4 = 1;
            else if (pos == 5)
                c5 = 1;
            else if (pos == 6)
                c6 = 1;
            else if (pos == 7)
                c7 = 1;
            else if (pos == 8)
                c8 = 1;
            else if (pos == 9)
                c9 = 1;

            printf("\n  Bot chose position %d\n\n", pos);
            moves++;

            /* check bot win */
            if (
                (c1 == 1 && c2 == 1 && c3 == 1) ||
                (c4 == 1 && c5 == 1 && c6 == 1) ||
                (c7 == 1 && c8 == 1 && c9 == 1) ||
                (c1 == 1 && c4 == 1 && c7 == 1) ||
                (c2 == 1 && c5 == 1 && c8 == 1) ||
                (c3 == 1 && c6 == 1 && c9 == 1) ||
                (c1 == 1 && c5 == 1 && c9 == 1) ||
                (c3 == 1 && c5 == 1 && c7 == 1))
            {
                winner = 1;
            }

        } /* end while */

        /* final board */
        printf("  Current Board:\n");

        printf(" ");

        if (c1 == 0)
            printf("   1");
        else if (c1 == 1)
            printf("   X");
        else
            printf("   O");

        printf(" | ");

        if (c2 == 0)
            printf("2");
        else if (c2 == 1)
            printf("X");
        else
            printf("O");

        printf(" | ");

        if (c3 == 0)
            printf("3");
        else if (c3 == 1)
            printf("X");
        else
            printf("O");

        printf("\n  -----------\n");

        printf(" ");

        if (c4 == 0)
            printf("   4");
        else if (c4 == 1)
            printf("   X");
        else
            printf("   O");

        printf(" | ");

        if (c5 == 0)
            printf("5");
        else if (c5 == 1)
            printf("X");
        else
            printf("O");

        printf(" | ");

        if (c6 == 0)
            printf("6");
        else if (c6 == 1)
            printf("X");
        else
            printf("O");

        printf("\n  -----------\n");

        printf(" ");
        if (c7 == 0)
            printf("   7");
        else if (c7 == 1)
            printf("   X");
        else
            printf("   O");

        printf(" | ");

        if (c8 == 0)
            printf("8");
        else if (c8 == 1)
            printf("X");
        else
            printf("O");

        printf(" | ");

        if (c9 == 0)
            printf("9");
        else if (c9 == 1)
            printf("X");
        else
            printf("O");

        printf("\n\n");

        if (winner == 2)
            printf("* Congratulations! You Win! *\n\n");
        else if (winner == 1)
            printf("* You Lose! Bot Wins! *\n\n");
        else
            printf("* It's a Tie! *\n\n");

        printf("Enter 'r' to play again, or 'q' to quit: ");
        scanf(" %c", &again);

    } while (again != 'q' && again != 'Q');

    printf("\nThanks for playing!\n");
    return 0;
}

/*
   ---List of online references used for learning purposes ---
    1.https://en.wikipedia.org/wiki/Tic-tac-toe#Strategy (helped to understand the strategies to create an unbeatable tictactoe gamebot)
    2.Conditional and loops in C by Neso Academy (helped to understand C language essentials more effectively to buid the bot applying the strategies)


 */