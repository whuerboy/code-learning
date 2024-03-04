#include "Menu.h"

Menu::Menu() {
	num = 0;
}

void Menu::addFood(Food f) {
	food[num++] = f;
	cout << "�ɹ����ʳ���ǰ���У�" << num << "��ʳ��\n\n";
}

void Menu::setNum(int x) {
	num = x;
}

void Menu::showFood() {
	cout << "ʳ���й���" << num << "��" << endl;
	cout << "ʳ����  ����\t\t����\t\t�ۿ�" << endl;
	for (int i = 0; i < num; i++)
		cout << setw(10) << setiosflags(ios::left) << i << setw(10) << food[i].getName() << "\t" << food[i].getPrice() << "\t\t" << food[i].getDiscount() << endl;
}

void Menu::changePrice() {
	string s;
	int c;
	double p;
	cout << "������ʳ��ı��:";
	cin >> c;
	s = food[c].getName();
	cout << "��ѡ����ʳ�" << s << endl;
	cout << endl;
	cout << "������۸�";
	cin >> p;
	cout << endl;
	food[c].setPrice(p);


}

void Menu::changeDiscount() {
	string s;
	int c;
	double p;
	cout << "������ʳ��ı��:";
	cin >> c;
	s = food[c].getName();
	cout << "��ѡ����ʳ�" << s << endl;
	cout << endl;
	cout << "�������ۿۣ�0<�ۿ�  �ۿ�<=1����";
	cin >> p;
	cout << endl;
	food[c].setDiscount(p);
	
}

void Menu::delFood() {
	string s;
	int i;
	cout << "�����������";
	cin >> s;
	for (i = 0; i < num; i++) {
		if (food[i].getName() == s) {
			cout << "�ɹ�ɾ��" << s << endl << endl;
			num--;
			for (int j = i; j < num; j++) {
				food[j] = food[j + 1];
				return;
			}
		}
	}
	if (i >= num)
		cout << "û������ʳ��\n\n";
}

void Menu::addFood(string s, double p, double d) {
	Food f(s, p, d);
	num++;
	food[num].setName(s);
	food[num].setPrice(p);
	food[num].setDiscount(d);
	
}

double Menu::getPriceByName(string n) {
	for (int i = 0; i < num; i++) {
		if (n == food[i].getName())
			
			return food[i].getRightPrice();
		return 0;
	}
}

int Menu::getIdByName(string n) {
	for (int i = 0; i < num; i++) {
		if (n == food[i].getName())
			return i;
		return 0;
	}
}

string Menu::getNameById(int i) {
	return food[i].getName();
}

int Menu::getNum() {
	return num;
}