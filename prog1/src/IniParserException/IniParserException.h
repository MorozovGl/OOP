#pragma once
#include <exception>
#include <string>

class IniParserException : public std::exception {
public:
    IniParserException(const std::string &excMessage) : message(excMessage) {}
	virtual const char* what() const noexcept;
    ~IniParserException() noexcept {}
private:
    std::string message;
};
class IO_Exception : public IniParserException {
public:
	IO_Exception(const std::string &filename) : IniParserException("File " + filename + " can't be read.\n") {};
};
class Format_Exception : public IniParserException {
public:
	Format_Exception(const std::string &line) : IniParserException("Format incorrect in line: " + line + '\n') {};
};
class Data_Exception : public IniParserException {
public:
	Data_Exception(const char *data_key_level, const std::string &key_name) : IniParserException(std::string(data_key_level) + '"'+ key_name + '"' + " can`t be found.\n") {};
};
