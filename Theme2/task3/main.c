#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define NUMBER_OF_SUBJECTS 3

typedef struct {
    double mark;
    char subjectName[30];
} Subject;

typedef struct {
    char lastName[12];
    int group;
    Subject subjects[NUMBER_OF_SUBJECTS];
} Student;

Student* generateStudentInfo(int length, int maxNumberOfGroups);
char* generateRandomString(int length);
void printAllStudentsInfo(Student* students, int length);
void printLastNameAllStudentWhoHaveMarkLessThanNumber(Student* students, int length, int number);
int numberOfStudentsWhoHaveOnlyWellOrExcellentMarks(Student* students, int length);
void printBestPassedStudentsSubject(Student* students, int length);
int worstPerformanceGroupNumber(Student* students, int length, int maxNumberOfGroups);
double calculateAverageGroupPerformance(Student* students, int length, int groupNumber);

int main() {
    srand(time(NULL));

    int length = 10;
    int maxNumberOfGroups = 4;
    Student* students = generateStudentInfo(length, maxNumberOfGroups);

    printAllStudentsInfo(students, length);

    printf("STUDENTS THAT HAS MARK LESS THEN 50\n");
    printLastNameAllStudentWhoHaveMarkLessThanNumber(students, length, 50);
    printf("\n\n");

    printf("PERCENTAGE OF STUDENTS THAT HAVE ONLY WELL OR EXCELLENT MARKS IS %.2lf\n\n",
           (double)(numberOfStudentsWhoHaveOnlyWellOrExcellentMarks(students, length) * 100) / length);

    printf("BEST PASSED SUBJECTS BY STUDENTS");
    printBestPassedStudentsSubject(students, length);
    printf("\n");

    printf("THE WORST PERFORMANCE GROUP IS %d\n", worstPerformanceGroupNumber(students, length, maxNumberOfGroups));
    return 0;
}

Student* generateStudentInfo(int length, int maxNumberOfGroups) {
    Student* students = (Student*) malloc(sizeof(Student) * length);

    int index;
    for (index = 0; index < length; index++) {
        // set student last name
        char* lastName = generateRandomString(rand() % 6 + 7);
        lastName[0] = toupper(lastName[0]);
        strcpy(students[index].lastName, lastName);

        // set student group
        students[index].group = rand() % maxNumberOfGroups + 1;

        // set student subject marks
        students[index].subjects[0].mark = rand() % 100 + 1;
        strcpy(students[index].subjects[0].subjectName, "Web Technologies");
        students[index].subjects[1].mark = rand() % 100 + 1;
        strcpy(students[index].subjects[1].subjectName, "Ukrainian language");
        students[index].subjects[2].mark = rand() % 100 + 1;
        strcpy(students[index].subjects[2].subjectName, "Information System Design");
    }

    return students;
}

// according to
// https://stackoverflow.com/questions/15767691/whats-the-c-library-function-to-generate-random-string
char* generateRandomString(int length) {
    // available chars for generating random last name
    char charset[] = "abcdefghijklmnopqrstuvwxyz";
    char* randomString = (char*) malloc(sizeof(char) * length);

    int index;
    for (index = 0; index < length - 1; index++) {
        int randomCharsetIndex = rand() % (sizeof(charset) - 1);
        randomString[index] = charset[randomCharsetIndex];
    }

    randomString[length - 1] = '\0';
    return randomString;
}

void printAllStudentsInfo(Student* students, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        printf("Last name: %s\n", students[i].lastName);
        printf("Group: %d\n", students[i].group);
        printf("Subjects\n");
        for (j = 0; j < NUMBER_OF_SUBJECTS; j++) {
            printf("|Subject: %-30s|Mark: %5.2lf|\n", students[i].subjects[j].subjectName, students[i].subjects[j].mark);
        }
        printf("\n");
    }
}

void printLastNameAllStudentWhoHaveMarkLessThanNumber(Student* students, int length, int number) {
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = 0; j < NUMBER_OF_SUBJECTS; j++) {
            if (students[i].subjects[j].mark < number) {
                printf("%s\n", students[i].lastName);
                break;
            }
        }
    }
}

int numberOfStudentsWhoHaveOnlyWellOrExcellentMarks(Student* students, int length) {
    int counter = 0;
    int i, j;
    for (i = 0; i < length; i++) {
        int allMarksWellOrExcellent = 1;
        for (j = 0; j < NUMBER_OF_SUBJECTS; j++) {
            if (students[i].subjects[j].mark >= 50) {
                allMarksWellOrExcellent = 0;
                break;
            }
        }

        if (allMarksWellOrExcellent) {
            counter++;
        }
    }

    return counter;
}

void printBestPassedStudentsSubject(Student* students, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        int indexOfBestPassedSubject = 0;
        for (j = 1; j < NUMBER_OF_SUBJECTS; j++) {
            if (students[i].subjects[j].mark > students[i].subjects[indexOfBestPassedSubject].mark) {
                indexOfBestPassedSubject = j;
            }
        }

        printf("Best passed subject by student '%s' is %s\n", students[i].lastName, students[i].subjects[indexOfBestPassedSubject].subjectName);
    }
}

int worstPerformanceGroupNumber(Student* students, int length, int maxNumberOfGroups) {
    int groupNumber;
    int worstGroupNumber = 1;
    int worstGroupAverageMarks = calculateAverageGroupPerformance(students, length, 1);

    for (groupNumber = 2; groupNumber <= maxNumberOfGroups; groupNumber++) {
        int groupAverageMarks = calculateAverageGroupPerformance(students, length, groupNumber);
        if (groupAverageMarks < worstGroupAverageMarks) {
            worstGroupAverageMarks = groupAverageMarks;
            worstGroupNumber = groupNumber;
        }
    }

    return worstGroupNumber;
}

double calculateAverageGroupPerformance(Student* students, int length, int groupNumber) {
    int i, j;
    int countOfSubjects = 0;
    double sumOfMarks = 0;

    for (i = 0; i < length; i++) {
        if (students[i].group == groupNumber) {
            for (j = 0; j < NUMBER_OF_SUBJECTS; j++) {
                countOfSubjects++;
                sumOfMarks += students[i].subjects[j].mark;
            }
        }
    }

    return sumOfMarks / countOfSubjects;
}
