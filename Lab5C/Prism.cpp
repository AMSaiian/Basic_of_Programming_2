#include "Prism.h"

double Prism::getBasePerimetr()
{
    return m_baseSide * m_baseCorners;
}

double Prism::getBaseSquare()
{
    return (pow(m_baseSide, 2) * m_baseCorners) / 4.0 * tan(M_PI / m_baseCorners);
}

Prism::Prism()
{
};

Prism::Prism(double lateralSide, double baseSide, int baseCorners)
{
    if (lateralSide > 0 && baseSide > 0 && baseCorners >= 3)
    {
        m_lateralSide = lateralSide;
        m_baseSide = baseSide;
        m_baseCorners = baseCorners;
    }
    else
        *this = Prism();
}

void Prism::setLateralSide(double side)
{
    if (side > 0)
        m_lateralSide = side;
    else
        m_lateralSide = 1;
}

void Prism::setBaseSide(double side)
{
    if (side > 0)
        m_baseSide = side;
    else
        m_baseSide = 1;
}

void Prism::setBaseCorners(int amount)
{
    if (amount >= 3)
        m_baseCorners = amount;
    else
        amount = 3;
}

double Prism::getLateralSide()
{
    return m_lateralSide;
}

double Prism::getBaseSide()
{
    return m_baseSide;
}

int Prism::getBaseCorners()
{
    return m_baseCorners;
}

double Prism::getSideSurfaceSquare()
{
    return m_lateralSide * getBasePerimetr();
}

double Prism::getVolume()
{
    return m_lateralSide * getBaseSquare();
}

Prism3::Prism3() : Prism(0.0, 0.0, 3)
{
};

Prism3::Prism3(double lateralSide, double baseSide) : Prism(lateralSide, baseSide, 3)
{
}


double Prism3::getSideSurfaceSquare()
{
    return m_lateralSide * m_baseSide * 3;
}

double Prism3::getVolume()
{
    return m_lateralSide * pow(m_baseSide, 2) * pow(3, 0.5) * 0.25;
}

Prism4::Prism4() : Prism(0.0, 0.0, 4)
{
};

Prism4::Prism4(double lateralSide, double baseSide) : Prism(lateralSide, baseSide, 4)
{
};


double Prism4::getSideSurfaceSquare()
{
    return m_lateralSide * m_baseSide * 4;
}

double Prism4::getVolume()
{
    return m_lateralSide * pow(m_baseSide, 2);
}
