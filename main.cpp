#include "hpp/main.hpp"
using namespace std;


about_main::about_main()
{
	insurance = new about_insurance();
}

void clear_all(void)
{
	system(mac);
}

static void error_input(about_main &main, int count_p)
{
	int count = count_p;

	clear_all();
	cout << "번호를 잘못 누르셨습니다. 다시 입력해주세요." << endl;
	cin >> main.select;
	if (main.select >= 1 && main.select <= 5)
		return ;
	else if (count == 10)
	{
		clear_all();
		cout << "장난 치지 마세요!, 2초뒤 프로그램을 종료합니다." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		exit(1);
	}
	else if (count < 10)
	{
		cout << "check " << count_p << endl;
		error_input(main, ++count);
	}
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
		}
		else if (main.select == main.exit)
		{
			cout << "2초 뒤 종료됩니다." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			return (0);
		}
		else
		{
			error_input(main, 0);
			continue;
		}
	}
}

about_main::~about_main()
{
	delete insurance;
}