#include "../hpp/main.hpp"
#include "../hpp/insurance.hpp"

using namespace std;
void about_insurance::insurance_main(void)
{
	while(1)
	{
		cout << "원하는 기능을 선택해주세요" << endl;
		cout << "해당 계산기는 근로자용 입니다." << endl;
		cout << "24년 4대보험 요율\n 국민연금 : 4.5%\n 건강보험 : 3.545%\n \
				장기요양보험 : 건강보험의 12.95%\n 고용보험 : 0.9%" << endl;
		cout << "\n\n" << endl;
		cout << "1번, 2024년도 요율적용 계산기" << endl;
		cout << "2번, 각 보험요율 직접입력 전용 계산기" << endl;
		cin >> select_insurance;

		if (select_insurance == select1)
		{
			cout << "2024년도 4대보험요율 계산기입니다.\n\n" << endl;
			cout << "24년 4대보험 요율\n 국민연금 : 4.5%\n 건강보험 : 3.545%\n \
					장기요양보험 : 건강보험의 12.95%\n 고용보험 : 0.9%" << endl;
			cout << "\n\n 세전 총 금액을 입력해주세요" << endl;
			cin >> all_money;
			
		}
	}
}