/*
Program:      Network Topology Recognition Algorithm
Modified by: Edgard Luigi Sanchez
Description:
          //Assignment 2: Topology recognition problem                                   
          // Doina Bein                                                                   
          // Given a network with n>3 nodes and a weight matrix W[0..n−1, 0..n−1] of      
          // positive integers, of a weighted, connected undirected graph modeling        
          // a network, decide whether the network is one of the topologies, if any:      
          // ring, star, fully connected mesh. Note: represent infinity by the value 100.
          // INPUT: a positive integer n and a list of n^2 positive values          
          // OUTPUT: message "ring" or "star" or "complete" or "neither"                  

Date:       3/9/17
*/



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

int main() 
{
  int n, i, j, count, center;
  int W[100][100];
  bool cond;

  // display the header                                                         
  cout << endl << "CPSC 335- Luigi Sanchez - Programming Assignment #2" << endl;
  cout << "Topology recognition algorithm" << endl;
  cout << "Enter the number of nodes in the topology" << endl;
  // read the number of nodes                                                   
  cin >> n;
  // read the weight matrix                                                     
  cout << "Enter the positive weights, 100 for infinity" << endl;
  for(i=0; i < n; i++)
   for(j=0; j < n; j++)
      cin >> W[i][j];

  // Start the chronograph to time the execution of the algorithm               
  auto start = chrono::high_resolution_clock::now();

  cout <<"The topology is"<< endl;
  cond = true; 
  count = 0;
  // loop to check whether the topology is a ring                               
  for (i=0;  i < n ; i++) 
  {
      for(j=0; j < n; j++)
      {
        if(W[i][j] != 100 && W[i][j] != 0)
          count++;
      }

      if(count != 2)
      {
        cond = false;
        break;
      }
          count = 0;
  }

  if (cond) {
    cout <<"ring" << endl;
    return EXIT_SUCCESS;
  }

  count = 0;
  cond = true;
  center = 0;
  // loop to check whether the topology is a star                               
  for (i=0;  i < n; i++) 
  {
    for(j=0; j < n; j++)  
    {
      if(W[i][j] != 100 && W[i][j] != 0)
        count++;
    }

    if(count == (n-1))
        center++;

    if(count > 1 && count != (n-1))
    {
      cond = false;
      break;      
    }  
    
    count = 0;
  }

  if (cond && (center == 1)) {
    cout <<"star" << endl;
    return EXIT_SUCCESS;
  }

  cond = true;
  count = 0;  
  // loop to check whether the topology is a fully connected mesh               
  for (i=0;  i < n ; i++) 
  {
    for(j=0; j < n; j++)
    {
       if(W[i][j] != 100 && W[i][j] != 0)
        count++;
    }

    if(count != (n-1))
    {
      cond = false;
      break;
    }
    count = 0;
  }

  if (cond)
    cout << "fully connected mesh" << endl;
  else
   cout << "neither" << endl;

  // End the chronograph to time the loop                                       
  auto end = chrono::high_resolution_clock::now();

  // Print the elapsed time in seconds and fractions of seconds
  // Displaying the output is NOT part of the algorithm so the timer ends before displaying the output                                                                                                                                       
  int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
  double seconds = microseconds / 1E6;
  cout << "elapsed time: " << seconds << " seconds" << endl;
  cout << "elapsed time: " << microseconds << " microseconds" << endl;
  return EXIT_SUCCESS;
}


