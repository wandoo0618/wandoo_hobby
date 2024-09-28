#include "../hpp/main.hpp"
#include "../hpp/insurance.hpp"
using namespace std;

static void show_menu_print(void)
{
	clear_all();
	cout << "[[[4대보험 요율 직접적용 모드입니다.]]]" << endl;
}

void about_insurance::insur_init(insurance_24 &i)
{
	clear_all();
	cout << "\n\n 고용보험 요율을 입력해주세요." << endl;
	cin >> i.gookmin_24;
	cout << "입력 국민연금 요율 : " << i.gookmin_24 << "%" << endl;
	
	cout << "\n\n 건강보험 요율을 입력해주세요" << endl;
	cin >> i.gungang_24;
	cout << "입력 건강보험 요율 : " << i.gungang_24 << "%" << endl;
	
	cout << "\n\n 장기요양보험 요율을 입력해주세요" << endl;
	cin >> i.janggi_24;
	cout << "입력 장기요양보험 요율 : " << i.janggi_24 << "%" << endl;

	cout << "\n\n 고용보험 요율을 입력해주세요" << endl;
	cin >> i.goyoung_24;
	cout << "입력 고용보험 요율 : " << i.goyoung_24 << "%" << endl;
	
	cout << "입력된 4대보험 요율" << endl;
	cout << "국민연금 : " << i.gookmin_24 << "%" << endl;
	cout << "건강보험 : " << i.gungang_24 << "%" << endl;
	cout << "장기요양보험 : " << i.janggi_24 << "%" << endl;
	cout << "고용보험 : " << i.goyoung_24 << "%" << endl;
	
	i.gookmin_24 /= 100;
	i.gungang_24 /= 100;
	i.janggi_24 /= 100;
	i.goyoung_24 /= 100;
}

void about_insurance::insur_caculater(insurance &result, insurance_24 &i)
{
	clear_all();
	cout << "수입을 입력해주세요." << endl;
	cin >> all_money;
	
	result.gookmin = (double)all_money * i.gookmin_24;
	result.gungang = (double)all_money * i.gungang_24;
	result.janggi = (double)result.gungang * i.janggi_24;
	result.goyoung = (double)all_money * i.goyoung_24;
	result.all_result = round(result.gookmin + result.gungang + result.janggi + result.goyoung);

	cout << "국민연금 : " << result.gookmin << "원" << endl;
	cout << "건강보험 : " << result.gungang << "원" << endl;
	cout << "장기요양보험 : " << result.janggi << "원" << endl;
	cout << "고용보험 : " << result.goyoung << "원" << endl;

	cout << "4대보험 총 합계 : " << result.all_result << endl;
}



int about_insurance::select2_insurance(void)
{
	insurance insur;
	insurance_24 insur_input;

	while (1)
	{
		show_menu_print();
		insur_init(insur_input);
		insur_caculater(insur, insur_input);
		show_print_all(insur);
		exit(1);
	}
	
}