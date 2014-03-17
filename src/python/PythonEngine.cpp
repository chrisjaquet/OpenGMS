/**
 * \file        PythonEngine.cpp
 * \brief       Contains the definition of the \c PythonEngine class used to wrap the python
 *              interpreter so that it may be used as a semi-interactive interpreter.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        23 Jun 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/

// Python Header (must be first) ///////////////////////////////////////////////////////////////////
#include <Python.h>

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "PythonEngine.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////

// Class Static Variables //////////////////////////////////////////////////////////////////////////
PythonEngine *PythonEngine::_instance = NULL;


// Class Implementation ////////////////////////////////////////////////////////////////////////////

/**
 * Default constructor
 */
PythonEngine::~PythonEngine()
{
}

/**
 * Destructor
 */
PythonEngine::PythonEngine()
{
}

