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
    //outfile << "plot \"-\" with lines" << endl;

    for (int j = steps[i]; j < (steps[i+1] - 1); j++)
      outfile << xvals[j] << " " << yvals[j] << endl;

    outfile.close(); // close and clear file in order to use the name 
    outfile.clear(); // later in the code (several loops)

  }  // end of for (int i = 0; i < ( steps.size() -1 ); i++){

  plotting.erase(5,1); // erase the first "," in "plot ,gnu101.txt with lines, .."

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




/* // begin of old definition
gnuplott::gnuplott(){
  axisIsSet = false;
}

gnuplott::gnuplott(vector<double> axis){
  storage_.push_back(axis);
  axisIsSet = true;
}

void
gnuplott::setaxis(vector<double> axis){
  if (storage_.size() == 0){
    storage_.push_back(axis);
    axisIsSet = true;
  }
  else
    cerr << "Error: an axis is already set!" << endl;
}


void
gnuplott::addfunction(vector<double> vec){
  if (axisIsSet)
    storage_.push_back(vec);
  else 
    cerr << "Error: No axis set. Please set "
            "axis before adding values!" << endl;
}


void
gnuplott::plot(){
  ofstream outfile;
  outfile.open("gnuplott_output.txt"); // standard output file
  
  outfile << "plot ";
  for (int i = 2; i <= storage_.size(); i++)
    outfile << "\"-\" using 1:" << i << " with lines,\\" << endl;
  
  outfile << endl;

  for (int i = 0; i < storage_[0].size(); i++){
    for (int j = 0; j < storage_.size(); j++){
      outfile << storage_[j][i] << " " ;
    }
    outfile << endl;
  }

  outfile.close();
  outfile.clear();

  system("gnuplot gnuplott_output.txt");

}
  
*/ // end of old definiton


/*
void
gnuplott::plot(){
  ofstream outfile;
  outfile.open("gnuplott_output.txt"); // standard output file
  
  outfile << "plot \"-\" with lines" << endl;

  for (int i = 0; i < valsx_.size(); i++)
    outfile << valsx_[i] << " " << valsy_[i] << endl;

  outfile.close(); // close file
  outfile.clear();
  
  system("gnuplot gnuplott_output.txt");
}
*/
