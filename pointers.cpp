#include <iostream>

class cowsandbulls {
public:
	int cowscounter(int b[4], int a[4], int* c) { // считает и выводит кол-во коров
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (b[i] == a[j]) {
					++(*c);
				}
			}
		}
		return *c;
	};
	int bullscounter(int b[4], int a[4], int* c) { // считает и выводит кол-во быков
		for (int i = 0; i < 4; ++i) {
			std::cin >> b[i];
			if (b[i] == a[i]) {
				++(*c);
			}
		}
		return *c;
	};
	int computer_number(int a[4]) { // функция, благодаря которой компьютер загадывает число
		for (int i = 0; i < 4; ++i) {
			a[i] = 1 + rand() % 9;
			for (int j = 0; j < i; j++)
				if (a[j] == a[i]) {
					do {
						a[i] = 1 + rand() % 9;
					} while (a[i] == a[j]);
				}
		}
		return 0;
	};
	int your_number(int a[4]) { // функция, благодаря которой игрок загадывает число
		for (int i = 0; i < 4; ++i) {
			std::cin >> a[i];
		}
		return 0;
	};
};


int main() {
	srand(time(NULL));
	int a[4];
	cowsandbulls n1;
	n1.computer_number(a);
	for (int i = 0; i < 4; ++i) {
		std::cout << a[i]; // позволяет увидеть что загадал компьютер, для быстрого прохождения(для обычного прохождения, можно удалить)
	} std::cout << "\n";
	int b[4];
	int c = 0;
	int d = 0;
	int* e = &c;
	int* f = &d;
	std::cout << "the computer guessed the number, try to guess it" << std::endl;
	do {
		cowsandbulls c1;
		c1.bullscounter(b, a, e);
		c1.cowscounter(b, a, f);
		if (c != 4) {
			std::cout << c << " bulls" << std::endl;
			std::cout << d << " cows" << std::endl;
			c = 0;
			d = 0;
		}
	} while (c != 4); // цикл, в котором игрок угадывает число компьютера
	std::cout << "you did it! now it's computer turn to guess, enter your number" << std::endl;
	int ur[4];
	n1.your_number(ur);
	int c1 = 0;
	int d1 = 0;
	int a1[4];
	int result[4];
	int counter = 0;
	do {

		do {
			for (int i = 0; i < 4; ++i) {
				a1[i] = rand() % 9;
				counter++;
			}
		} while (a1[3] != ur[3]);
		result[3] = a1[3];
		c1 = 1;

		do {
			for (int i = 0; i < 3; ++i) {
				a1[i] = rand() % 9;
				counter++;
			}
		} while (a1[2] != ur[2]);
		result[2] = a1[2];
		c1 = 2;

		do {
			for (int i = 0; i < 2; ++i) {
				a1[i] = rand() % 9;
				counter++;
			}
		} while (a1[1] != ur[1]);
		result[1] = a1[1];
		c1 = 4;

		do {
			for (int i = 0; i < 1; ++i) {
				a1[i] = rand() % 9;
				counter++;
			}
		} while (a1[0] != ur[0]);
		result[0] = a1[0];
		c1 = 4;
	} while (c1 != 4); // цикл, в котором компьютер угадывает число игрока
	std::cout << "computer guessed ur number! it is:" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << result[i];
	} std::cout << "\n";
	std::cout << counter << " turns used to guess" << std::endl;
	return 0;
}