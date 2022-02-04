#include "Student.h"
#include "Group.h"



ostream& operator<<(ostream& os, const Student& student)
{
	os << "-----------------" << endl;
	os << "Информация о студенте: " << endl;
	os << "Фамилия: " << student.surname<< endl;
	os << "Имя: " << student.name<< endl;
	os << "Отчество: " << student.patronymic<< endl;
	os << "Возраст: " << student.age<< endl;
	os << "Оценки: ";
	student.Show_credits();
	os << "\nСдача екзамена: " << boolalpha << student.Get_exam() << endl;
	os << "Средняя оценка студента: " << student.average_rating << endl;
	return os;
}

istream& operator>>(istream& is, Student& student)
{
	setlocale(LC_ALL, "RUSSIAN");

	cout << "Введите фамилию: ";
	char* temp_surname = new char[100];
	is >> temp_surname;
	student.Set_surname(temp_surname);

	cout << "Введите имя: ";
	char* temp_name = new char[100];
	is >> temp_name;
	strcpy_s(student.name, 99, temp_name);

	cout << "Введите отчество: ";
	char* temp_patronymic = new char[100];
	is >> temp_patronymic;
	strcpy_s(student.patronymic, 99, temp_patronymic);

	cout << "Введите возраст: ";
	is >> student.age;
	delete[] temp_name;
	delete[] temp_surname;
	delete[] temp_patronymic;
	return is;
}

ostream& operator<<(ostream& os, const Group& group)
{
	os<< "----------------------------------" << endl;
	os<< "----------------------------------" << endl;
	os<< "Информация о группе: " << endl;
	os<< "Название группы: " << group.name_of_group << endl;
	os<< "Специализация группы: " << group.specialization << endl;
	os<< "Номер курса: " << group.Get_course() << endl;
	os << "Студенты: " << endl;
	for (int i = 0; i < group.count_of_student; i++)
	{
		cout << group.student[i] << endl;
	}
	return os;
}

istream& operator>>(istream& is, Group& group)
{
	cout << "Введите количество студентов: ";
	is >> group.count_of_student;
	group.student = new Student[group.count_of_student];

	cout << "Введите название группы: ";
	char* temp_name_of_group = new char[100];
	is >> temp_name_of_group;
	group.Set_name_of_group(temp_name_of_group);

	cout << "Введите специализацию группы: ";
	char* temp_specialization = new char[100];
	is >> temp_specialization;
	group.Set_specialization(temp_specialization);

	cout << "Введите номер курса: ";
	is >> group.course;

	delete[] temp_name_of_group;
	delete[] temp_specialization;
	return is;
}




int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
	
	/*Student A;
	A.Show_student();
	A += 3;
	A.Show_student();

	Student C;
	C.Show_student();
	Student D;
	D.Show_student();
	cout << endl;
	bool result = C < D;
	cout << boolalpha << result << endl;

	Student Igor("Плахотнюк", "Игорь", "Витальевич");
	Igor.Show_student();
	Igor.Set_name("Vasya");
	Igor.Show_student();*/

	/*Group A(5);
	Group B(55);
	bool result = A != B;
	cout << boolalpha << result << endl;
	bool result_2 = A > B;
	cout << boolalpha << result_2 << endl;*/

	/*Group A(5);
	A.Show_group();
	Student B("Plah", "Igor", "Vitaliyevich");
	A += B;
	A.Show_group();*/

	/*Group A(10);
	A.Show_group();
	A.Dismiss_for_exam();
	A.Show_group();
	A.Dismiss_for_credits();
	A.Show_group();*/

	/*Group A(0);
	A.Show_group();
	Group B(3);
	B.Show_group();
	Group C(2);
	C.Show_group();
	A.Merge_groups(B, C);
	A.Show_group();*/


	// перегрузка оператора << >> для студента
	/*Student A;
	cout << A << endl;
	cin >> A;
	cout << A;*/

	/*Group A(5);
	cout << A << endl;*/

	/*Group A;
	cout << A;
	cin >> A;
	cout << A;*/

	// перегрузка ()

	/*Student A;
	cout << A;
	A("Плахотнюк", "Игорь", "Витальевич", 24);
	cout << A;*/
	
	/*Group A(5);
	cout << A << endl;
	cout << "==================================" << endl;
	A(2, "Не избранные", "Транспорт");
	cout << A;*/


	// перегрузка оператора []
	/*Group A(3);
	cout << A << endl;
	cout << "===================" << endl;
	cout << A[0] << endl;
	return 0;*/
}