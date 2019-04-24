using namespace std;
#include <iostream>
#include <limits>
#include "Functions.h"
#include <fstream>
#include <string>


int  main()
{
	 int algonumber;
	 string inputFile;
	 string outputFile;
	 string runningTimeFile;

	 cin>>algonumber;
	 cin>>inputFile;
	 cin>>outputFile;
	 cin>>runningTimeFile;
  
///////////////////////////////////
// Reading the data from the input file

  int size=0;
  int x;
  int i=0;
  int*arr=NULL;
  ifstream myfile (inputFile,ios::in);
  // calcullate the size of the array
  if (myfile.is_open())
	{ 
		while (true)
		{
			int x;
			myfile >> x;
			size++;
			if (myfile.eof())
				break;
		}
	
   arr =new int[size-1];
  int ii=0; 
  //read from the file and save in the array 
  myfile.clear();
  myfile.seekg(0, ios::beg);
        while (true)
		{
			int x;
			myfile >> x;
			arr[ii] = x;
			ii++;
			if (myfile.eof())
				break;
			
		}
		
  }
  myfile.close();
 
  //////////////////////////////
  //////////////////////////////

  // check if the array is sorted or not
  string checkSorting;
  int j=0;
  checkSorting = "sorted";
  for(int i=0;i<size-1;i++)
  	{
  		if(arr[i+1]>=arr[i]){j++;}
  	    else{
			checkSorting = "Unsorted";
			break;
		}
  	}
 
  	
  

  	////////////////////////////////////
  	///////////////////////////////////
  float timeOfRun;
  timeOfRun=sortmain(arr,size,algonumber);

  /////////////////////////////
  /////////////////////////////
  // Print the sorted data to the file 

   ofstream myfile1 (outputFile,ios::out);
  if (myfile1.is_open())
  {
  	for(int i=0;i<size-1;i++)
   { 
   	myfile1 << arr[i] << endl ;
   }
   myfile1.close();
  }
  else cout << "Unable to open file";
  
////////////////////////
  /////////////////////
  //write the running time to the file

   ofstream myfile2 (runningTimeFile,ios::app);
  if (myfile2.is_open())
  {
    myfile2 << size << "_" << checkSorting << ":" << timeOfRun << endl;
    myfile2.close();
  }
  else cout << "Unable to open file";

  ///////////////////////////
  //////////////////////////
  return 0;
}