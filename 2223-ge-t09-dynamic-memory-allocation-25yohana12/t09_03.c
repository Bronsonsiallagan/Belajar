#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "academic.h"

int main(int _argc, char **_argv)
{
  struct student_t *students = malloc(100 * sizeof(struct student_t));
  struct course_t *courses = malloc(100 * sizeof(struct course_t));
  char input[100];

  char *data;
  int idxStud = 0;
  int idxCourse = 0;
  do
  {
    fflush(stdin);
    input[0] = '\0';
    int c = 0;
    while (1)
    {
      char x = getchar();
      if (x == '\r')
      {
        continue;
      }
      if (x == '\n')
      {
        break;
      }
      input[c] = x;
      input[++c] = '\0';
    }
    if (strcmp(input, "---") == 0)
    {
      break;
    }
    else if (strstr(input, "print-students") != NULL)
    {
      print_students(students, idxStud);
    }
    else if (strstr(input, "create-student") != NULL)
    {

      char id[12];
      char name[40];
      char year[5];
      char study_program[100];

      data = strtok(input, "#");
      data = strtok(NULL, "#");
      strcpy(id, data);
      data = strtok(NULL, "#");
      strcpy(name, data);
      data = strtok(NULL, "#");
      strcpy(year, data);
      data = strtok(NULL, "#");
      strcpy(study_program, data);
      students[idxStud] = create_student(id, name, year, study_program);

      idxStud++;
    } 
    else if (strstr(input, "create-course") != NULL)
    {

      char id[12];
      char name[40];
      int credit;
      char grade[5];

      data = strtok(input, "#");
      data = strtok(NULL, "#");
      strcpy(id, data);
      data = strtok(NULL, "#");
      strcpy(name, data);
      data = strtok(NULL, "#");
      credit = atoi(data);

      data = strtok(NULL, "#");
      if (strcmp(data, "A") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_A);
      }
      else if (strcmp(data, "AB") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_AB);
      }
      else if (strcmp(data, "B") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_B);
      }
      else if (strcmp(data, "BC") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_BC);
      }
      else if (strcmp(data, "C") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_C);
      }
      else if (strcmp(data, "D") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_D);
      }
      else if (strcmp(data, "E") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_E);
      }
      else if (strcmp(data, "T") == 0)
      {
        courses[idxCourse] = create_course(id, name, credit, GRADE_T);
      }
      idxCourse = idxCourse + 1;
    }

    else if (strstr(input, "print-courses") != NULL)
    {
      print_courses(courses, idxCourse);
    }
    else if (strstr(input, "find-student-by-id") != NULL)
    {
      char findId[10];

      data = strtok(input, "#");
      data = strtok(NULL, "#");
      strcpy(findId, data);

      find_student_by_id(students, idxStud, findId);
    }

  } while (1);

  free(students);
  return 0;
}