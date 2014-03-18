/**
 * \file 	Debug.h
 * \brief 	Classes/functions to assist with debugging.
 * \author  Chris Jaquet (chris@bytesbynight.com)
 */
#ifndef DEBUG_H_
#define DEBUG_H_

#include <cassert>
#include <string>

void debugAssertMessage(bool statement, std::string message);

#ifdef DEBUG
#	define DEBUG_ASSERT(statement) 				assert(statement)
#	define DEBUG_ASSERT_MSG(statement, message) debugAssertMessage((statement), message)
#else
#   define DEBUG_ASSERT(x)
#	define DEBUG_ASSERT_MSG(statement, message)
#endif




#endif /* DEBUG_H_ */
