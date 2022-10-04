#include<iostream>
using namespace std;

class AbstrCaculator {
public:

	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;

};


class Add : public AbstrCaculator {
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}

};

class Subtract :public AbstrCaculator {
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

class Multiply :public AbstrCaculator {
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};


void test1() {

	AbstrCaculator* cal = new Add;

	cal->m_Num1 = 100;
	cal->m_Num2 = 100;

	cout << cal->getResult() << endl;

	delete cal;

	cal = new Subtract;

	cal->m_Num1 = 100;
	cal->m_Num2 = 100;

	cout << cal->getResult() << endl;

	delete cal;

	cal = new Multiply;

	cal->m_Num1 = 100;
	cal->m_Num2 = 100;

	cout << cal->getResult() << endl;

	delete cal;

}

int main() {

	test1();

	system("pause");
	return 0;

}