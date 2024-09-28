#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>

# include "insurance.hpp"

class about_insurance;

class about_main
{
	public:
		enum
		{
			select1,
			select2,
			end,
		};
		int select;

		about_insurance *insurance;


		about_main();
		~about_main();	

};



#endif