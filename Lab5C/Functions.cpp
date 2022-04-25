#include "Functions.h"
void createPrisms(vector<Prism3>& threeAngle, vector<Prism4>& fourAngle)
{
	double tempSide;
	Prism3 tempPrism3;
	cout << "������� ����� ������� ��������� ����������� ���������� ������: ";
	cin >> tempSide;
	tempPrism3.setBaseSide(tempSide);
	cout << "������� ����� ������� ������� ����������� ���������� ������: ";
	cin >> tempSide;
	tempPrism3.setLateralSide(tempSide);
	threeAngle.push_back(tempPrism3);
	cout << "\n������� 1 ����������� ���������� ������ � �������� ������� ������� = " 
		<< tempPrism3.getLateralSide() << " � �������� ������� ��������� = " << tempPrism3.getBaseSide()
		<< ".\n�� ����� ����� = " << tempPrism3.getVolume()
		<< ". �� ������� ������� ����������� ����� = " << tempPrism3.getSideSurfaceSquare() << endl << endl;
	Prism4 tempPrism4;
	cout << "������� ����� ������� ��������� ��������������� ���������� ������: ";
	cin >> tempSide;
	tempPrism4.setBaseSide(tempSide);
	cout << "������� ����� ������� ������� ��������������� ���������� ������: ";
	cin >> tempSide;
	tempPrism4.setLateralSide(tempSide);
	cout << "\n������� 1 ��������������� ���������� ������ � �������� ������� ������� = "
		<< tempPrism4.getLateralSide() << " � �������� ������� ��������� = " << tempPrism4.getBaseSide()
		<< ".\n�� ����� ����� = " << tempPrism4.getVolume() 
		<< ". �� ������� ������� ����������� ����� = " << tempPrism4.getSideSurfaceSquare() << endl << endl;
	fourAngle.push_back(tempPrism4);
	int m;
	cout << "������� ���������� ����������� � ��������������� �����, ������� ����� �������: ";
	cin >> m;
	double lateralSide3 = threeAngle[0].getLateralSide();
	double baseSide3 = threeAngle[0].getBaseSide();
	double lateralSide4 = fourAngle[0].getLateralSide();
	double baseSide4 = fourAngle[0].getBaseSide();
	for (int i = 0; i < m; i++)
	{
		lateralSide3 = lateralSide3 + 20 * pow(3.0, 0.5) / (3.0 * pow(baseSide3, 2));
		tempPrism3.setLateralSide(lateralSide3);
		threeAngle.push_back(tempPrism3);
		cout << "\n������� " << i + 2 << " ����������� ���������� ������ � �������� ������� ������� = "
			<< tempPrism3.getLateralSide() << " � �������� ������� ��������� = " << tempPrism3.getBaseSide()
			<< ".\n�� ����� ����� = " << tempPrism3.getVolume()
			<< ". �� ������� ������� ����������� ����� = " << tempPrism3.getSideSurfaceSquare() << endl;
		lateralSide4 = lateralSide4 + 5.0 / pow(baseSide4, 2);
		tempPrism4.setLateralSide(lateralSide4);
		fourAngle.push_back(tempPrism4);
		cout << "\n������� " << i + 2 << " ��������������� ���������� ������ � �������� ������� ������� = "
			<< tempPrism4.getLateralSide() << " � �������� ������� ��������� = " << tempPrism4.getBaseSide()
			<< ".\n�� ����� ����� = " << tempPrism4.getVolume()
			<< ". �� ������� ������� ����������� ����� = " << tempPrism4.getSideSurfaceSquare() << endl << endl;
	}
}

double countResult(vector<Prism3> threeAngle)
{
	double result = 0;
	for (int i = 0; i < threeAngle.size(); i++)
	{
		result += threeAngle[i].getVolume();
	}
	return result;
}
double countResult(vector<Prism4> fourAngle)
{
	double result = 0;
	for (int i = 0; i < fourAngle.size(); i++)
	{
		result += fourAngle[i].getSideSurfaceSquare();
	}
	return result;
}