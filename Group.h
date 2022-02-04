#pragma once
#include "ALL_libraries.h"
#include "Student.h"

class Group
{
private:
	int count_of_student;
	Student* student = nullptr;
	char* name_of_group = nullptr;
	char* specialization = nullptr;
	int course;
public:
	Group();
	Group(int count_of_student);
	Group(int count_of_student, const char* name_of_group, const char* specialization);
	Group(const char* name_of_group, const char* specialization);
	Group(const Group& original);
	~Group();

	

	void Set_name_of_group(const char* name_of_group);// метод установки имени группы
	void Set_specialization(const char* specialization);// метод установки специализации группы
	

	void Set_course(int course);  // метод установки курса
	int Get_course() const;
	void Show_group();  // показ всех студентов группы

	Group& Dismiss_for_exam(); // метод отчисления студентов за несдавший экз

	Group& Dismiss_for_credits(); // отчисления за неуспеваемость
	
	Group& Merge_groups(const Group& first, const Group& second); // слияние двух групп
	
	Group& Add_student(const char* surname, const char* name, const char* patronymic);

	bool operator == (const Group& other); // перегрузка оператора равенства

	bool operator != (const Group& other); // перегрузка оператора неравенства

	bool operator < (const Group& other); // оператор сравнения <

	bool operator > (const Group& other); // оператор сравнения >

	Group& operator += (const Student& other);

	friend ostream& operator<<(ostream& os, const Group& group);

	friend istream& operator>>(istream& is, Group& group);

	Group& operator()(int count_of_student, const char* name_of_group, const char* specialization);

	Student& operator[](int index);

};

