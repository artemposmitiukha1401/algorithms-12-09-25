#include <iostream>
#include <iomanip>

const int MIN_RAND = -100;
const int MAX_RAND = 100;

template <typename T,  const size_t SIZE>
void PrintArr(const T (&arr)[SIZE]) {
    for (size_t i = 0; i < SIZE; i++)
        std::cout << arr[i] << " | ";

    std::cout << std::endl;
}

template <typename T, const size_t SIZE>
void FillArr(T (&arr)[SIZE]) {
    for (size_t i = 0; i < SIZE; i++)
        arr[i] = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
    PrintArr(arr);
}
template <typename T, const size_t SIZE>
void FillArr(T (&arr)[SIZE], const int min_range, const int max_range) {
    for (size_t i = 0; i < SIZE; i++)
        arr[i] = rand() % (max_range - min_range + 1) + min_range;
    PrintArr(arr);
}
template <typename T, const size_t SIZE>
void FillArrManually(T (&arr)[SIZE]) {
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << i + 1 << " - ";
        std::cin >> arr[i];
    }
    PrintArr(arr);
}

template <typename T, const size_t SIZE>
void SortArr(T (&arr)[SIZE]) {
    for (size_t i = 0; i < SIZE - 1; i++) {
        for (size_t j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
    PrintArr(arr);
}


template <typename T, const size_t SIZE>
void FindSum (const T (&arr)[SIZE], const int sum) {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = i + 1; j < SIZE; j++) {
            if (arr[i] + arr[j] == sum)
                std::cout << arr[i] << " + " << arr[j] << " = " << sum << std::endl;
        }
    }
}

template <typename T, const size_t SIZE>
void CompareIncome(const T (&year_income_list)[SIZE], const size_t min_range, const size_t max_range) {
    size_t start_index = min_range - 1;
    size_t end_index = max_range - 1;

    size_t max_income_month = start_index;
    size_t min_income_month = start_index;

    for (size_t i = start_index; i <= end_index; i++) {
        if (year_income_list[i] > year_income_list[max_income_month])
            max_income_month = i;
        if (year_income_list[i] < year_income_list[min_income_month])
            min_income_month = i;
    }

    std::cout << "Your max income month was: " << max_income_month + 1
              << "\nTotal income: " << year_income_list[max_income_month] << std::endl;

    std::cout << "Your min income month was: " << min_income_month + 1
              << "\nTotal income: " << year_income_list[min_income_month] << std::endl;
}


template <typename T, const size_t SIZE>
void CalcualateNegativesSum(const T (&arr)[SIZE]) {
    int negatives_sum = 0;
    for (size_t i = 0; i < SIZE; i++) {
        if (arr[i] < 0)
            negatives_sum += -arr[i];
    }
    std::cout << "Sum of negatives is: " << negatives_sum << std::endl;
}

template <typename T, const size_t SIZE>
void ProductBetweenMinMax(const T (&arr)[SIZE]) {
    size_t min_index = 0;
    size_t max_index = 0;
    int product = 1;

    for (size_t i = 0; i < SIZE; i++) {
        if (arr[i] < arr[min_index])
            min_index = i;
        if (arr[i] > arr[max_index])
            max_index = i;
    }
    std::cout << "Min value: " << arr[min_index] << "\nMax value: " << arr[max_index] << std::endl;
    if (min_index > max_index)
        std::swap(min_index, max_index);

    for (size_t i = min_index + 1; i < max_index; i++)
        product *= arr[i];

    std::cout << "Product between positions [" << min_index << "] and [" << max_index << "] is " << product << std::endl;
}


template <typename T, const size_t SIZE>
void ProductOfEven(const T (&arr)[SIZE]) {
    int product = 1;
    for (size_t i = 0; i < SIZE; i++)
        if (i % 2 == 0)
            product *= arr[i];
    std::cout << "Product of elements on even positions is : " << product << std::endl;
}

