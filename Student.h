#pragma once
#include "ALL_libraries.h"



class Student
{
private:
	char* surname;
	char* name;
	char* patronymic;
	int age;
	int* credits;
	int count_of_credits;
	bool exam;
	float average_rating;

public:
	Student();
	Student(const char* surname, const char* name, const char* patronymic);
	Student(const Student& original);
	~Student();
	
	void Set_name(const char* name);
	const char* Get_name();
	void Set_surname(const char* surname);
	const char* Get_surname();
	void Set_patronymic(const char* patronymic);
	const char* Get_patronymic();
	int Get_age()const;
	int Get_count_of_credits() const;
	float Get_avegare_rating() const;
	void Show_credits() const;
	bool Get_exam() const;
	void Show_student();

	Student& operator += (int credits);

	Student& operator = (const Student& other);

	bool operator == (const Student& other); // ���������� ��������� ���������

	bool operator != (const Student& other); // ���������� ��������� �����������

	bool operator < (const Student& other); // �������� ��������� <

	bool operator > (const Student& other); // �������� ��������� >

	friend ostream& operator<<(ostream& os, const Student& student);

	friend istream& operator>>(istream& is, Student& student);

	Student& operator()(const char* surname, const char* name, const char* patronymic, const int age);


};

