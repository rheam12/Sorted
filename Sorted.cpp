//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// #defines, enum, and function declarations; do not remove
//

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
#define NaN std::numeric_limits<float>::quiet_NaN() // (comes from <limits>)

enum sortType { ASCENDING, DESCENDING, UNKNOWN, UNSORTED };

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort);
bool sorted(const float data[]);

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort) {
	if(data[currentDataItem]!=data[currentDataItem]&&typeOfSort!=UNSORTED)
		  return true;

  switch(typeOfSort){
	 case UNKNOWN:
	  if(data[currentDataItem-1]<data[currentDataItem])
		  return isSorted(data,currentDataItem+1,ASCENDING);
	  if(data[currentDataItem-1]>data[currentDataItem])
		  return isSorted(data,currentDataItem+1,DESCENDING);
	  else
		 return isSorted(data,currentDataItem+1,UNKNOWN); 
	case ASCENDING:
	  if(data[currentDataItem-1]<=data[currentDataItem])
		  return isSorted(data,currentDataItem+1,ASCENDING);
		else
			return isSorted(data,currentDataItem+1,UNSORTED);
	case DESCENDING:
		if(data[currentDataItem-1]>=data[currentDataItem])
		  return isSorted(data,currentDataItem+1,DESCENDING);
		else
			return isSorted(data,currentDataItem+1,UNSORTED);
	case UNSORTED:
		return 0;
}
}

bool sorted(const float data[]) {
 int currentDataItem=1;
 bool check;
check= isSorted(data,currentDataItem,UNKNOWN);
 return check;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  float data[] = {123.2, 30.4, 409.23, NaN};

  if (sorted(data))
    cout << "Data is sorted" << endl;
  else
    cout << "Data is not sorted" << endl;
  
  return 0;
}

#endif

