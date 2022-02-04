#include "Group.h"
#include "Student.h"

Group::Group()
{
	count_of_student = 0;
	student = new Student[count_of_student];
	name_of_group = new char[100];
	strcpy_s(name_of_group, 99, "Избранные");
	specialization = new char[100];
	strcpy_s(specialization, 99, "Маркетинг и мененджмент");
	course = 3;
}

Group::Group(int count_of_student)
{

	if (count_of_student < 0)
	{
		throw "OPPS!";
	}
	else
	{
		this->count_of_student = count_of_student;
	}
	student = new Student[this->count_of_student];
	name_of_group = new char[100];
	strcpy_s(name_of_group, 99, "Избранные");
	specialization = new char[100];
	strcpy_s(specialization, 99, "Маркетинг и мененджмент");
	course = 3;
}

Group::Group(const char* name_of_group, const char* specialization)
{
	count_of_student = 0;
	student = new Student[this->count_of_student];
	this->name_of_group = new char[100];
	strcpy_s(this->name_of_group, 99, name_of_group);
	this->specialization = new char[100];
	strcpy_s(this->specialization, 99, specialization);
	course = 3;
}

Group::Group(int count_of_student, const char* name_of_group, const char* specialization)
{
	if (count_of_student < 0)
	{
		throw "OPPS!";
	}
	else
	{
		this->count_of_student = count_of_student;
	}
	student = new Student[this->count_of_student];
	this->name_of_group = new char[100];
	strcpy_s(this->name_of_group, 99, name_of_group);
	this->specialization = new char[100];
	strcpy_s(this->specialization, 99, specialization);
	course = 3;
}

Group::Group(const Group& original)
{
	count_of_student = original.count_of_student;
	student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		student[i] = original.student[i];
	}
	name_of_group = new char[100];
	strcpy_s(name_of_group, 99, original.name_of_group);
	specialization = new char[100];
	strcpy_s(specialization, 99, original.specialization);
	course = original.course;
}


void Group::Set_course(int course)
{
	this->course = course;
}

int Group::Get_course() const
{
	return course;
}

void Group::Set_name_of_group(const char* name_of_group)
{
	delete[] this->name_of_group;
	this->name_of_group = new char[100];
	strcpy_s(this->name_of_group, 99, name_of_group);
	
}

void Group::Set_specialization(const char* specialization)
{
	delete[] this->specialization;
	this->specialization = new char[100];
	strcpy_s(this->specialization, 99, specialization);
}

void Group::Show_group()  // показ всех студентов группы
{
	cout << "----------------------------------" << endl;
	cout << "----------------------------------" << endl;
	cout << "Информация о группе: " << endl;
	cout << "Название группы: " << name_of_group << endl;
	cout << "Специализация группы: " << specialization << endl;
	cout << "Номер курса: " << Get_course() << endl;
	if (count_of_student > 0)
	{
		cout << "Студенты: " << endl;
		for (int i = 0; i < count_of_student; i++)
		{
			student[i].Show_student();
			cout << endl;
		}
	}
	else
	{
		cout << "Группа пустая" << endl;
	}

}

Group& Group::Add_student(const char* surname, const char* name, const char* patronymic)
{
	Student* temp = new Student[count_of_student + 1];
	for (int i = 0; i < count_of_student; i++)
	{
		temp[i] = student[i];
	}
	Student s = Student(surname, name, patronymic);
	temp[count_of_student] = s;
	delete[] this->student;
	student = temp;
	count_of_student++;
	return *this;
}



Group& Group::Dismiss_for_exam()  // отчисление студента за несдавший экз
{
	Student* new_student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		new_student[i] = student[i];
	}
	int count_of_exam = 0;
	for (int i = 0; i < count_of_student; i++)
	{
		if (new_student[i].Get_exam() == 1)
		{
			count_of_exam++;
		}
	}
	delete[] student;
	student = new Student[count_of_exam];
	int j = 0;
	for (int i = 0; i < count_of_student; i++)
	{
		if (new_student[i].Get_exam() == 1)
		{
			student[j] = new_student[i];
			j++;
		}
	}
	count_of_student = count_of_exam;
	return *this;
}

Group& Group::Dismiss_for_credits() // метод отчисления неуспевающего студента
{
	float MIN;
	MIN = student[0].Get_avegare_rating();
	for (int i = 1; i < count_of_student; i++)
	{
		if (student[i].Get_avegare_rating() < MIN)
		{
			MIN = student[i].Get_avegare_rating();
		}
		else
		{
			continue;
		}
	}
	count_of_student--;
	Student* new_student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		if (student[i].Get_avegare_rating() == MIN)
		{
			for (int j = i; j < count_of_student; j++)
			{
				new_student[j] = student[j + 1];
			}
			break;
		}
		new_student[i] = student[i];
	}
	delete[] student;
	student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		student[i] = new_student[i];
	}
	return *this;
}


Group& Group::Merge_groups(const Group& first, const Group& second)
{
	
	this->count_of_student = first.count_of_student + second.count_of_student;
	this->student = new Student[this->count_of_student];
	for (int i = 0; i < first.count_of_student; i++)
	{
		this->student[i] = first.student[i];
	}
	for (int i = first.count_of_student; i < count_of_student; i++)
	{
		this->student[i] = second.student[i - first.count_of_student];
	}
	return *this;
}

bool Group::operator == (const Group& other)
{
	return (this->count_of_student == other.count_of_student);
}

bool Group::operator != (const Group& other)
{
	return !(this->count_of_student == other.count_of_student);
}

bool Group::operator < (const Group& other)
{
	return this->count_of_student < other.count_of_student;
}

bool Group::operator > (const Group& other)
{
	return this->count_of_student > other.count_of_student;
}

Group& Group::operator +=(const Student& other)
{
	Student* new_student = new Student[count_of_student + 1];
	for (int i = 0; i < count_of_student; i++)
	{
		new_student[i] = this->student[i];
	}
	new_student[count_of_student] = other;
	delete[] this->student;
	this->student = new_student;
	count_of_student++;
	return *this;
}

Group::~Group()
{
	if (student != nullptr)
	{
		delete[] student;

	}
	if (name_of_group != nullptr)
	{
		delete[] name_of_group;

	}
	if (specialization != nullptr)
	{
		delete[] specialization;
		
	}
}

Group& Group::operator()(int count_of_student, const char* name_of_group, const char* specialization)
{
	delete[] this->student;
	this->count_of_student = count_of_student;
	this->student = new Student[count_of_student];
	this->name_of_group = new char[100];
	strcpy_s(this->name_of_group, 99, name_of_group);
	this->specialization = new char[100];
	strcpy_s(this->specialization, 99, specialization);
	return *this;
}

Student& Group::operator[] (int index)
{
	if (index >= count_of_student)
	{
		throw "OPPS!";
	}
	else
	{
		return student[index];
	}
}

