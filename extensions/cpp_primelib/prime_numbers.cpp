#include <Python.h>


PyObject* prime_factors(PyObject*, PyObject* n) {
    int n = PyInt_AsInt(n);
    double tanh_x = sinh_impl(x) / cosh_impl(x);
    return PyFloat_FromDouble(tanh_x);
}

static PyMethodDef cpp_primelib_methods[] = {
    // The first property is the name exposed to Python, the second is the C++
    // function name that contains the implementation.
    { "prime_factors", (PyCFunction)prime_factors, METH_O, nullptr },

    // Terminate the array with an object containing nulls.
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef superfastcode_module = {
    PyModuleDef_HEAD_INIT,
    "cpp_primelib",                                 // Module name to use with Python import statements
    "Provides some functions for prime numbers",    // Module description
    0,
    cpp_primelib_methods                            // Structure that defines the methods of the module
};

PyMODINIT_FUNC PyInit_cpp_primelib() {
    return PyModule_Create(&cpp_primelib_module);
}