#include <iostream>
#include <string>

using namespace std;

/**
 * \brief Перечислимый тип фигур, для которых считаем площадь.
 */
enum class Figure
{
    /**
     * \brief Неправильно сформированный выбор.
     */
    none,

    /**
     * \brief Выбранная фигура -- прямоугольник.
     */
    rectangle,

    /**
     * \brief Выбранная фигура -- треугольник.
     */
    triangle
};

/**
 * \brief Функция расчета площади прямоугольника.
 * \param width ширина прямоугольника.
 * \param length длина прямоугольника.
 * \return Площадь прямоугольника.
 */
double GetRectangleArea(const double width, const double length);

/**
 * \brief Функция расчета площади треугольника.
 * \param a первая сторона треугольника.
 * \param b вторая сторона треугольника.
 * \param c третья сторона треугольника.
 * \return Площадь треугольника.
 */
double GetTriangleArea(const double a, const double b, const double c);

/**
 * \brief Ввод стороны фигуры.
 * \param message Разъясняющая надпись.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return Сторону фигуры.
 */
double ReadSide(const string& message = "", ostream& out = cout, istream& in = cin);

/**
 * \brief 
 * \param message Сообщение для пользователя.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return Выбор пользователя.
 */
Figure ReadUserChoice(const string& message = "", ostream& out = cout, istream& in = cin);

/**
 * \brief Точка вход в программу
 * \return Код ошибки, если 0 - успешное выполнение
 */
int main()
{
    const auto message = "Выберите фигуру для расчет площади: "
        + to_string(static_cast<int>(Figure::rectangle)) + " - прямоугольник, "
        + to_string(static_cast<int>(Figure::triangle)) + " - треугольник";

    const auto figure = ReadUserChoice(message);
   
    switch (figure)
    {
        case Figure::rectangle:
        {
            const auto width = ReadSide("Введите ширину прямоугольника = ");
            const auto length = ReadSide("Введите длину прямоугольника = ");

            const auto rectangleArea = GetRectangleArea(width, length);
            cout << "\nПлощадь прямоугольника " << rectangleArea << endl;
            break;
        }
        case Figure::triangle:
        {
            const auto a = ReadSide("Введите первую сторону треугольника = ");
            const auto b = ReadSide("Введите вторую сторону треугольника = ");
            const auto c = ReadSide("Введите третью сторону треугольника = ");

            const auto triangleArea = GetTriangleArea(a, b, c);
            cout << "\nПлощадь треугольника " << triangleArea << endl;
            break;
        }
    default:
        cout << "Ошибка!";
    }

    return 0;
}

double GetRectangleArea(const double width, const double length)
{
    return width * length;
}

double GetTriangleArea(const double a, const double b, const double c)
{
    const auto semiperimeter= (a + b + c) / 2;
    return sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
}

double ReadSide(const string& message, ostream& out, istream& in)
{
    out << message;
    double side;
    in >> side;
    return side;
}

Figure ReadUserChoice(const string& message, ostream& out, istream& in)
{
    out << message;
    int userInput;
    in >> userInput;
    return static_cast<Figure>(userInput);
}
