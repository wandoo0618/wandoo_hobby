#include "../hpp/main.hpp"
#include "../hpp/insurance.hpp"
using namespace std;

int tester(void)
{

	double netSalary; // 실수령액 (세후 금액)

	std::cout << "실수령액(세후 금액)을 입력하세요 (원): ";
	std::cin >> netSalary;

	// 초기 세전 급여 추정값 설정
	double grossSalary = netSalary / 0.8; // 일반적으로 세후 금액은 세전 금액의 약 80%로 가정

	double calculatedNetSalary = 0.0;
	double prevGrossSalary = 0.0;
	double epsilon = 1.0; // 허용 오차 (1원)

	// 반복문을 통해 세전 급여를 추정
	while (std::abs(grossSalary - prevGrossSalary) > epsilon)
	{
		prevGrossSalary = grossSalary;

		// 4대 보험료 계산
		double nationalPension = grossSalary * 0.045;			 // 국민연금
		double healthInsurance = grossSalary * 0.03545;			 // 건강보험
		double longTermCareInsurance = healthInsurance * 0.1295; // 노인장기요양보험
		double employmentInsurance = grossSalary * 0.009;		 // 고용보험

		double totalInsurance = nationalPension + healthInsurance + longTermCareInsurance + employmentInsurance;

		// 소득세 및 지방소득세는 총 급여에서 4대 보험료를 공제한 금액의 약 3%로 가정
		// double taxableIncome = grossSalary - totalInsurance;
		// double incomeTax = taxableIncome * 0.03;

		// 총 공제액 계산
		double totalDeduction = totalInsurance;
		// double totalDeduction = totalInsurance + incomeTax;

		// 계산된 실수령액
		calculatedNetSalary = grossSalary - totalDeduction;

		// 실수령액과 입력된 금액의 차이 계산
		double difference = netSalary - calculatedNetSalary;

		// 차이에 따라 세전 급여 조정
		grossSalary += difference;
	}

	std::cout << std::fixed << std::setprecision(0);
	std::cout << "\n추정 세전 금액: " << grossSalary << "원\n";
	this_thread::sleep_for(chrono::milliseconds(10000));
	return 0;
}
