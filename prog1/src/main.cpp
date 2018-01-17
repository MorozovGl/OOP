#include "IniParser/IniParser.h"

int main() {
	try {
    IniParser p("../input_files/lab01_input_correct_01.ini");
		p.PrintAll();
		std::cout << p.GetValue<std::string>("SECTION", "MaxWaitTimeMs");
		std::cout << p.GetValue<int>("SECTION", "RawCacheMaxGapMs") << std::endl;
	}	
	catch (std::exception& e) {
		std::cerr << e.what(); 
	}
    return 0;
}

