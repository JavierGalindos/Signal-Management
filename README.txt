g++ main.cpp -std=c++14 \
 -I /Library/Frameworks/Python.framework/Versions/3.9/include/python3.9 \
 -I /Library/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/numpy/core/include \
 -L /Library/Frameworks/Python.framework/Versions/3.9/lib \
 -lpython3.9

Not necessary:
-I /Library/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/numpy/core/include \ 
If -DWITHOUT_NUMPY

In Xcode:
Build Settings->
Add the flags in both Other C++ Flags and Other Liker flags

g++ main.cpp -std=c++17 \
 -I /Library/Frameworks/Python.framework/Versions/3.9/include/python3.9 \
 -I /Library/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/numpy/core/include \
 -L /Library/Frameworks/Python.framework/Versions/3.9/lib \
 -lpython3.9 



g++ -o main main.cpp FileManagement.cpp SquareWave.cpp UI.cpp -std=c++11 \
 -I /Library/Frameworks/Python.framework/Versions/3.9/include/python3.9 \
 -I /Library/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/numpy/core/include \
 -L /Library/Frameworks/Python.framework/Versions/3.9/lib \
 -lpython3.9 


Windows:
1.install python and matplotlib .. don't forget to add python folder it to your PATH.

2.add matplotlibcpp.hpp to your project include folder.

3.on you cmake list file add this.

find_package(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES( ${PYTHON_INCLUDE_DIRS} )
link_directories( ${PYTHON_LIBRARIES})
target_link_libraries( targetname ${PYTHON_LIBRARY})