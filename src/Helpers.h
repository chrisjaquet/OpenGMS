/**
 * \file        Helpers.h
 * \brief       Contains useful helper macroes and functions
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        05 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
#ifndef HELPERS_H_
#define HELPERS_H_

// Macros //////////////////////////////////////////////////////////////////////////////////////////

/**
 * \def CGET(type, name)
 * \brief   Macro for creating a simple getter of the given type with the given name for retrieving
 *          the variable _name.
 * \param type  The type of the variable being retrieved.
 * \param name  The name to use when generating the getter. The variable being returned is _name.
 */
#define CGET(type, name) inline type name(void) { return _##name; }

/**
 * \def CSET(type, name)
 * \brief   Macro for creating a simple setter of the given type with the given name for setting the
 *          variable _name.
 * \param type  The type of the variable being set.
 * \param name  The name to use when generating the setter. The variable being set is _name.
 */
#define CSET(type, name) inline void name(type new##name) { _##name = new##name; }

/**
 * \def CGETSET(type, name)
 * \brief   Macro for creating a simple getter and setter of the given type with the given name for
 *          retrieving/setting the variable _name. This macro makes use of CGET and CSET.
 *
 * \param type  The type of the variable.
 * \param name  The name to use when generating the getter/setter. The variable being retrieved or
 *              set is _name.
 */
#define CGETSET(type, name) CGET(type, name) \
                CSET(type, name)

#endif /* HELPERS_H_ */
