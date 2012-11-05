/**
 * \file        Logger.h
 * \brief       Functions for logging to stdout.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        05 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
#ifndef LOGGER_H_
#define LOGGER_H_

// Macro Definitions ///////////////////////////////////////////////////////////////////////////////

/**
 * \def LOGP(...)
 * \brief   Log Print -- Prints the given string as with \c printf but prepends the calling
 *          function's name.
 */
#define LOGP(...) printf("[%s] ", __PRETTY_FUNCTION__); printf(__VA_ARGS__)

/**
 * \def LOGPB(...)
 * \brief   Log Print Blind -- Prints the given string as with \c printf.
 */
#define LOGPB(...) printf(__VA_ARGS__)

/**
 * \def LOGPU(...)
 * \brief   Log Print Urgent -- Prints the given string as with \c printf but prepends the calling
 *          function's name and forces a \c fflush of the output stream.
 */
#define LOGPU(...) printf("[%s] ", __PRETTY_FUNCTION__); printf(__VA_ARGS__); fflush(stdout)

/**
 * \def LOGPBU(...)
 * \brief   Log Print Blind Urgent -- Prints the given string as with \c printf and forces a \c
 *          fflush of the output stream.
 */
#define LOGPBU(...) printf(__VA_ARGS__); fflush(stdout)

#endif /* LOGGER_H_ */
