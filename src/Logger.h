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

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

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

// TODO: The name needs work
/**
 * \class CLogContext
 * \brief Class that automatically updates the current logging context in the constructor and restores it in the
 * 		  destructor.
 *
 * THIS CLASS IS NOT THREAD SAFE!
 */
class CLogContext
{
	public:
		// TODO: Expand this to include the class or module name as well.
		CLogContext(const char *pFunctionName)
		{
			m_stackID = CAutoLogger::GetInstance()->EnterContext(pFunctionName);
		}
		~CLogContext()
		{
			CAutoLogger::GetInstance()->LeaveContext(m_stackID);
		}
	private:
		int m_stackID;
};

class CAutoLogger
{
	friend class CLogContext;
	public:
		static CAutoLogger *GetInstance()
		{
			if(!sm_instance)
			{
				sm_instance = new CAutoLogger();
			}
			return sm_instance;
		}

		CAutoLogger() {}
		~CAutoLogger() {}

		void LogMessage(std::string& message) const
		{
			int indentCount = m_callStack.size() - 1;
			std::string indentString;
			while(indentCount)
			{
				indentString += " ";
				indentCount--;
			}

			char *szLastToken = strtok(message, "\n");
			const char *szFunctionName = m_callStack.last();
			while(szLastToken)
			{
				printf("%s[%s] %s", indentString.const_data(), szFunctionName, szLastToken);
			}
		}

		void PrintCallStack(bool lastCallFirst = true)
		{
			int stackDepth = m_callStack.count();
			for(int i=0; i<stackDepth; i++)
			{
				if(lastCallFirst)
				{
					int index = stackDepth-i;
					printf("[%03d] %s", index, m_callStack[index]);
				}
				else
				{
					printf("[%03d] %s", i+1, m_callStack[i]);
				}
			}
		}

	private:
		int EnterContext(const char *pFunctionName)
		{
			m_callStack.push_back(pFunctionName);

			return m_callStack.size() - 1;
		}

		void LeaveContext(int stackID)
		{
			m_callStack.remove(stackID);
		}

		static CAutoLogger *sm_instance;

		std::vector<const char*> m_callStack;
};

#endif /* LOGGER_H_ */
