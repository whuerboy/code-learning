#include<iostream>
#include<fstream>//�ļ���
#include<string>
using namespace std;
ofstream ofs;//���������󣬿���д�ļ�
ifstream ifs;//���ļ�

//��������ʱ���������ݶ�������ʱ���ݣ�����һ�������ͻᱻ�ͷ�
//ͨ�����ļ��������Խ����ݳ־û�
//�ļ����ͣ��ı��ļ������ı���AscII����ʽ�洢�ڼ�����У����������ļ�

 //�����ļ������ࣺofstream��д������ ifstream(���ļ�)  fstream(��д)

int main52() {

	//ָ���ļ��򿪷�ʽ��
	ofs.open("ͨѶ¼.txt", ios::out);

	//���ļ���д���ݣ�
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	//�ر��ļ���
	ofs.close();

	ifs.open("ͨѶ¼.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	else {
		//�����ݣ�
		// ��һ�ַ�����
		//char buf[1024] = { 0 };//������ݵ�����
		//while (ifs >> buf)//�����������ݷ���������
		//{
		//	cout << buf << endl;
		//}


		//�ڶ��ַ�����
		/*char buf[1024] = { 0 };
		while (ifs.getline(buf, sizeof(buf))) {
			cout << buf << endl;
		}*/

		 
		//�����ַ�����
			string buf;
		while (getline(ifs, buf)) {
			cout << buf << endl;
		}

		//�����ַ�����
		//char c;
		//while ((c = ifs.get()) != EOF) //EOF:�ļ���β��
		//{
		//	cout << c;
		//}


	}
	ifs.close();

	return 0;

}

