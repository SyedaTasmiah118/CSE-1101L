#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 150
#define MAX_NAME_LENGTH 101

typedef struct Student
{
    int studentID;
    char studentName[MAX_NAME_LENGTH];
    float midtermMark;
    float finalMark;
    float totalMark;
} Student;

void promptStudentDetails(Student *studentPtr);

void displayStudent(const Student *studentPtr);

int findStudentIndexByID(const Student roster[], int size, int searchID);

int findTopStudentIndex(const Student roster[], int size);

void addStudent(Student roster[], int *size);

void displayFullRoster(const Student roster[], int size);

void findAndDisplayStudent(const Student roster[], int size);

void showTopStudent(const Student roster[], int size);

void clearInputBuffer(void);

int main(void)
{
    Student courseRoster[MAX_STUDENTS];
    int rosterSize = 0;
    int choice = 0;

    do
    {
        printf("       \n\nCOURSE ROSTER MANAGEMENT\n\n");
        printf("1. Add Student\n");
        printf("2. Display Full Roster\n");
        printf("3. Find Student by ID\n");
        printf("4. Show Top Student\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid Input. Please Enter 1 to 5.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addStudent(courseRoster, &rosterSize);
            break;

        case 2:
            displayFullRoster(courseRoster, rosterSize);
            break;

        case 3:
            findAndDisplayStudent(courseRoster, rosterSize);
            break;

        case 4:
            showTopStudent(courseRoster, rosterSize);
            break;

        case 5:
            printf("\nProgramme Terminated Successfully.\n");
            break;

        default:
            printf("\nInvalid choice. Enter a number from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}

void clearInputBuffer(void)
{
    int character;

    while ((character = getchar()) != '\n' && character != EOF)
    {
    }
}

void promptStudentDetails(Student *studentPtr)
{
    int validInput;
    int nameComplete;

    do
    {
        printf("Enter Student Name: ");

        if (fgets(
                studentPtr->studentName,
                sizeof(studentPtr->studentName),
                stdin) == NULL)
        {
            studentPtr->studentName[0] = '\0';
        }

        nameComplete =
            strchr(studentPtr->studentName, '\n') != NULL;

        studentPtr->studentName[strcspn(studentPtr->studentName, "\n")] = '\0';

        if (!nameComplete)
        {
            clearInputBuffer();
        }

        if (strlen(studentPtr->studentName) == 0)
        {
            printf("Student name cannot be empty.\n");
        }

    } while (strlen(studentPtr->studentName) == 0);

    validInput = 0;

    while (!validInput)
    {
        printf("Enter Midterm Mark (0 to 100): ");

        if (scanf("%f", &studentPtr->midtermMark) != 1)
        {
            printf("Invalid input. Enter a numeric mark.\n");
            clearInputBuffer();
        }
        else if (
            studentPtr->midtermMark < 0.0f ||
            studentPtr->midtermMark > 100.0f)
        {
            printf("Midterm marks must be between 0 and 100.\n");
            clearInputBuffer();
        }
        else
        {
            clearInputBuffer();
            validInput = 1;
        }
    }

    validInput = 0;

    while (!validInput)
    {
        printf("Enter Final Mark (0 to 100): ");

        if (scanf("%f", &studentPtr->finalMark) != 1)
        {
            printf("Invalid Input. Enter a numeric mark.\n");
            clearInputBuffer();
        }
        else if (
            studentPtr->finalMark < 0.0f ||
            studentPtr->finalMark > 100.0f)
        {
            printf("Final mark must be between 0 and 100.\n");
            clearInputBuffer();
        }
        else
        {
            clearInputBuffer();
            validInput = 1;
        }
    }

    studentPtr->totalMark = studentPtr->midtermMark + studentPtr->finalMark;
}

void displayStudent(const Student *studentPtr)
{
    printf("Student ID    : %d\n", studentPtr->studentID);
    printf("Student Name  : %s\n", studentPtr->studentName);
    printf("Midterm Mark  : %.2f / 100\n", studentPtr->midtermMark);
    printf("Final Mark    : %.2f / 100\n", studentPtr->finalMark);
    printf("Total Mark    : %.2f / 200\n", studentPtr->totalMark);
}

int findStudentIndexByID(const Student roster[], int size, int searchID)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (roster[i].studentID == searchID)
        {
            return i;
        }
    }

    return -1;
}

int findTopStudentIndex(const Student roster[], int size)
{
    int i;
    int topIndex;

    if (size == 0)
    {
        return -1;
    }

    topIndex = 0;

    for (i = 1; i < size; i++)
    {
        if (roster[i].totalMark > roster[topIndex].totalMark)
        {
            topIndex = i;
        }
    }

    return topIndex;
}

void addStuden(Student roster[], int *size)
{
    Student newStudent;
    int existingIndex;
    int validID = 0;

    if (*size >= MAX_STUDENTS)
    {
        printf("\nCannot add another student.\n");
        printf("The course roster is full.\n");
        printf("Maximum roster size is %d students.\n", MAX_STUDENTS);
        return;
    }

    printf("\n\nADD STUDENT\n\n");

    while (!validID)
    {
        printf("Enter Student ID: ");

        if (scanf("%d", &newStudent.studentID) != 1)
        {
            printf("Invalid ID. Enter a positive integer.\n");
            clearInputBuffer();
        }
        else if (newStudent.studentID <= 0)
        {
            printf("Invalid ID. Student ID must be positive.\n");
            clearInputBuffer();
        }
        else
        {
            clearInputBuffer();
            validID = 1;
        }
    }

    existingIndex = findStudentIndexByID(roster, *size, newStudent.studentID);

    if (existingIndex != -1)
    {
        printf(
            "Error: A student with ID %d already exists.\n",
            newStudent.studentID);
        printf("Duplicate student ID cannot be added.\n");
        return;
    }

    promptStudentDetails(&newStudent);

    roster[*size] = newStudent;

    (*size)++;

    printf("\nStudent added successfully.\n");
    printf(
        "Current roster size: %d out of %d students.\n",
        *size,
        MAX_STUDENTS);
}

void displayFullRoster(const Student roster[], int size)
{
    int i;

    printf("\n\nFULL COURSE ROSTER\n\n");

    if (size == 0)
    {
        printf("The course roster is currently empty.\n");
        return;
    }

    printf("Total number of students: %d\n\n", size);

    for (i = 0; i < size; i++)
    {
        printf("Student Number: %d\n", i + 1);
        displayStudent(&roster[i]);
    }
}

void findAndDisplayStudent(const Student roster[], int size)
{
    int searchID;
    int studentIndex;

    if (size == 0)
    {
        printf("\nThe course roster is empty.\n");
        printf("There are no students to search for.\n");
        return;
    }

    printf("\nFIND STUDENT\n");
    printf("Enter the Student ID to search: ");

    if (scanf("%d", &searchID) != 1)
    {
        printf("Invalid input. Student ID must be an integer.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (searchID <= 0)
    {
        printf("Invalid ID. Student ID must be positive.\n");
        return;
    }

    studentIndex = findStudentIndexByID(
        roster,
        size,
        searchID);

    if (studentIndex == -1)
    {
        printf(
            "\nNo student was found with ID %d.\n",
            searchID);
    }
    else
    {
        printf("\nStudent found.\n");
        displayStudent(&roster[studentIndex]);
    }
}

void showTopStudent(const Student roster[], int size)
{
    int topStudentIndex;

    printf("\nTOP STUDENT\n");

    topStudentIndex = findTopStudentIndex(roster, size);

    if (topStudentIndex == -1)
    {
        printf("The course roster is empty.\n");
        printf("No top student is available.\n");
    }
    else
    {
        printf("The student with the highest total mark is:\n");
        displayStudent(&roster[topStudentIndex]);
    }
}