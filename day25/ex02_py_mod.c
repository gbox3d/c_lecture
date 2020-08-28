#include <Python.h>
#include <stdio.h>
// #include <SDL.h>

static PyObject *hello()
{
  puts("hello py module in c");
  return Py_BuildValue("");
}

static PyObject *c_add(PyObject *self,PyObject *args)
{
  int a,b,r;
  if(!PyArg_ParseTuple(args,"ii",&a,&b)) //파이썬에서 받은 데이터 언패킹 
    return NULL;
  
  r = a+b;
  return Py_BuildValue("i",r); //패킹해서 파이썬쪽으로 넘겨주기 
}

// static PyObject *sdlTest()
// {
//   if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
//   {
//     printf("error initializing SDL: %s\n", SDL_GetError());    
//   }
//   else {
//     printf("sdl init ok!");    
//   }
//   return Py_BuildValue("");
// }

static PyObject *c_sub(PyObject *self,PyObject *args)
{
  int a,b,r;
  if(!PyArg_ParseTuple(args,"ii",&a,&b)) //파이썬에서 받은 데이터 언패킹 
    return NULL;
  
  r = a-b;
  return Py_BuildValue("i",r); //패킹해서 파이썬쪽으로 넘겨주기 
}

static struct PyMethodDef _sample_methods[] =
{
  {"hello",hello,METH_NOARGS,NULL},
  {"c_add",c_add,METH_VARARGS,NULL},
  {"c_sub",c_sub,METH_VARARGS,NULL},
  // {"sdlTest",sdlTest,METH_NOARGS,NULL},
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


