from distutils.core import setup, Extension

setup(name="_ex02",
      version="1.0",
      description="hello method sample",
      author="gbox3d",
      author_email="gbox3d@gmail.com",
      url="http://gbox3d.blogspot.com",
      ext_modules=[Extension("_ex02",["ex02_py_mod.c"])]

      )
