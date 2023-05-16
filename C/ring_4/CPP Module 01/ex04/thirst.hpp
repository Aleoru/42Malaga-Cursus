#ifndef THIRST_HPP
# define THIRST_HPP

# include <iostream>
# include <fstream>

class Thirst{

	public:

		Thirst(std::string file);
		~Thirst(void);
		void	replace(std::string s1, std::string s2);

	private:
		
		std::string	_infile;
		std::string	_outfile;

};


#endif