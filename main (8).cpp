
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool insideTriangle(double triTop, double x, double y);

int main()
{
  srand(time(0));
  double triTop = static_cast<double>(rand())/RAND_MAX;
  int numTrials = 20;
  int trialCount = 1;
  double i = 0;
  double k = 0;
  int current = 100;
  double percent = 0;

  cout<<"Trial # | # Points | # in triangle | Estimated Area"<<endl;
  
  
  while(trialCount <= numTrials)
  {
    while(i < current)
    {
      if(insideTriangle(triTop,static_cast<double>(rand())/RAND_MAX,static_cast<double>(rand())/RAND_MAX))
      {
        k++;
      }
      i++;
    }
    //cout<<trialCount<<"       | "<<current<<"      | "<<percent<<"             | "<<(100/percent)<<endl;
    cout<<setw(8)<<trialCount<<'|'<<setw(10)<<current<<'|'<<setw(15)<<k<<'|'<<setw(15)<<(k/current)<<endl;
    i = 0;
    k = 0;
    
    if(trialCount%4 == 0)
    {
      current*=10;
    }
    trialCount ++;
  }

  return 0;
}

bool insideTriangle(double triTop, double x, double y)
{
  int result = true;
  if(x < triTop * y)
  {
    result = false;
  }
  else if(x > 1-(1-triTop)*y)
  {
    result = false;
  }
  return result;
}








