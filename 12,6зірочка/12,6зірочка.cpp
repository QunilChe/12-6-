#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef char Info; // Тип елементів черги (латинські літери)

struct Elem {
	Elem* link; // Покажчик на наступний елемент в черзі
	Info info; // Значення елемента
};

// Додавання елемента до черги
void enqueue(Elem*& first, Elem*& last, Info value) {
	Elem* tmp = new Elem; // Створення нового елемента
	tmp->info = value; // Присвоєння значення
	tmp->link = NULL; // Покажчик на наступний елемент - NULL
	if (last != NULL)
		last->link = tmp; // Якщо черга не порожня, останній елемент посилається на новий елемент
	last = tmp; // Останнім елементом стає новий елемент
	if (first == NULL)
		first = tmp; // Якщо черга була порожня, перший елемент стає новим елементом
}

// Вилучення елемента з черги
Info dequeue(Elem*& first, Elem*& last) {
	Elem* tmp = first->link; // Зберігаємо покажчик наступного елемента
	Info value = first->info; // Зберігаємо значення вилученого елемента
	delete first; // Видаляємо перший елемент
	first = tmp; // Перший елемент - наступний елемент в черзі
	if (first == NULL)
		last = NULL; // Якщо черга порожня, останній елемент стає NULL
	return value; // Повертаємо значення вилученого елемента
}

// Функція для виведення елементів черги
void printQueue(Elem* first) {
	cout << "queue: ";
	Elem* tmp = first;
	while (tmp != NULL) { // Проходження по всіх елементах черги
		cout << tmp->info << " "; // Виведення значення поточного елемента
		tmp = tmp->link; // Перехід до наступного елемента
	}
	cout << endl;
}
void FuckRandom(Elem*& first, Elem*& last)
{
	int timeCounter = 0; 
	while (true) { 
		int action = rand() % 2; 
		int numItems = rand() % 3 + 1;

		if (action == 0) {

			for (int i = 0; i < numItems; i++) {
				char newItem = 'A' + rand() % 26;
				enqueue(first, last, newItem);
			}
			cout << "added " << numItems << " item to queue." << endl;
			printQueue(first);
		}
		else {

			if (first == NULL) {
				cout << "queue empty" << endl;
			}
			else {
				for (int i = 0; i < numItems; i++) {
					char dequeuedItem = dequeue(first, last);
					cout << "dequeue item: " << dequeuedItem << endl;
					if (first == NULL) {
						break;
					}
				}
			}
			printQueue(first);
		}
		timeCounter++;
		if (timeCounter >= 10) {
			break;
		}
	}
}
bool isEmpty(Elem* first) {
	return first == NULL;
}
int main() {
	srand(time(NULL)); // Ініціалізація генератора випадкових чисел
	Elem* first = NULL; // Початковий стан черги - порожня
	Elem* last = NULL;
	FuckRandom(first, last);
	printQueue(first);
	return 0;
}

void FuckRandoerm(Elem*& first, Elem*& last)
{
	int timeCounter = 0; // лічильник часу
	while (true) { // безкінечний цикл
		int action = rand() % 2; // випадковим чином обираємо дію: 0 - додати елементи до черги, 1 - видалити елементи з черги
		int numItems = rand() % 3 + 1; // випадковим чином обираємо кількість елементів, які треба додати або видалити з черги

		if (action == 0) { // якщо обрана дія - додати елементи до черги

			for (int i = 0; i < numItems; i++) { // додаємо випадкові елементи до черги
				char newItem = 'A' + rand() % 26; // випадковий символ в діапазоні від A до Z
				enqueue(first, last, newItem); // додаємо елемент до черги
			}
			cout << "Added " << numItems << " item(s) to the queue." << endl; // виводимо повідомлення про додані елементи
		}
		else { // якщо обрана дія - видалити елементи з черги

			if (first == NULL) { // якщо черга пуста, не можна видалити елементи
				cout << "Queue is empty, cannot dequeue." << endl; // виводимо повідомлення про неможливість видалення елементів
			}
			else { // якщо черга не пуста

				for (int i = 0; i < numItems; i++) { // видаляємо випадкову кількість елементів з черги
					char dequeuedItem = dequeue(first, last); // видаляємо перший елемент з черги
					cout << "Dequeued item: " << dequeuedItem << endl; // виводимо повідомлення про видалений елемент
					if (first == NULL) { // якщо черга порожня після видалення останнього елемента
						break; // виходимо з циклу
					}
				}
			}
		}
		timeCounter++; // збільшуємо лічильник часу
		if (timeCounter >= 10) { // якщо
		}
	}
}