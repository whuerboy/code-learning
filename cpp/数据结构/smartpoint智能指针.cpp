#include<iostream>
//����ָ���ǻ��ڴ���ʱ�Զ������ڴ�Ȼ���Զ��ں��ʵ�ʱ�����ٵ�
class elevent {
public:
	elevent() {
		std::cout << "���캯���ĵ���" << std::endl;
	}
	~elevent() {
		std::cout << "���������ĵ���" << std::endl;
	}
	void print() {
		std::cout << "print" << std::endl;
	}
};

int main14() {
	{
		std::unique_ptr<elevent> e = std::make_unique<elevent>();//std::unique_ptr<ele>e(new ele())���ַ���������쳣��ȫ������
		//����ָ�벻��ͨ����ֵ��һ��ָ��õ�����Ϊ���ǹ�ָ��һ���ڴ棬һ����ɾ����ᵼ���ڴ�й¶
		e->print();
	}


	{ 
		std::shared_ptr<elevent>s0;
		{
		std::shared_ptr<elevent> s = std::make_shared<elevent>();
		s0 = s;
		//std::shared_ptr<elevent>s(new elevent());һ�㲻��������share_ptr����һ�����ƿ飬ʹ��new�����Ὺ�������ڴ棬��make����ֱ�ӽ����ǽ��������
		//������shareָ�븳ֵʱ�����������ü����������ü���Ϊ0ʱ���ײ��eleveant�Żᱻ������
		//����Ҫ����ָ�븴�ƶ��������ü����Ļ�����Ҫʹ��weakָ��

		}	
	}


	{
		std::weak_ptr<elevent> w;
		{
			std::shared_ptr<elevent>s = std::make_shared<elevent>();
			w = s;
		}
	}


	return 0;
}