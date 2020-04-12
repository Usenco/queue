#include "systems.h"


int main() {
    
	systems s;
	offense *o = nullptr;
	int a,n,id;
	setlocale(LC_ALL, "rus");
	string file;

	do {
		cout << "0 - выход\n";
		cout << "1 - добавить нарушение\n";
		cout << "2 - удалить нарушение\n";
		cout << "3 - покозать все нарушения\n";
		cout << "4 - покозать нарушения по номеру машини\n";
		cout << "5 - сохранить\n";
		cout << "6 - выгрузить\n";
		cin >> a;
		system("cls");
		switch (a) {
		case 0:break;
		default:cout << "вы ввели не допустимое значение\n";
		case 1:
			if (o != nullptr)delete o;
			o = new offense;
			cin.get();
			cin >> (*o);
			cout << "введите номер машини: "; cin >> n;
			s.addnewoffer(o,n);
			break;
		case 2:
			cout << "введите номер машини и id нарушения: "; cin >> n; cin >> id;
			s.deloffer(id,n);
			break;
		case 3:
			s.show(); break;
		case 4:
			cout << "введите номер машини: "; cin >> n;
			s.show_by_number(n); break;
		case 5:
			cin.get();
			cout << "введите название файла: "; getline(cin, file);
			s.save(file); break;
		case 6:
			s.clear();
			cin.get();
			cout << "введите название файла: "; getline(cin, file);
			s.load(file); break;
		}
	} while (a != 0);


	std::system("pause");
	return 0;
}