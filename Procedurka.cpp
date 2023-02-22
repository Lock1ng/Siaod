#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


struct UP {
	int shifr{};
	int year{};
	string namenaprav{};
	string shifrprofile{};
	string nameprofile{};
};

UP input_nap(UP s) {
	cout << "Введите название направления: ";
	getline(cin, s.namenaprav);
	cout << "Введите шифр профиля: ";
	getline(cin, s.shifrprofile);
	cout << "Введите название профиля: ";
	getline(cin, s.nameprofile);
	cout << "Введите год УП: ";
	cin >> s.year;
	cout << "Введите шифр направления: ";
	cin >> s.shifr;
	return s;
}

bool compareTwoStudents(UP a, UP b)
{
	return a.shifr > b.shifr;
}

void computeRanks(UP a[], int cnt)
{
	sort(a, a + cnt + 1, compareTwoStudents);
}

void input_massiv_nap(UP *one, int i) {
	cout << one[i].namenaprav << endl;
	cout << one[i].shifrprofile << endl;
	cout << one[i].nameprofile << endl;
	cout << one[i].year << endl;
	cout << one[i].shifr << endl;
};
int find_index(UP* s, UP d, int maxx) {
	int i = 0;
	for (i; i < maxx; i++) {
		if (s[i].shifr == d.shifr) {
			return i;
		}
	}
}
int find_index_first(UP* s, int d, int maxx) {
	int i = 0;
	for (i; i < maxx; i++) {
		if (s[i].shifr == d) {
			return i;
		}
	}
}
int find_index_last(UP* s, int d, int maxx) {
	int i = 0;
	for (i; i < maxx; i++) {
		if ((s[i].shifr == d) && (s[i + 1].shifr != d)) {
			return i;
		}
	}
}
int delete_year(UP *one, int cnt) {
	int i = 0;
	for (i; i < cnt + 1; i++) {
		if (2023 - one[i].year > 4) {
			one[i].namenaprav = '0';
			one[i].shifrprofile = '0';
			one[i].nameprofile = '0';
			one[i].year = 0;
			one[i].shifr = 0;
			cnt = cnt - 1;
		}
	}
	return cnt;
}
void permutations(UP *s, UP d, int j, int cnt) {
	int i = 0;
	for (i = cnt; i >= j; i--) {
			s[i + 1] = s[i];
	}
	s[j] = d;
}
int main() {

	system("chcp 1251");
	system("cls");
	int cnt = 0;
	int i = 0;
	int otvet;
	const int maxx = 99;
	bool a = true;
	UP one;
	UP users[maxx + 1];
	UP test;
	UP users_test;
	cout << "Выберите режим:\n1.Заполнить запись по одному учебному плану с клавиатуры.\n\
2.Вставить запись в таблицу планов в начало подсписка, с одним и тем же шифром направления.\
\n3.Вывести названия профилей и год начала действия учебного плана заданного направления\n\
4.Удалить планы срок действия которых истек при прошествии 4-х лет.\n\
5.Вывести все данные\n\
6.Завершить работу\n" << endl;
	while (a) {
		cin >> otvet;
		cin.get();
			if (otvet == 1) {
				users[i] = input_nap(one);
				cnt++;
				i++;
				computeRanks(users, cnt);
			}
			if (otvet == 2) {
				test = input_nap(one);
				computeRanks(users, cnt);
				permutations(users, test, find_index(users, test, cnt), cnt);
				i++;
				cnt++;
			}
			if (otvet == 3) {
				cout << "Введите заданное направление: ";
				int k;
				cin >> k;
				int j = find_index_first(users, k, cnt);
				cout.width(25);
				cout << left << "Название профиля";
				cout.width(25);
				cout << left << "Год начала действия УП" << endl;
				for (j; j <= find_index_last(users, k, cnt); j++) {
					cout.width(25);
					cout << left << users[j].namenaprav;
					cout.width(25);
					cout << left << users[j].year << endl;
				}
			}
			if (otvet == 4) {
				cnt = delete_year(users, cnt);
				computeRanks(users, cnt);
			}
			if (otvet == 5) {
				int j = 0;
				cout.width(25);
				cout << left << "Название направления";
				cout.width(25);
				cout << left << "Шифр профиля";
				cout.width(25);
				cout << left << "Название профиля";
				cout.width(25);
				cout << left << "Год начала действия УП";
				cout.width(25);
				cout << left << "Шифр направления" << endl;
				for (j; j < cnt; j++) {
					cout.width(25);
					cout << left << users[j].namenaprav;
					cout.width(25);
					cout << left << users[j].shifrprofile;
					cout.width(25);
					cout << left << users[j].nameprofile;
					cout.width(25);
					cout << left << users[j].year;
					cout.width(25);
					cout << left << users[j].shifr << endl;

				}
			}
			if (otvet == 6) {
				return 0;
			}
			cout << "\nВыберите режим:\n1.Заполнить запись по одному учебному плану с клавиатуры.\n\
2.Вставить запись в таблицу планов в начало подсписка, с одним и тем же шифром направления.\
\n3.Вывести названия профилей и год начала действия учебного плана заданного направления\n\
4.Удалить планы срок действия которых истек при прошествии 4-х лет.\n\
5.Вывести все данные\n\
6.Завершить работу\n" << endl;
	}
}