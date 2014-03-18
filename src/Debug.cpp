/**
 * \file 	Debug.cpp
 * \brief 	Classes/functions to assist with debugging.
 * \author  Chris Jaquet (chris@bytesbynight.com)
 */

#include "Debug.h"

#include <cstdio>

void debugAssertMessage(bool statement, std::string message)
{
	if(!statement)
	{
		std::fprintf(stderr, "ASSERTION FAILED WITH MESSAGE: %s", message.c_str());
		assert(statement);
	}
}