template <typename T, const size_t SIZE>
void SumBetweenNegatives(const T (&arr)[SIZE]) {
    int first_negative_index = -1;
    int last_negative_index = -1;
    int sum = 0;

    for (size_t i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            if (first_negative_index == -1) {
                first_negative_index = i;
            }
            last_negative_index = i;
        }
    }

    if (first_negative_index == -1 || last_negative_index == -1) {
        std::cout << "No negative numbers in the array\n";
        return;
    }
    for (size_t i = first_negative_index; i <= last_negative_index; i++)
        sum += arr[i];

    std::cout << "Sum between positions [" << first_negative_index << "] and [" << last_negative_index << "] is " << sum << std::endl;
}
const size_t RAND_NUM_SIZE = 4;
int random_number[RAND_NUM_SIZE];
int attempts = 0;

template <typename T, const size_t RAND_NUM_SIZE>
void GenerateNumber(T (&random_number)[RAND_NUM_SIZE]) {
    for (size_t i = 0; i < RAND_NUM_SIZE; i++)
        random_number[i] = rand() % (9 - 1 + 1) +1;
}

void DivideNumber(int num, int digits[], int current_index) {
    if (current_index < 0) return;
    digits[current_index] = num % 10;
    DivideNumber(num / 10, digits, current_index - 1);
}
int CountCows(int user_guess[], int current_index) {
    if (current_index >= 4) return 0;
    return (user_guess[current_index] == random_number[current_index] ? 1 : 0) + CountCows(user_guess, current_index + 1);
}
int CountBulls(int user_guess[], int current_index) {
    if (current_index >= 4) return 0;

    int bulls = 0;
    for (int i = 0; i < 4; i++) {
        if (i != current_index && user_guess[current_index] == random_number[i]) {
            bulls = 1;
            break;
        }
    }
    return bulls + CountBulls(user_guess, current_index + 1);
}

void BullsAndCows() {
    attempts++;
    int user_number = 0;
    int user_guess[4];
    std::cout << "Enter your guess: "; std::cin >> user_number;
    DivideNumber(user_number, user_guess, 3);
    int cows_count = CountCows(user_guess, 0);
    int bulls_count = CountBulls(user_guess, 0);
    std::cout << "Bulls: " << bulls_count << " | Cows: " << cows_count << std::endl;

    if (cows_count == 4) {
        std::cout << "You won!" << "\nAmount of attempts: " << attempts << std::endl;
        std::cout << "Random number was: ";
        for (int num: random_number) std::cout << num << " ";
        return;
    }
    BullsAndCows();
}

struct Cell {
    int x = 0, y = 0;
    bool isPassed = 0;
    int found_index = -1;
};
struct Knight {
    int x = 0, y = 0;
    int current_dr_index = 0;
};

