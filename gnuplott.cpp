// gnuplott.cpp definiton file for gnuplott class

#include "gnuplott.h"

#include <iostream>
#include <vector>
#include <fstream> // for file input/output
#include <cstdlib> // for system("command"); to run a command in shell

#include <sstream> // for conversion of int, float, .. to string

using namespace std;


gnuplott::gnuplott(){
  steps.push_back(0);
}


void
gnuplott::addPoint(double xval, double yval){
  xvals.push_back(xval);
  yvals.push_back(yval);
}

void
gnuplott::endoffunction(){
  steps.push_back( xvals.size() );
}

void
gnuplott::plot(){
  ofstream outfile;
  string plotting("plot ");
  
  // i induces the functions, 0th function, 1st function, ... 
  for (int i = 0; i < ( steps.size() - 1 ); i++){
    // output files are named: gnu100.txt, gnu101.txt, gnu102.txt,
    // for function            Nr. 0       Nr. 1       Nr. 2
    string outfilestring("gnu");
    // conversion of integer i to string
    stringstream out;
    out << (100+i);
    outfilestring.append( out.str() );
    outfilestring.append(".txt");
    
    plotting.append(", \"");
    plotting.append(outfilestring);
    plotting.append("\" with lines ");
    
    outfile.open( outfilestring.c_str() ); // open output file


    for (int j = steps[i]; j < (steps[i+1] - 1); j++)
      outfile << xvals[j] << " " << yvals[j] << endl;

    outfile.close(); // close and clear file in order to use the name 
    outfile.clear(); // later in the code (several loops)

  }  // end of for (int i = 0; i < ( steps.size() -1 ); i++){

  plotting.erase(5,1); // erase the first "," in "plot ,gnu101.txt with
                       // lines, .."

  outfile.open("plotting.txt");
  outfile << plotting ;
  outfile.close();
  outfile.clear();
  

  system("gnuplot -persist plotting.txt");
  cout << "If you see nothing:" << endl
       << "As Linux-User please install gnuplot" << endl
       << "And as Windows-User please install gnuplot and "
       << "run it with plotting.txt as input file" << endl;
}

