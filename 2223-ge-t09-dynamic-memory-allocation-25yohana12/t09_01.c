// 12S22003 - Yohana Siahaan
// 12S22025 - Bronson Siallagan

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "academic.h"

int main(int _argc, char **_argv)
{
  struct student_t *students = malloc(100 * sizeof(struct student_t));
  char input[100];
  char id[12];
  char name[40];
  char year[5];
  char study_program[100];
  char *data;
  int idxStud = 0;
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

  } while (1);

  free(students);
  return 0;
}
