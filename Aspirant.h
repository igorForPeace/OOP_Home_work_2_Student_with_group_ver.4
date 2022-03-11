#pragma once
#include "ALL_libraries.h"
#include "Student.h"

class Aspirant:public Student
{
private:
	string theme;
public:
	Aspirant();
	Aspirant(string theme);
	Aspirant(string theme, const char* surname, const char* name, const char* patronymic);
	void SetTheme(string theme);
	string GetTheme() const;
	void SetName(const char* name);
	const char* GetName();
	void SetSurname(const char* surname);
	const char* GetSurname();
	void SetPatronymic(const char* patronymic);
	const char* GetPatronymic();
	void Show_student();

	

};

