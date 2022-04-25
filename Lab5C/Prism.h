#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>
#include <Windows.h>

using namespace std;

class Prism
{
protected:
	double m_lateralSide;
	double m_baseSide;
private:
	int m_baseCorners;
	double getBasePerimetr();
	double getBaseSquare();
public:
	Prism();
	Prism(double lateralSide, double baseSide, int baseCorners);
	void setLateralSide(double side);
	void setBaseSide(double side);
	void setBaseCorners(int amount);
	double getLateralSide();
	double getBaseSide();
	int getBaseCorners();
	double getSideSurfaceSquare();
	double getVolume();
};

class Prism3 : public Prism
{
public:
	Prism3();
	Prism3(double lateralSide, double baseSide);
	void setBaseCorners(int amount) = delete;
	double getSideSurfaceSquare();
	double getVolume();
};

class Prism4 : public Prism
{
public:
	Prism4();
	Prism4(double lateralSide, double baseSide);
	void setBaseCorners(int amount) = delete;
	double getSideSurfaceSquare();
	double getVolume();
};