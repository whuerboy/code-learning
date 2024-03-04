#include "SystemMap.h"
SystemMap::SystemMap() {
	frame = "*";
}
int SystemMap::showSystemMap() {
	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << "||";
		else
			cout << " ";
	}
	cout << endl;
	cout << "#\t\t\t��ӭ���ٱ���";
	for (int i = 0; i < 23; i++)
		cout << " ";
	cout << "*\n";
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << frame;
		else
			cout << " ";
	}
	cout << endl;
	cout << "#\t\t  ��������Ҫʲô����\t\t";
	for (int i = 0; i < 11; i++)
		cout << " ";
	cout << "#\n";
	cout << "#\t\t  1:�ڵ�Ͳ�";
	for (int i = 0; i < 31; i++)
		cout << " ";
	cout << "#\n";
	cout << "#\t\t  2:�����Ͳ�";
	for (int i = 0; i < 31; i++)
		cout << " ";
	cout << "#\n";
	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	cout << "\t\t  ������ѡ�����:";
	int choice;
	cin >> choice;
	return choice;

}
void SystemMap::showInsideSystemMap() {
	cout << "��ӭ���ڱ���Ͳͣ������ǲ˵�\n\n";
}
void SystemMap::showOutsideSystemMap() {
	cout << "��ӭ���㱾��������������ǲ˵�\n\n";
}
int SystemMap::showChoiceMap() {
	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << frame;
		else
			cout << " ";
	}
	cout << "\n#\t\t      ��ӭ�������������";
	for (int i = 0; i < 21; i++)
		cout << " ";
	cout << "#\n";
	cout << "#\t\t\t�곤:   ������";
	for (int i = 0; i < 23; i++)
		cout << " ";
	cout << "#\n";
	for (int i = 0; i < 60; i++) {
		if (i == 0 || i == 59)
			cout << frame;
		else
			cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 60; i++)cout << frame;
	cout << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:�˿ͷ���          |" << endl;
	cout << "\t\t|  2:����Աϵͳ        |" << endl;
	cout << "\t\t|  3:�˳�ϵͳ          |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t����ѡ����:";
	int choice;
	cin >> choice;
	return choice;
}
int SystemMap::adminSystemMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:ʳ�����          |" << endl;
	cout << "\t\t|  2:���շ���          |" << endl;
	cout << "\t\t|  3:��������          |" << endl;
	cout << "\t\t|  4:��ʷ�������      |" << endl;
	cout << "\t\t|  5:�˳�              |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cin >> choice;
	return choice;
}
int SystemMap::showRegMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:�¹˿͵��        |" << endl;
	cout << "\t\t|  2:��ѯ����          |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t����ѡ����:";
	cin >> choice;
	return choice;
}
int SystemMap::showClientChoiceMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:���              |" << endl;
	cout << "\t\t|  2:�޸Ķ���          |" << endl;
	cout << "\t\t|  3:�ύ����          |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t����ѡ����:";
	cin >> choice;
	return choice;
}
int SystemMap::showQueryMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:��ѯ����          |" << endl;
	cout << "\t\t|  2:�˳�              |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t����ѡ����:";
	cin >> choice;
	return choice;
}
int SystemMap::showChangeMenuMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:���ʳ��          |" << endl;
	cout << "\t\t|  2:�޸�ʳ��۸�      |" << endl;
	cout << "\t\t|  3:�޸�ʳ���ۿ�      |" << endl;
	cout << "\t\t|  4:ɾ��ʳ��          |" << endl;
	cout << "\t\t|  5:�˳�ʳ�����ϵͳ  |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t����ѡ����:";
	int choice;
	cin >> choice;
	return choice;
}
int SystemMap::showMenuChoice() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:ԭ�˵�            |" << endl;
	cout << "\t\t|  2:�²˵�            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t����ѡ����:";
	cin >> choice;
	return choice;
}
int SystemMap::showCilentOrderMessage() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:�޸�����            |" << endl;
	cout << "\t\t|  2:ɾ��ʳ��            |" << endl;
	cout << "\t\t|  3:�˳��޸�            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t����ѡ����:";
	cin >> choice;
	return choice;
}
int SystemMap::showOrderChangeMap() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:���Ҷ���            |" << endl;
	cout << "\t\t|  2:�޸Ķ���            |" << endl;
	cout << "\t\t|  3:ɾ������            |" << endl;
	cout << "\t\t|  4:�˳��޸�            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t����ѡ����:";
	cin >> choice;
	return choice;
}
int SystemMap::showPastSales() {
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|  1:���Ҷ���            |" << endl;
	cout << "\t\t|  2:�޸Ķ���            |" << endl;
	cout << "\t\t|  3:ɾ������            |" << endl;
	cout << "\t\t|  4:�˳��޸�            |" << endl;
	cout << "\t\t------------------------" << endl;
	int choice;
	cout << "\t\t����ѡ����:";
	cin >> choice;
	return choice;
}