// gnuplottmain.cpp

#include <iostream>
#include <vector>
#include <cmath>


#include "gnuplott.h"

using namespace std;

double func1(double a){
  return (pow(a,3) - 2 * pow(a,2));
}

double func2(double a){
  return log(a);
}

double func3(double a){
  return cos(a);
}



int main(){

  gnuplott plt; // you create a gnuplott object, 
                // which collects all data to be plotted


  // you add a Data point ( x, y ) by using the method addPoint(double x, double y)
  // here I just use a loop to add data points for the first function
  for (int i = -8; i < 30; i++)
    plt.addPoint( static_cast<double>(i)/10, func1(static_cast<double>(i)/10) );

  plt.endoffunction();
  // in order to distinguish the different functions you have to tell the gnuplott
  // object, that the data points of a function are complete. 
  // every data point added, will be seen as a point of the next function
  // IT IS VITAL, THAT YOU FINISH EVERY FUNCTION WITH THIS METHOD, EVEN IF THERE
  // IS ONLY ONE!!

  // and the same game for the next two functions. As you will see, the functions
  // do not have to be defined on the same interval.
  for (int i = 1; i < 50; i++)
    plt.addPoint( static_cast<double>(i)/10, func2(static_cast<double>(i)/10) );

  plt.endoffunction();


  for (int i = -50; i < 50; i++)
    plt.addPoint( static_cast<double>(i)/10, func3(static_cast<double>(i)/10) );

  plt.endoffunction();


  for (int i = -40; i < 60; i++)
    plt.addPoint( static_cast<double>(i)/10, sin(static_cast<double>(i)/10) );

  plt.endoffunction();



  plt.plot();
  // now, to plot just use the plot() method. Then the gnuplot object 
  // plots everything, which it has stored

}

  // please ignore the following code, it is an old version, which i am too 
  // lazy to erase
  /*
  { // begin code-block
    vector<double> xvals;
    for (int i = -50; i < 50; i++){ // set the x-axis-vector
      xvals.push_back( (static_cast<double>(i)/10) );
    }
    
    plt.setaxis(xvals);

    vector<double> yvals;

    // use yvals to compute function values for first function:
     for (int i = 0; i < xvals.size(); i++){
      yvals.push_back( vfunction1(xvals[i]) );
    }

    plt.addfunction(yvals);

    // use yvals again to compute function values for second function:
    yvals.clear(); // erase previous values
    
    for (int i = 0; i < xvals.size(); i++){
      yvals.push_back( vfunction2(xvals[i]) );
    }

    plt.addfunction(yvals);
    
  } // end code-block
  */




