#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "../IniParserException/IniParserException.h"

class IniParser {
public:
	IniParser(const std::string& filename);
	// Processing and saving data
	void Parse();
	// Print
	void PrintAll() const noexcept;
	// Checks if a section exists.
	bool IsHaveSection(const std::string& section_name) const;
	// Checks if a pair param-section exists.
	bool IsHaveParam(const std::string& section_name, const std::string& param_name) const;
	// Return value from data by section and parameter 
	template<typename T>
	T GetValue(const std::string &section_name, const std::string &param_name) const;
	~IniParser();
private:
	// Opens Ini file
	void Initialize(const std::string& filename);
	std::ifstream file;
	std::map <std::string, std::map <std::string, std::string> > data;
};