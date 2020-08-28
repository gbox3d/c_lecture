#include <Python.h>
#include <stdio.h>

static PyObject *hello()
{
  puts("hello py module in c");
  return Py_BuildValue("");
}

static struct PyMethodDef _sample_methods[] =
{
  {"hello",hello,METH_NOARGS,NULL},
  {NULL}  
};

static struct PyModuleDef _sample_module = {
  PyModuleDef_HEAD_INIT,
  "_ex02",
  "this is sample C module",
  -1,
  _sample_methods
};

PyMODINIT_FUNC PyInit__ex02(void)
{
  PyObject *m;
  m = PyModule_Create(&_sample_module);
  return m;
}


