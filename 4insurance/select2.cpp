#include "../hpp/main.hpp"
#include "../hpp/insurance.hpp"
using namespace std;

static void show_menu_print(void)
{
	clear_all();
	cout << "[[[4대보험 요율 직접적용 모드입니다.]]]" << endl;
	cout << "\n\t각 보험에 적용할 %를 입력해주세요." << endl;
}

static void error_range(void)
{
	cout << "범위를 잘못 입력하였습니다. 다시 입력해주세요." << endl;
	cout << "허용 범위 [0 ~ 100], 소수점 가능" << endl;
}

int about_insurance::insur_init(insurance_24 &i)
{
	int button;
	while (1)
	{
		cout << "\n\n 국민연금보험 요율을 입력해주세요. [0 ~ 100%]" << endl;
		cin >> i.gookmin_24;
		cout << "입력 국민연금 요율 : " << i.gookmin_24 << "%" << endl;
		clear_all();
		if (i.gookmin_24 < 0 || i.gookmin_24 > 100)
		{
			error_range();
			continue ;
		}
		else
			break ;
	}
	while(1)
	{
		cout << "\n\n 건강보험 요율을 입력해주세요. [0 ~ 100%]" << endl;
		cin >> i.gungang_24;
		cout << "입력 건강보험 요율 : " << i.gungang_24 << "%" << endl;
		clear_all();
		if (i.gungang_24 < 0 || i.gungang_24 > 100)
		{
			error_range();
			continue;
		}
		else
			break ;
	}
	while(1)
	{
		cout << "\n\n 장기요양보험 요율을 입력해주세요. [0 ~ 100%]" << endl;
		cin >> i.janggi_24;
		cout << "입력 장기요양보험 요율 : " << i.janggi_24 << "%" << endl;
		clear_all();
		if (i.janggi_24 < 0 || i.janggi_24 > 100)
		{
			error_range();
			continue;
		}
		else
			break;
	}
	while(1)
	{
		cout << "\n\n 고용보험 요율을 입력해주세요. [0 ~ 100%]" << endl;
		cin >> i.goyoung_24;
		cout << "입력 고용보험 요율 : " << i.goyoung_24 << "%" << endl;
		clear_all();
		if (i.goyoung_24 < 0 || i.goyoung_24 > 100)
		{
			error_range();
			continue;
		}
		else
			break ;
	}

	cout << "입력된 4대보험 요율" << endl;
	cout << "국민연금 : " << i.gookmin_24 << "%" << endl;
	cout << "건강보험 : " << i.gungang_24 << "%" << endl;
	cout << "장기요양보험 : " << i.janggi_24 << "%" << endl;
	cout << "고용보험 : " << i.goyoung_24 << "%" << endl;

	i.gookmin_24 /= 100;
	i.gungang_24 /= 100;
	i.janggi_24 /= 100;
	i.goyoung_24 /= 100;

	cout << "\n\n1번 : 다시 입력하기, 2번 : 다음으로, 3번 : 종료하기" << endl;
	cin >> button;
	if (button == 1) // 다시 입력
		insur_init(i);
	else if (button == 2) // 다음으로
		return (0);
	else if (button == 3) //종료
		return(1);
	return (0);
}

void about_insurance::insur_caculater(insurance &result, insurance_24 &i)
{
	while(1)
	{
		clear_all();
		cout << "수입을 입력해주세요." << endl;
		cin >> all_money;

		if (all_money < 0 || all_money >= 2100000000)
		{
			clear_all();
			cout << "입력 금액 : " << all_money << "원 입니다." << endl;
			cout << "범위가 잘못되었습니다. 다시 입력해주세요. [허용범위 1 ~ 21억]" << endl;
			continue;
		}
		else
			break ;
	}
	
	result.gookmin = (double)all_money * i.gookmin_24;
	result.gungang = (double)all_money * i.gungang_24;
	result.janggi = (double)result.gungang * i.janggi_24;
	result.goyoung = (double)all_money * i.goyoung_24;
	result.all_result = round(result.gookmin + result.gungang + result.janggi + result.goyoung);

	// cout << "국민연금 : " << result.gookmin << "원" << endl;
	// cout << "건강보험 : " << result.gungang << "원" << endl;
	// cout << "장기요양보험 : " << result.janggi << "원" << endl;
	// cout << "고용보험 : " << result.goyoung << "원" << endl;
	// cout << "4대보험 총 합계 : " << result.all_result << endl;

}



int about_insurance::select2_insurance(void)
{
	insurance insur;
	insurance_24 insur_input;
	int check;

	while (1)
	{
		show_menu_print();

		check =insur_init(insur_input);
		if (check == 1) // 종료값
			return (1);
		insur_caculater(insur, insur_input);
		show_print_all(insur);
		while (1)
		{
			cout << "\n1번 : 재시도, 2번 : 메뉴이동, 3번 : 종료하기" << endl;
			cin >> check;
			if (check == 1) //재시도
				break;
			else if (check == 2) // 메뉴이동
				return (0);
			else if (check == 3)
				return (1);
			else
			{
				cout << "\n잘못 입력하셨습니다. 다시 입력해주세요.\n" << endl;
				continue;
			}
		}
		return (0);
	}
	
}