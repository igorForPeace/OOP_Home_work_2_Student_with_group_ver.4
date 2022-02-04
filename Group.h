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

	

	void Set_name_of_group(const char* name_of_group);// ����� ��������� ����� ������
	void Set_specialization(const char* specialization);// ����� ��������� ������������� ������
	

	void Set_course(int course);  // ����� ��������� �����
	int Get_course() const;
	void Show_group();  // ����� ���� ��������� ������

	Group& Dismiss_for_exam(); // ����� ���������� ��������� �� ��������� ���

	Group& Dismiss_for_credits(); // ���������� �� ��������������
	
	Group& Merge_groups(const Group& first, const Group& second); // ������� ���� �����
	
	Group& Add_student(const char* surname, const char* name, const char* patronymic);

	bool operator == (const Group& other); // ���������� ��������� ���������

	bool operator != (const Group& other); // ���������� ��������� �����������

	bool operator < (const Group& other); // �������� ��������� <

	bool operator > (const Group& other); // �������� ��������� >

	Group& operator += (const Student& other);

	friend ostream& operator<<(ostream& os, const Group& group);

	friend istream& operator>>(istream& is, Group& group);

	Group& operator()(int count_of_student, const char* name_of_group, const char* specialization);

	Student& operator[](int index);

};

