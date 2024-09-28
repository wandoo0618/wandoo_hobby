#include "../hpp/main.hpp"
#include "../hpp/insurance.hpp"

using namespace std;

string addComma(int number)
{
    stringstream ss;
    ss.imbue(locale(""));  // 기본 로케일을 사용
    ss << fixed << number;
    return ss.str();
}

void about_insurance::show_print_all(insurance &insur)
{
	cout << "계산 결과입니다. (소수점은 반올림하여 계산됩니다.)" << endl;
	cout << "\n\n 국민연금 : " << addComma(round(insur.gookmin)) << "원 입니다." << endl;
	cout << " 건강보험 : " << addComma(round(insur.gungang)) << "원 입니다." << endl;
	cout << " 장기요양보험 : " << addComma(round(insur.janggi)) << "원 입니다." << endl;
	cout << " 고용보험 : " << addComma(round(insur.goyoung)) << "원 입니다." << endl;
	cout << "\n\n 보험료 합계 : " << addComma(insur.all_result) << "원 입니다." << endl;
	cout << "\n\t [[[세후 금액 : " << addComma(all_money - insur.all_result) << "원 입니다.]]]" << endl;

}

void about_insurance::caculater(insurance_24 &i, insurance &result)
{
	i.gookmin_24 = gookmin_per;
	i.gungang_24 = gungang_per;
	i.janggi_24 = janggi_per;
	i.goyoung_24 = goyoung_per;
	result.gookmin = all_money * i.gookmin_24;
	result.gungang = all_money * i.gungang_24;
	result.janggi = result.gungang * i.janggi_24;
	result.goyoung = all_money * i.goyoung_24;
	result.all_result = round(result.gookmin + result.gungang + result.janggi + result.goyoung);

}

int about_insurance::select1_insurance(void)
{
	insurance insur;
	insurance_24 insur_24;
	clear_all();
	cout << "2024년도 4대보험요율 계산기입니다.\n\n"
		 << endl;
	cout << "[[[24년 4대보험 요율]]]\n 국민연금 : 4.5%\n 건강보험 : 3.545%\n 장기요양보험 : 건강보험의 12.95%\n 고용보험 : 0.9%"
		 << endl;
	cout << "\n\n 세전 총 금액을 입력해주세요" << endl;
	cin >> all_money;

	while (1)
	{
		clear_all();
		if (all_money <= 0 || all_money > 2147483647)
		{
			clear_all();
			cout << "입력 금액 : " << all_money << "원 입니다." << endl;
			cout << "범위가 잘못되었습니다. 다시 입력해주세요. [허용범위 1 ~ 백억]" << endl;
			cin >> all_money;
			continue;
		}
		else
		{
			caculater(insur_24, insur);

		}
		break;
	}
	show_print_all(insur);

	cout << "\n\n 메뉴로 가기 : 1번, 종료하기 : 2번을 눌러주세요." << endl;
	while (1)
	{
		cin >> select_insurance;
		if (select_insurance == select1)
			return (1);
		else if (select_insurance == select2)
			exit(0);
		else
		{
			clear_all();
			cout << "잘못 입력하셨습니다. 메뉴 : 1번, 종료 : 2번을 눌러주세요." << endl;
		}
	}
	return (0);
}

int about_insurance::insurance_main(void)
{


	while(1)
	{
		clear_all();
		cout << "해당 계산기는 근로자용 입니다.\n\n" << endl;
		cout << "[[[24년 4대보험 요율]]]\n 국민연금 : 4.5%\n 건강보험 : 3.545%\n 장기요양보험 : 건강보험의 12.95%\n 고용보험 : 0.9%" << endl;
		cout << "\n\n" << endl;

		cout << "원하는 기능을 선택해주세요\n" << endl;
		cout << "1번, 2024년도 요율적용 계산기" << endl;
		cout << "2번, 각 보험요율 직접입력 전용 계산기" << endl;
		cin >> select_insurance;
	

		if (select_insurance == select1)
		{
			if (select1_insurance() == 1)
				{
					return (1);
				}
		}
	}
}