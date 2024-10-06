#include "hpp/main.hpp"
#include "hpp/insurance.hpp"
using namespace std;

void about_main::error_input(about_main &main, int count_p)
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