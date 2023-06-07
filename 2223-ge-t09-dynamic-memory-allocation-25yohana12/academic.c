// 12S22003 - Yohana Natalia Siahaan
// 12S22025 - Bronson TM Siallagan

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade)
{
    char *text = malloc(8);
    text[0] = '\0';
    
    strcpy(text, (_grade == GRADE_A) ? "A" : (_grade == GRADE_AB) ? "AB"
                                         : (_grade == GRADE_B)    ? "B"
                                         : (_grade == GRADE_BC)   ? "BC"
                                         : (_grade == GRADE_C)    ? "C"
                                         : (_grade == GRADE_D)    ? "D"
                                         : (_grade == GRADE_E)    ? "E"
                                         : (_grade == GRADE_T)    ? "T"
                                                                  : "None");
    return text;
}
float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    float performance;
    performance =
        (_grade == GRADE_A) ? 4.00 * _credit : (_grade == GRADE_AB)                   ? 3.50 * _credit
                                           : (_grade == GRADE_B)                      ? 3.00 * _credit
                                           : (_grade == GRADE_BC)                     ? 2.50 * _credit
                                           : (_grade == GRADE_C)                      ? 2.00 * _credit
                                           : (_grade == GRADE_D)                      ? 1.00 * _credit
                                           : (_grade == GRADE_E || _grade == GRADE_T) ? 0.00 * _credit
                                                                                      : 0.00;
    return performance;
}

void print_course(struct course_t _course)
{
    char *text = grade_to_text(_course.passing_grade);
    printf("%s|%s|%d|%s\n", _course.code, _course.name, _course.credit, text);
}

void print_courses(struct course_t *_courses, unsigned short int _course_size)
{
    for (int i = 0; i < _course_size; i++)
    {
        printf("%s|%s|%d|%s\n", _courses[i].code, _courses[i].name, _courses[i].credit, grade_to_text(_courses[i].passing_grade));
    }
}

void print_student(struct student_t _student)
{
    if (_student.gpa > 4)
    {
        _student.gpa = 0.00;
        printf("%s|%s|%s|%s|%.2f\n", _student.id, _student.name, _student.year, _student.study_program, _student.gpa);
    }
    else
    {
        printf("%s|%s|%s|%s|%.2f\n", _student.id, _student.name, _student.year, _student.study_program, _student.gpa);
    }
}

void print_students(struct student_t *_students,
                    unsigned short int _student_size)
{
    // codes

    for (int i = 0; i < _student_size; i++)
    {
        /* code */
        printf("%s|%s|%s|%s|%.2f\n", _students[i].id, _students[i].name, _students[i].year, _students[i].study_program, _students[i].gpa);
    }
}

void print_enrollment(struct enrollment_t _enrollment)
{
    printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, grade_to_text(_enrollment.grade), calculate_performance(_enrollment.grade, _enrollment.course.credit));
}

void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size)
{
    int i = 0;
    while (i < _enrollment_size)
    {
        printf("%s|%s|%s|%.2f\n", _enrollments[i].course.code, _enrollments[i].student.id, grade_to_text(_enrollments[i].grade), calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit));
        i++;
    }
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade)
{
    struct course_t crs;

    strcpy(crs.code, _code);
    strcpy(crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;

    return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program)
{
    struct student_t std;

    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    strcpy(std.study_program, _study_program);
    std.gpa = 0.00;

    return std;
}

struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester)
{
    struct enrollment_t emt;

    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;
    emt.grade = GRADE_NONE;

    return emt;
}

void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size)
{
    float total_performance = 0.00;
    int total_credit = 0;
    int i = 0;
    while (i < _enrollment_size)
    {
        total_performance += calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
        total_credit += _enrollments[i].course.credit;
        i++;
    }

    _student->gpa = total_performance / total_credit;
}

void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade)
{
    int i = 0;
    while (i < _enrollment_size)
    {
        if (_enrollments[i].grade != 0)
        {
            i++;
            continue;
        }
        else
        {
            _enrollments[i].grade = _grade;
            break;
        }
        i++;
    }
}

struct student_t find_student_by_id(struct student_t *_students,
                                    unsigned short int _student_size,
                                    char *_id)
{
    struct student_t std;

    if (_students != NULL)
    {
        for (int i = 0; i < _student_size; i++)
        {
            if (strcmp(_students[i].id, _id) == 0)
            {
                printf("%s|%s|%s|%s|%.2f\n", _students[i].id, _students[i].name, _students[i].year, _students[i].study_program, _students[i].gpa);
            }
        }

        return std;
    }
}
struct course_t find_course_by_code(struct course_t *_courses,
                                    unsigned short int _course_size,
                                    char *_code)
{

    struct course_t crs;
    if (_courses != NULL)
    {
        for (int i = 0; i < _course_size; i++)
        {
            if (strcmp(_courses[i].code, _code) == 0)
            {
                printf("%s|%s|%d|%s\n", _courses[i].code, _courses[i].name, _courses[i].credit, grade_to_text(_courses[i].passing_grade));
            }
        }
    }
    return crs;
}
