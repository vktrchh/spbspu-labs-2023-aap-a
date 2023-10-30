#include <iostream>

int main ()
{
  std::cout << "Введите последовательность чисел: ";
  int num;
  bool hasInput = false;

  while (std::cin >> num){
    hasInput = true;
    if (num == 0) {
        if(!hasInput) {
            std::cerr << "Ошибка! Пустая последовательность." << std::endl;
            return 2;
        }
        break;
    }
  }

  return 0;
}