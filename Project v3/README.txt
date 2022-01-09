Signal Management-Javier Galindos
This project uses a library that needs python to compile. You have to follow the following steps:
https://matplotlib-cpp.readthedocs.io/en/latest/compiling.html
It is recommendable compiling and executing in macOs or Linux.

For Unix Users:
1. Install python
2. Install matplolib: (copy this in Terminal) 
	pip3 install matplotlib.
3. Go to the folder of the project
4. Write within the Terminal:
	make
5. Write within the Terminal:
	./Project


Whether you want to use Xcode:
Include theflags within:
Build Settings->
Add the flags in both Other C++ Flags and Other Liker flags
You have to check whether the path are the same and change it if they are different:
 -I /Library/Frameworks/Python.framework/Versions/3.9/include/python3.9 \
 -I /Library/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/numpy/core/include \
 -L /Library/Frameworks/Python.framework/Versions/3.9/lib \
 -lpython3.9 

For Windows:
You will need:
_Windows 10 
_Python
_CMake
_Visual Studio

Steps:
1.install python and matplotlib .. don't forget to add python folder it to your PATH.

2.add matplotlibcpp.hpp to your project include folder.

3.on you cmake list file add this.

find_package(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES( ${PYTHON_INCLUDE_DIRS} )
link_directories( ${PYTHON_LIBRARIES})
target_link_libraries( targetname ${PYTHON_LIBRARY})

4. Compile the whole project.
