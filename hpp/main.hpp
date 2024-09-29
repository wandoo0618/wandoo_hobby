#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <thread>  // sleep_for 사용을 위한 라이브러리
# include <chrono>  // 시간 단위를 위한 라이브러리

# include "insurance.hpp"

const char win[] = "cls";
const char mac[] = "clear";

//24년도 4대보험 요율
const double gookmin_per = 0.045; //국민연금
const double gungang_per = 0.03545; //건강보험
const double janggi_per = 0.1295; // 장기요양보험
const double goyoung_per = 0.009; // 고용보험

class about_insurance;

class about_main
{
	public:
		enum
		{
			exit,
			select1,
			select2,
			end,
		};
		int select;

		about_insurance *insurance;

		about_main();
		~about_main();	

};

void clear_all(void);
int tester(void);

#endif