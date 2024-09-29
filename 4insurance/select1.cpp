#include "../hpp/main.hpp"
#include "../hpp/insurance.hpp"
using namespace std;

static void menu_print(void)
{
	cout << "2024년도 4대보험적용 계산기입니다.\n\n"<< endl;
	cout << "[[[24년 4대보험 요율]]]\n 국민연금 : 4.5%\n 건강보험 : 3.545%\n 장기요양보험 : 건강보험의 12.95%\n 고용보험 : 0.9%" << endl;
	cout << "\n\n 세전 총 금액을 입력해주세요" << endl;
}

int about_insurance::select1_insurance(void)
{
	insurance insur;
	insurance_24 insur_24;

	clear_all();
	menu_print();
	while (1)
	{
		cin >> all_money;
		if (all_money <= 0 || all_money > 2100000000)
		{
			clear_all();
			cout << "입력 금액 : " << all_money << "원 입니다." << endl;
			cout << "범위가 잘못되었습니다. 다시 입력해주세요. [허용범위 1 ~ 21억]" << endl;
			continue;
		}
		else
			caculater(insur_24, insur);

		show_print_all(insur); //계산 결과

		cout << "\n\n 메뉴로 가기 : 1번, 재입력하기 2번, 종료하기 : 3번을 눌러주세요." << endl;
		while (1)
		{
			cin >> select_insurance;
			if (select_insurance == select1)
				return (1);
			else if (select_insurance == select2)
				break ;
			else if (select_insurance == select3)
				return (0);
			else
			{
				clear_all();
				cout << "잘못 입력하셨습니다. 메뉴 : 1번, 종료 : 2번을 눌러주세요." << endl;
			}
		}
	}
	return (0);
}