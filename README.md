gnuplott
========

A simple C++ class that collects data points (of a mathematical function) and uses gnuplot to plot them.


This is a small project, that I wrote to be able to plot (simple) functions from C++ programs.
Since at that time there were no means to plot functions with only c++, I decided to use gnuplot.
There are libraries which allow to control gnuplot from c++ code but I wasn't used to gnuplot commands
and only wanted a simple way to plot simple functions.

The file "gnuplott.h" is the header file for my class "gnuplott" and contains the declarations of the 
functions. The file "gnuplott.cpp" contains the definitions (code).

And in "gnuplottmain.cpp" there is a small example code which uses the "gnuplott" class.
To compile it you have to give the compiler both the gnuplottmain.cpp and gnuplott.cpp files:

g++ gunplottmain.cpp gnuplott.cpp
