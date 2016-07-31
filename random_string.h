#pragma once
#include <cstdlib>
#include <string>

 std::string random_string(const int len) {
	 static const char alphanum[] =
		 //"0123456789"
		// "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		 "abcdefghijklmnopqrstuvwxyz";// !\"£$%^&*(){}[]:@~;'#|\\¬<>,.?/-=_+";

	std::string s;
	for (int i = 0; i < len; ++i) {
		s.append(1, alphanum[rand() % (sizeof(alphanum) - 1)]);
	}

	return s;
}