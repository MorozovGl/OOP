#include "IniParser.h"
#include "../IniParserException/IniParserException.h"

IniParser::IniParser(const std::string& filename) {
    Initialize(filename);
    Parse();
}
IniParser::~IniParser() {
	data.clear();
	file.close();
}
void IniParser::Initialize(const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        throw IO_Exception(filename);
    }
}
void IniParser::Parse() {
    std::string s;
    std::string section_name, param_key, param_value;
    size_t len, foundSemiColon, foundDelim;
    while (std::getline(file, s)) {
        foundSemiColon = s.find(';');
        if (foundSemiColon != std::string::npos) {
            s = s.substr(0, foundSemiColon);
        }
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        if (!s.empty()) {
            len = s.length();
            if (s[0]=='[' && s[s.length()-1]==']') {
                section_name = s.substr(1, len-2);
            }
            else {
                foundDelim = s.find('=');
                if (foundDelim == std::string::npos) {
					throw Format_Exception(s);
                }
				param_key = s.substr(0, foundDelim);
				param_value = s.substr(foundDelim + 1, len - foundDelim);
                data[section_name].insert(make_pair(param_key, param_value));
            }
        }
    }
}
void IniParser::PrintAll() const noexcept {
	std::map<std::string, std::map<std::string, std::string> >::const_iterator it;
	std::map<std::string, std::string>::const_iterator init;
	for (it = data.begin(); it != data.end(); it++) {
		std::cout << it->first << std::endl;
		for (init = (it->second).begin(); init != (it->second).end(); init++) {
			std::cout << init->first << '=' << init->second << std::endl;
		}
	}
};
bool IniParser::IsHaveSection(const std::string& section_name) const {
	if (data.find(section_name) == data.end()) {
		throw Data_Exception("Section ", section_name);
	}
	return true;
};
bool IniParser::IsHaveParam(const std::string& section_name, const std::string& param_name) const {
	IsHaveSection(section_name);
	if (data.at(section_name).find(param_name) == data.at(section_name).end()) {
		throw Data_Exception("Parameter ", param_name);
	}
	return true;
};
template<>
int IniParser::GetValue<int>(const std::string &section_name, const std::string &param_name) const {
	IsHaveParam(section_name, param_name);
	std::string x = data.find(section_name)->second.find(param_name)->second;
	try {
		return std::stoi(x);
	}
	catch (const std::invalid_argument&) {
		std::cerr << "Argument is invalid\n";
		throw;
	}
	catch (const std::out_of_range&) {
		std::cerr << "Argument is out of range for a integer\n";
		throw;
	}
}
template<>
double IniParser::GetValue<double>(const std::string &section_name, const std::string &param_name) const {
	IsHaveParam(section_name, param_name);
	std::string x = data.find(section_name)->second.find(param_name)->second;
	try {
		return std::stod(x);
	}
	catch (const std::invalid_argument&) {
		std::cerr << "Argument is invalid\n";
		throw;
	}
	catch (const std::out_of_range&) {
		std::cerr << "Argument is out of range for a integer\n";
		throw;
	}
}
template<>
std::string IniParser::GetValue<std::string>(const std::string &section_name, const std::string &param_name) const {
	IsHaveParam(section_name, param_name);
	return data.find(section_name)->second.find(param_name)->second + '\n';
}