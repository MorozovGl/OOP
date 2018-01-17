#include "IniParserException.h"

const char* IniParserException::what() const noexcept {
	return message.c_str();
}