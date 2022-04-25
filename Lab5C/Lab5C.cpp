#include "Prism.h"
#include "Functions.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Prism3> threeAngle;
	vector<Prism4> fourAngle;
	createPrisms(threeAngle, fourAngle);
	double resultThree = countResult(threeAngle);
	double resultFour = countResult(fourAngle);
	cout << "Суммарный объем всех созданных треугольных призм равен = " << resultThree
		<< ".\nСуммарная площадь боковых поверхностей всех четырехугольных призм равна = " << resultFour;
}
