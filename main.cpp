#include "hpp/main.hpp"
using namespace std;

about_main::about_main()
{
	about_insurance *insurance();
}

void main(void)
{
	about_main main;

	cout << "원하시는 기능을 선택해주세요" << endl;
	cin >> main.select;

	while (1)
	{
		if (main.select == main.select1)
		{
			main.insurance->insurance_main();
		}
	}
	
}

about_main::~about_main()
{
	delete insurance;
}