int x_directions[] = {2, 1, -1, -2, -2, -1, 1, 2};
int y_directions[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int BOARD_SIZE = 6;
Knight knight;
Cell board[BOARD_SIZE][BOARD_SIZE];
int total_moves = 0;

void InitializeBoard() {
    for (size_t i = 0; i < BOARD_SIZE; i++) {
        for (size_t j = 0; j < BOARD_SIZE; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
}
void PrintBoard() {
    for (size_t i = 0; i < BOARD_SIZE; i++) {
        for (size_t j = 0; j < BOARD_SIZE; j++) {
            std::cout << "[" << std::setw(3) << board[i][j].found_index << "] ";
        }
        std::cout << std::endl;
    }
}
bool ValidateNextMove(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE &&
            y >= 0 && y < BOARD_SIZE &&
            !board[x][y].isPassed);
}

bool CalculatePath(int knight_position_x, int knight_position_y) {
    knight.x = knight_position_x;
    knight.y = knight_position_y;

    board[knight_position_x][knight_position_y].isPassed = true;
    board[knight_position_x][knight_position_y].found_index = total_moves++;

    if (total_moves == BOARD_SIZE * BOARD_SIZE) {
        PrintBoard();
        return true;
    }

    for (size_t direction = 0; direction < 8; direction++) {
        int next_move_x = knight_position_x + x_directions[direction];
        int next_move_y = knight_position_y + y_directions[direction];

        if (ValidateNextMove(next_move_x, next_move_y))
            if (CalculatePath(next_move_x, next_move_y)) return true;

    }

    board[knight_position_x][knight_position_y].isPassed = false;
    board[knight_position_x][knight_position_y].found_index = -1;
    total_moves--;

    return false;
}

int main() {
    srand(time(nullptr));

    // const size_t SIZE = 20;
    // В одномерном массиве, заполненном случайными числами,
    // определить минимальный и максимальный элементы.

    // int arr[SIZE];
    // FillArr(arr);
    // SortArr(arr);
    // int min_num = arr[0];
    // int max_num = arr[SIZE - 1];
    // std::cout << "Minimum number is " << min_num << "\nMax number is " << max_num << std::endl;


    // В одномерном массиве, заполненном случайными числами
    // в заданном пользователем диапазоне, найти сумму элементов,
    // значения которых меньше указанного пользователем.

    // int min_range = 0;
    // int max_range = 0;
    // int values_sum;
    // int arr[SIZE];
    // do {
    //     std::cout << "Enter min range value: ";  std::cin >> min_range;
    // } while (min_range < 0);
    // do {
    //     std::cout << "Enter max range value: ";  std::cin >> max_range;
    // } while (max_range < 0 || max_range < min_range);
    // do {
    //     std::cout << "Enter sum of values to search for: ";  std::cin >> values_sum;
    // } while (values_sum < 0);
    //
    // FillArr(arr, min_range, max_range);
    // FindSum(arr, values_sum);

    // Пользователь вводит прибыль фирмы за год (12 месяцев).
    // Затем пользователь вводит диапазон (например, 3 и 6 — поиск
    // между 3-м и 6-м месяцем). Необходимо определить месяц,
    // в котором прибыль была максимальна и месяц, в котором
    // прибыль была минимальна с учетом выбранного диапазона.

    // int year_income_list[12];
    // int min_range = 0;
    // int max_range = 0;
    // std::cout << "Fill info for financial year: \n";
    // FillArrManually(year_income_list);
    // do {
    //     std::cout << "Enter minimum year income month to check: "; std::cin >> min_range;
    // } while (min_range < 0);
    // do {
    //     std::cout << "Enter maximum year income month to check: "; std::cin >> max_range;
    // } while (max_range < 0 || max_range < min_range);
    // CompareIncome(year_income_list, min_range, max_range);


    // В одномерном массиве, состоящем из N вещественных
    // чисел вычислить:
    // - Сумму отрицательных элементов.
    // - Произведение элементов, находящихся между min и max
    // элементами.
    // - Произведение элементов с четными номерами.
    // - Сумму элементов, находящихся между первым и последним отрицательными элементами.

    // int arr[SIZE];
    // FillArr(arr);
    // CalcualateNegativesSum(arr);
    // ProductBetweenMinMax(arr);
    // ProductOfEven(arr);
    // SumBetweenNegatives(arr);

    // Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий должен угадать его.
    // После ввода пользователем числа программа сообщает, сколько цифр числа угадано (быки) и сколько цифр
    // угадано и стоит на нужном месте (коровы). После отгадывания числа на экран необходимо вывести количество
    // сделанных пользователем попыток. В программе необходимо использовать рекурсию.

    // GenerateNumber(random_number);
    // BullsAndCows();

    // 10. Дана шахматная доска размером 8х8 и шахматный конь. Программа
    // должна запросить у пользователя координаты клетки поля и поставить туда коня.
    // Задача программы найти и вывести путь коня, при котором он обойдет все клетки
    // доски, становясь в каждую клетку только один раз. (Так как процесс отыскания
    // пути для разных начальных клеток может затянуться, то рекомендуется сначала
    // опробовать задачу на поле размером 6хб). В программе необходимо использовать рекурсию.

    // Сделал не самым эффективным способом, но по другому не получилось
    InitializeBoard();
    int start_position_x = 0, start_position_y = 0;
    do {
        std::cout << "Enter start position for x (< 6): "; std::cin >> start_position_x;
    }while (start_position_x < 0 || start_position_x > BOARD_SIZE);

    do {
        std::cout << "Enter start position for y (< 6): "; std::cin >> start_position_y;
    }while (start_position_y < 0 || start_position_y > BOARD_SIZE);

    CalculatePath(start_position_x, start_position_y);

}