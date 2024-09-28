#ifndef INSURANCE_HPP
# define INSURANCE_HPP

class about_insurance
{
	public:

		enum
		{
			ex,
			select1,
			select2,
			select3,
		};
		struct insurance
		{
			double gookmin;
			double gungang;
			double janggi;
			double goyoung;
			int all_result;
		};
		
		struct insurance_24
		{
			double gookmin_24;
			double gungang_24;
			double janggi_24;
			double goyoung_24;
		};


		int insurance_main(void);

	private:
		int select_insurance;
		int all_money;
		int select1_insurance(void);
		void caculater(insurance_24 &i, insurance &result);
		void show_print_all(insurance &insur);

};


#endif