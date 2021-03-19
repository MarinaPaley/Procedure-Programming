#include <iostream>

using namespace std;

/**
 * \brief Расчет тока во втором участке цепи по Первому закону Кирхгофа.
 * \param totalCurrent Значение тока полной цепи.
 * \param otherCurrent Значение тока в первом участке.
 * \return Значение тока во втором участке.
 */
double KirchhoffFirstLaw(double totalCurrent, double otherCurrent);

/**
 * \brief Расчет сопротивления по закону Ома.
 * \param voltage Напряжение, В.
 * \param current Ток, А.
 * \return Сопротивление, Ом.
 */
double OmhLaw(double voltage, double current);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    const auto voltage = 220.0;

    cout << "Input current in circuit = ";
    double I;
    cin >> I;

    cout << "Input current in the first circuit = ";
    double I1;
    cin >> I1;

    const auto I2 = KirchhoffFirstLaw(I, I1);
    cout << "Current in the second circuit is = " << I2 << "\n";

    const auto R2 = OmhLaw(voltage, I2);
    cout << "Resistance in the second circuit is = " << R2 << endl;

    return 0;
}

double KirchhoffFirstLaw(const double totalCurrent, const double otherCurrent)
{
    return totalCurrent - otherCurrent;
}

double OmhLaw(const double voltage, const double current)
{
    return voltage / abs(current);
}

//
//Две лампы соединены параллельно.
//Напряжение участка цепи 220 В.
//Сила тока в цепи равна I А, сила тока на первой лампе I1 А.
//Определите силу тока во второй лампе и её сопротивление.