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
	result.gookmin = (double)all_money * i.gookmin_24;
	result.gungang = (double)all_money * i.gungang_24;
	result.janggi = result.gungang * i.janggi_24;
	result.goyoung = (double)all_money * i.goyoung_24;
	result.all_result = round(result.gookmin + result.gungang + result.janggi + result.goyoung);

}

static void show_menu_print(void)
{
	cout << "해당 계산기는 근로자용 입니다.\n\n" << endl;
	cout << "[[[24년 4대보험 요율]]]\n 국민연금 : 4.5%\n 건강보험 : 3.545%\n 장기요양보험 : 건강보험의 12.95%\n 고용보험 : 0.9%" << endl;
	cout << "\n\n" << endl;
	cout << "원하는 기능을 선택해주세요\n" << endl;
	cout << "1번, 2024년도 요율적용 계산기" << endl;
	cout << "2번, 각 보험요율 직접입력 전용 계산기" << endl;
	cout << "5번, 프로그램 종료" << endl;
	cout << "0번, 뒤로가기" << endl;
}

int about_insurance::insurance_main(void)
{
	while(1)
	{
		clear_all();
		show_menu_print();
		cin >> select_insurance;

		if (select_insurance == ex)
			return (1);
		else if (select_insurance == select1)
		{
			if (select1_insurance() == 1)
					return (1);
		}
		else if (select_insurance == select2)
		{
			if (select2_insurance() == 1)
				return (1);
		}
		else if (select_insurance == select5)
		{
			cout << "2초후 종료됩니다." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
	}
}