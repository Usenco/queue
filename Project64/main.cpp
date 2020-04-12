#include "systems.h"


int main() {
    
	systems s;
	offense *o = nullptr;
	int a,n,id;
	setlocale(LC_ALL, "rus");
	string file;

	do {
		cout << "0 - �����\n";
		cout << "1 - �������� ���������\n";
		cout << "2 - ������� ���������\n";
		cout << "3 - �������� ��� ���������\n";
		cout << "4 - �������� ��������� �� ������ ������\n";
		cout << "5 - ���������\n";
		cout << "6 - ���������\n";
		cin >> a;
		system("cls");
		switch (a) {
		case 0:break;
		default:cout << "�� ����� �� ���������� ��������\n";
		case 1:
			if (o != nullptr)delete o;
			o = new offense;
			cin.get();
			cin >> (*o);
			cout << "������� ����� ������: "; cin >> n;
			s.addnewoffer(o,n);
			break;
		case 2:
			cout << "������� ����� ������ � id ���������: "; cin >> n; cin >> id;
			s.deloffer(id,n);
			break;
		case 3:
			s.show(); break;
		case 4:
			cout << "������� ����� ������: "; cin >> n;
			s.show_by_number(n); break;
		case 5:
			cin.get();
			cout << "������� �������� �����: "; getline(cin, file);
			s.save(file); break;
		case 6:
			s.clear();
			cin.get();
			cout << "������� �������� �����: "; getline(cin, file);
			s.load(file); break;
		}
	} while (a != 0);


	std::system("pause");
	return 0;
}