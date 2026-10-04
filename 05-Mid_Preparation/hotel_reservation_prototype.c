#include <stdio.h>
#include <string.h>

int main()
{
    int reservationID[100];
    char guestName[100][101];
    int roomNumber[100];
    char roomType[100][21];
    char date[100][11];
    float rent[100];
    int occupancyStatus[100];

    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== HOTEL RESERVATION SYSTEM =====\n");
        printf("1. Add New Reservation\n");
        printf("2. Search Reservation by ID\n");
        printf("3. Display All Reservations by Date\n");
        printf("4. Display Vacant Rooms\n");
        printf("5. Calculate Total Yearly Revenue\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Reservation ID: ");
            scanf("%d", &reservationID[count]);

            getchar();

            printf("Guest Name: ");
            fgets(guestName[count], 101, stdin);
            guestName[count][strcspn(guestName[count], "\n")] = '\0';

            printf("Room Number: ");
            scanf("%d", &roomNumber[count]);

            getchar();

            printf("Room Type: ");
            fgets(roomType[count], 21, stdin);
            roomType[count][strcspn(roomType[count], "\n")] = '\0';

            printf("Date (DD/MM/YYYY): ");
            fgets(date[count], 11, stdin);
            date[count][strcspn(date[count], "\n")] = '\0';

            printf("Rent: ");
            scanf("%f", &rent[count]);

            printf("Occupancy Status (1=Occupied,0=Vacant): ");
            scanf("%d", &occupancyStatus[count]);

            count++;

            printf("Reservation Added Successfully!\n");
        }

        else if (choice == 2)
        {
            int id, i, found = 0;

            printf("Enter Reservation ID: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++)
            {
                if (reservationID[i] == id)
                {
                    printf("\nReservation ID : %d\n", reservationID[i]);
                    printf("Guest Name     : %s\n", guestName[i]);
                    printf("Room Number    : %d\n", roomNumber[i]);
                    printf("Room Type      : %s\n", roomType[i]);
                    printf("Date           : %s\n", date[i]);
                    printf("Rent           : %.2f\n", rent[i]);
                    printf("Status         : %d\n", occupancyStatus[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Reservation Not Found.\n");
        }

        else if (choice == 3)
        {
            char searchDate[11];
            int i, found = 0;

            getchar();

            printf("Enter Date (DD/MM/YYYY): ");
            fgets(searchDate, 11, stdin);
            searchDate[strcspn(searchDate, "\n")] = '\0';

            for (i = 0; i < count; i++)
            {
                if (strcmp(date[i], searchDate) == 0)
                {
                    printf("\nReservation ID : %d\n", reservationID[i]);
                    printf("Guest Name     : %s\n", guestName[i]);
                    printf("Room Number    : %d\n", roomNumber[i]);
                    printf("Room Type      : %s\n", roomType[i]);
                    printf("Rent           : %.2f\n", rent[i]);
                    printf("Status         : %d\n", occupancyStatus[i]);
                    found = 1;
                }
            }

            if (!found)
                printf("No Reservation Found.\n");
        }

        else if (choice == 4)
        {
            int room, i, occupied;

            printf("Vacant Rooms:\n");

            for (room = 1; room <= 10; room++)
            {
                occupied = 0;

                for (i = 0; i < count; i++)
                {
                    if (roomNumber[i] == room && occupancyStatus[i] == 1)
                    {
                        occupied = 1;
                        break;
                    }
                }

                if (!occupied)
                    printf("Room %d\n", room);
            }
        }

        else if (choice == 5)
        {
            float total = 0;
            int i;

            for (i = 0; i < count; i++)
                total += rent[i];

            printf("Total Yearly Revenue = %.2f\n", total);
        }

        else if (choice == 6)
        {
            printf("Program Ended.\n");
            break;
        }

        else
        {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
