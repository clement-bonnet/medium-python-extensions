#include <Python.h>
#include <math.h>

bool _divides(long long div, long long n) {
    return (n % div == 0); 
}

bool _is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    else {
        long long last_div = (long long)floor(sqrt(n));
        for (long long div = 2; div <= last_div; div++) {
            if (_divides(div, n)) {
                return false;
            }
        }
        return true;
    }
}

PyObject *is_prime(PyObject *self, PyObject *n_py) {
    long long n = PyLong_AsLongLong(n_py);
    if (_is_prime(n)) {
        Py_RETURN_TRUE;
    }
    else {
        Py_RETURN_FALSE;
    }
}

static PyMethodDef cpp_methods[] = {
    // The first property is the name exposed to Python, the second is the C++
    // function name that contains the implementation.
    {   "is_prime", is_prime, METH_O,
        "returns true if the given integer is a prime number."},

    // Terminate the array with an object containing nulls.
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef cpp_module = {
    PyModuleDef_HEAD_INIT,
    "cpp",                                                 // Module name to use with Python import statements
    "Provides some functions written in C++ for prime numbers", // Module description
    -1,
    cpp_methods                                           // Structure that defines the methods of the module
};

PyMODINIT_FUNC PyInit_cpp() {
    return PyModule_Create(&cpp_module);

    // return PyModuleDef_Init(&cpp_module);

}