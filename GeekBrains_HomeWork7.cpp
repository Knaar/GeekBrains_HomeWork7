#include <iostream>
#include <sstream>


using namespace std;
class Date//Создайте класс Date с полями день, месяц, год и методами доступа к этим полям
{
public:
	Date(int day = 1, int month = 1, int year = 1970) : day(day), month(month), year(year) {};


	friend ostream& operator<< (ostream& os, const Date& date);
	friend void DateLaler(const Date& date1, const Date& date2);

	void setDay(int _day) {
		this->day = _day;
	}
	void setMonth(int _month) {
		this->month = _month;
	}
	void setYear(int _year) {
		this->year = _year;
	}
private:
	int day, month, year;
};

ostream& operator<< (ostream& os, const Date& date) {//Перегрузите оператор вывода для данного класса.
	os << "Day : " << date.day << ", Month : " << date.month << ", Year: " << date.year << "\n";
	return os;
}
int* a(int& x, int& y) {

	return (&x);
}
//Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой(сравнение происходит по датам).
void DateLaler(const Date& date1, const Date& date2) {//!! я не придумал, как реализовать возврат наибольшего объекта! Спросить у Преподавателя
	if (date1.year > date2.year) {//я сравниваю сперва года
		cout << "Later : " << date1;
	}
	else if (date1.year < date2.year) {
		cout << "Later : " << date2;
	}
	else if (date1.year == date2.year) {

		if (date1.month > date2.month) {//потом, если год совпадает, сравниваю месяцы
			cout << "Later : " << date1;
		}
		else if (date1.month < date2.month) {
			cout << "Later : " << date2;
		}
		else if (date1.month == date2.month) {

			if (date1.day > date2.day) {//если и месяцы равны, проверяю дни
				cout << "Later : " << date1;
			}
			else if (date1.day < date2.day) {
				cout << "Later : " << date2;
			}
			else if (date1.day == date2.day) {
				cout << "Один и тот-же день";
			}
		}

	}
	//Функция должна вернуть более позднюю дату.
	//я пытался
}
//Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров.
void DayZ(Date& date1, Date& date2) {
	Date  ptemp{ date1 };
	date1 = date2;
	date2 = ptemp;

}

int main()
{
	setlocale(LC_ALL, "Russian");

	//	1

	Date SomeOneDay;


	cout << SomeOneDay;

	//Создайте два "умных" указателя today и date.
	Date* pToday = &SomeOneDay;//указатель один
	Date* pDate = &SomeOneDay;//указатель два

	stringstream stringData;
	stringData << "21 04 2022";//предположим, ввод сегодняшней даты должен быть как одно, текстовое значение
	int _d, _m, _y;//переменные для перезаписи
	stringData >> _d >> _m >> _y;

	//Первому присвойте значение сегодняшней даты.
	pToday->setDay(_d), pToday->setMonth(_m), pToday->setYear(_y);//Для него вызовите по отдельности методы доступа к полям класса Date


	cout << "pToday : " << *pToday;//а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
	*pDate = *pToday;//Затем переместите ресурс, которым владеет указатель today в указатель date.
	cout << "pDate : " << *pDate;

	//Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
	(pToday == NULL) ? cout << "Является ]\n" : cout << "Не является\n";
	(!pDate) ? cout << "Является \n" : cout << "Не является\n";

	//	2
	// По условию предыдущей задачи создайте два умных указателя date1 и date2.
	Date date1(13, 9, 2001);//создал два примерных объекта
	Date date2(29, 02, 2002);
	Date* pdate1 = &date1;
	Date* pdate2 = &date2;
	cout << *pdate1;
	DateLaler(*pdate1, *pdate2);
	DayZ(*pdate1, *pdate2);

}
