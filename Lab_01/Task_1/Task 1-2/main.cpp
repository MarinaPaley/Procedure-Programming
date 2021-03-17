#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * \brief Функции перевода из радиан в градусы.
 * \param radian Угол в радианах.
 * \return Возвращает угол в градусах.
 */
double RadianToDegree(double radian);

/**
 * \brief Функция пересчета из дробной части в секунды.
 * \param angleInDegree Угол в градусах с дробной частью.
 * \param angleInDegreeInt Угол в целых градусах.
 * \return Количество секунд.
 */
int TotalSecCount(double angleInDegree, int angleInDegreeInt);

/**
 * \brief Функция находит целое число градусов.
 * \param angle Угол в градусах
 * \return Угол в целых градусах
 */
int DegCount(double angle);

/**
 * \brief Функция пересчета из секунд в минуты.
 * \param secCount Количество секунд.
 * \return Количество минут.
 */
int MinCount(int secCount);

/**
 * \brief Функция расчета секунд как остатка от целого количества минут.
 * \param secCount Общее количество секунд.
 * \return Количество секунд.
 */
int SecCount(int secCount);

//Count sec in minute
const auto secInMin = 60;

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    cout << "Input an angle in radians = ";
    double angleInRadian;
    cin >> angleInRadian;

    const auto angleInDegree = RadianToDegree(angleInRadian);
   
    const auto angleInDegreeInt = DegCount(angleInDegree);
    const auto totalSecWithoutDegree = TotalSecCount(angleInDegree, angleInDegreeInt);
    const auto minCount = MinCount(totalSecWithoutDegree);
    const auto secCount = SecCount(totalSecWithoutDegree);

    cout << setprecision(10)
         << "\nThe angle in degree is " << angleInDegree
         <<"\n" << angleInDegreeInt << " degrees "
         << minCount <<" minutes "
         << secCount << " seconds" << endl;

    return 0;
}

double RadianToDegree(const double radian)
{
    return radian * 180 / M_PI;
}

int TotalSecCount(const double angleInDegree, const int angleInDegreeInt)
{
    const auto decimalPart = angleInDegree - angleInDegreeInt;
    // Count sec in degree
    const auto factor = 3600;
    return static_cast<int>(decimalPart * factor);
}

int DegCount(const double angle)
{
    return static_cast<int>(angle);
}

int MinCount(const int secCount)
{
    return secCount / secInMin;
}

int SecCount(const int secCount)
{
    return secCount % secInMin;
}
