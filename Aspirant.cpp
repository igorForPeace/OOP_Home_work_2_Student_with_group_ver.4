#include "Aspirant.h"

Aspirant::Aspirant():Student()
{
	theme = "Ecomomy";
}

Aspirant::Aspirant(string theme) : Student()
{
	this->theme = theme;
}

Aspirant::Aspirant(string theme, const char* surname, const char* name, const char* patronymic) :
	Student(surname, name, patronymic)
{
	this->theme = theme;
}

void Aspirant::SetTheme(string theme)
{
	this->theme = theme;
}

string Aspirant::GetTheme() const
{
	return theme;
}

void Aspirant::SetName(const char* name)
{
	Student::Set_name(name);
}

const char* Aspirant::GetName() 
{
	return Student::Get_name();
}

void Aspirant::SetSurname(const char* surname)
{
	Student::Set_surname(surname);
}

const char* Aspirant::GetSurname()
{
	return Student::Get_surname();
}

void Aspirant::SetPatronymic(const char* patronymic)
{
	Student::Set_patronymic(patronymic);
}

const char* Aspirant::GetPatronymic()
{
	return Student::Get_patronymic();
}

void Aspirant::Show_student()
{
	Student::Show_student();
	cout << "Тема дисертации: " << GetTheme() << endl;
}