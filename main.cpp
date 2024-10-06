#include "hpp/main.hpp"
using namespace std;

const char *os = mac;

about_main::about_main()
{
	insurance = new about_insurance();
}

void clear_all(void)
{
	system(os);
}

int main(void)
{
	about_main main;

	while (1)
	{
		clear_all();
		cout << "원하시는 기능을 선택해주세요" << endl;
		cout << "1번 : 4대보험 계산기" << endl;
		cout << "0번 : 종료하기" << endl;
		cin >> main.select;

		if (main.select == main.select1)
		{
			if (main.insurance->insurance_main() == 1)
				continue;
			else
				return (0);
		}
		else if (main.select == main.ex)
		{
			cout << "2초 뒤 종료됩니다." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			return (0);
		}
		else
		{
			//main.error_input(main, 0);
			continue;
		}
	}
}

about_main::~about_main()
{
	delete insurance;
}