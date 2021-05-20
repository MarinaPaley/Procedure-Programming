#include <iostream>
#include <sstream>

using namespace std;

/**
 * \brief Метод заполнения массива
 * \param size Размер массива
 * \return Заполненный массив
 */
int* get_array(const size_t size);

/**
 * \brief Вывод в строку элементов массива
 * \param size Размер массива
 * \return Строка с элементами
 */
string to_string(const int*, const size_t size);

/**
 * \brief Сортировка пузырьком
 * \param size Размер массива
 */
void bubble_sort(int*, const size_t size);

/**
 * \brief Быстрая сортировка
 * \param array массив
 * \param start_index начальный индекс = 0
 * \param end_index конечный индекс = Размер массива
 */
void quick_sort(int* array, const size_t start_index, const size_t end_index);

/**
 * \brief Обмен значениями двух переменных типа int
 * \param lha left hand argument
 * \param rha right hand argument
 */
void swap(int& lha, int& rha) noexcept;

/**
 * \brief Точка входа в программу
 * \return 0 в случае успеха
 */
int main()
{
    auto error_code = 0;
    int* my_array = nullptr;
    try 
    {
        cout << "Введите размер массива = ";
        size_t size;
        cin >> size;
        my_array = get_array(size);
        cout << "Введенный массив\n";
        cout << to_string(my_array, size);
        bubble_sort(my_array, size);
        cout << "\nОтсортированный массив\n";
        cout << to_string(my_array, size);
        cout << "\n--------\n";
        quick_sort(my_array,0,size);
        cout << "\nОтсортированный массив\n";
        cout << to_string(my_array, size);
    }
    catch (exception& e)
    {
        cout << e.what();
        error_code = 1;
    }

    if (my_array != nullptr)
    {
        delete[] my_array;
        my_array = nullptr;
    }
    return error_code;
}

int* get_array(const size_t size)
{
    if (size == 0)
        throw out_of_range("Неправильный размер массива");

    const auto array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        cout << "Введите " << index + 1 <<" элемент массива = ";
        cin >> array[index];
    }

    return array;
}

string to_string(const int* array, const size_t size)
{
    if (array == nullptr)
        throw invalid_argument("Массив не существует");

    stringstream buffer;
    buffer << "{";
    for (size_t index = 0; index < size - 1; index++)
    {
        buffer << array[index] << ", ";
    }
    buffer << array[size - 1] << "}";
    return buffer.str();
}

void swap(int& lha, int& rha) noexcept
{
    const auto temp = lha;
    lha = rha;
    rha = temp;
}

void bubble_sort(int* array, const size_t size)
{
    if (array == nullptr)
        throw invalid_argument("Массив не существует");

    for (size_t i = 0; i < size - 1; i++)
        for (size_t j =  i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                swap(array[i], array[j]);
            }
        }
}

void quick_sort(int* array, const size_t start_index, const size_t end_index)
{
    if (array == nullptr)
        throw invalid_argument("Массив не существует");

    if (end_index - start_index <= 1)
    {
        return;
    }

    const auto pivot_index = (start_index + end_index) / 2;

    swap(array[start_index], array[pivot_index]);

    size_t last_index = start_index;

    for (size_t index = start_index + 1; index < end_index; index++)
    {
        if (array[index] < array[start_index])
        {
            swap(array[index], array[++last_index]);
        }
    }

    swap(array[start_index], array[last_index]);

    quick_sort(array, start_index, last_index);
    quick_sort(array, last_index + 1, end_index);
}