#include <iostream>
#include<iostream>

/*
	   ДОМАШНЕЕ ЗАДАНИЕ:

	   Задание :
	     Программа для проверки правильной расстановки скобок
	   + Напишите функцию которая в качестве параметра получает строку,
		 содержащую скобки вида (, { и [. Пример: std::string s = "({[]})";
	   + Функция возвращает true, если скобки в переданной строке расставлены
		 корректно и false в противном случае.
		 OK: ({[]}), NOT OK: ({[}])
	   + Для решения данной задачи используйте реализованный вами стек
   */


bool Parentheses(std::string value)
{
	bool act = true;
	int size = value.size();
	int endSize = size - 1;

	int roundOn = 0, roundOff = 0, squareOn = 0, squareOff = 0, figurateOn = 0, figurateOff = 0;
	for (int i = 0; i < size; i++) {
		if (value[i] == '(')roundOn++;
		if (value[i] == ')')roundOff++;
		if (value[i] == '{')figurateOn++;
		if (value[i] == '}')figurateOff++;
		if (value[i] == '[')squareOn++;
		if (value[i] == ']')squareOff++;
	}
	int sum = roundOn + roundOff + squareOn + squareOff + figurateOn + figurateOff;
	if (roundOn == roundOff && squareOn == squareOff && figurateOn == figurateOff)
	{
		for (int i = 0; i < size; i++) {
			if (value[i] == 40) {
				sum--;
				act = false;
				for (endSize; endSize >= 0; endSize--) {
					if (value[endSize] == 41) {
						act = true;
						sum--;
						endSize--;
						break;
					}
					if (value[endSize] == 91 || value[endSize] == 93 || value[endSize] == 123 || value[endSize] == 125 || value[endSize] == 40)
						return false;
				}
			}
			if (!act)return false;

			if (value[i] == 91) {
				sum--;
				act = false;
				for (endSize; endSize >= 0; endSize--) {
					if (value[endSize] == 93) {
						sum--;
						act = true;
						endSize--;
						break;
					}

					if (value[endSize] == 91 || value[endSize] == 41 || value[endSize] == 123 || value[endSize] == 125 || value[endSize] == 40)
						return false;
				}
			}
			if (!act)return false;

			if (value[i] == 123) {
				sum--;
				act = false;
				for (endSize; endSize >= 0; endSize--) {
					if (value[endSize] == 125) {
						sum--;
						act = true;
						endSize--;
						break;
					}
					if (value[endSize] == 91 || value[endSize] == 41 || value[endSize] == 123 || value[endSize] == 93 || value[endSize] == 40)
						return false;
				}
			}
			if (!act)return false;

			if (sum == 0)return true;
		}
	}
	else {
		return false;
	}
}
int main()
{
	std::cout << std::boolalpha << Parentheses("((dddddddd[]dddddddd[]))") << '\n';



}
