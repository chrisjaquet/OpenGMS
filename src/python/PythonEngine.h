/**
 * \file        PythonEngine.h
 * \brief       Contains the definition of the \c PythonEngine class used to wrap the python
 *              interpreter so that it may be used as a semi-interactive interpreter.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        23 Jun 2012
 * \note        Copyright (c) 2012 Chris Jaquet
 * TODO:        1. Capture StdIO
 * TODO:        2. Keep local and global contexts safe
 **************************************************************************************************/
#ifndef PYTHONENGINE_H_
#define PYTHONENGINE_H_

// Python Header (must be first) ///////////////////////////////////////////////////////////////////
#include <Python.h>

// Local Headers ///////////////////////////////////////////////////////////////////////////////////

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <string>

// Class Definition ////////////////////////////////////////////////////////////////////////////////

/**
 * \class   PythonEngine
 * \brief   A means for wrapping the python interpreter so that we can use it as a semi-interactive
 *          interpreter. The goal is thus to encapsulate all the necessary information for a
 *          specific instance of the interpreter. Note that this is a singleton class since many
 *          aspects of the python interpreter are not thread-safe.
 */
class PythonEngine
{
    private:
        PyObject *_globals; ///< The global context information.
        PyObject *_locals; ///< The local context information.

        static PythonEngine *_instance; ///< Singleton instance of the class.

        // private members
        PythonEngine(); // Made private for singleton class implementation.
    public:
        virtual ~PythonEngine();

        /**
         * \name Getters and Setters
         */
        //\{
        inline PyObject *globals(void) { return _globals; } ///< Returns the python object containing the global context information. (Does not increment reference count.)
        inline PyObject *locals(void) { return _locals; } ///< Returns the python object containing the local context information. (Does not increment reference count.)
        //\}

        /**
         * \name Initialization and Finalization Commands
         */
        //\{
        void finalize();
        void initialize();
        bool isInitialized();
        void reinitialize();
        //\}

        /**
         * \name Code execution commands
         */
        //\{
        bool executeCode(std::string &theCode);
        string getLastError(void);
        string getLastOutput(void);
        //\}

        /**
         * \name StdIO ( \c stdout and \c stderr) Management
         */
        //\{
        bool redirectStdErr();
        //\}

        static inline PythonEngine *instance(void) { if(_instance == NULL) _instance = new PythonEngine; return _instance; } ///< The singleton instance method. There can be only one instance of the PythonEngine class and this is the only way to create it or get hold of the existing instance.

};

#endif /* PYTHONENGINE_H_ */
