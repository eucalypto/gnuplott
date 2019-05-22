// gnuplott.h   The header file for the gnuplott class

// the gnuplott class collects data points and prints them
// using gnuplot, where the data points are connected with lines.
// the using flow is intended to be like this:
// i)   define a gnuplott object.
// ii)  add data points for first function with 
//      addPoint(double x, double y);
// iii) close the collection of data points for first 
//      function with endoffunction();
// iv)  repeat steps ii) and iii) for each function, that
//      you want to plot
//     !! It is vital that you don't forget to close the last 
//     !! function with endoffunction(); 
// v)   at last use the method plot() to plot all the stored data 



#include <iostream>
#include <vector>

// NO using namespace std; otherwise std would be used in every file,
// in which this header is included

class gnuplott{
 public:
  gnuplott();
  
  void addPoint(double, double); // add a data point to current
                                 // function
  
  void endoffunction(); // closes current function, following data
                        // points are added to next function to
                        // plot. The last function has always to be
                        // "ended"

  void plot();  


 private:
  std::vector<double> xvals;
  std::vector<double> yvals;

  std::vector<int> steps;

  // the x-values are stored in xvals. The y-values (function values)
  // are stored in yvals. The functions are stored behind each other
  // in this vectors. steps stores the indices of the last datapoints
  // of a function.

};
