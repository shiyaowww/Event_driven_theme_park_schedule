#include <iostream>

using namespace std;

bool customerWaiting(int ary[]);

int loadCar(int numInLine[], int numBoard[]);

int main()
{
  bool ret = false;
  int ary[3] = {0,0,0};
  ret = customerWaiting(ary);
  cout << "expect 0 " << ret << endl;

  int i = 0;
  int ret2 = 0;
  int aryIn[3] = {2,1,14};
  int aryOut[3] = {0,0,0};
  ret2 = loadCar(aryIn, aryOut);
  cout << "rate filled, expect 85: " << ret2 << endl;
  cout << "aryOut, expect 2 1 14: ";
  for(i = 0; i < 3; i++)
  {
    cout << aryOut[i] << " ";
  }
  cout << endl;
}

bool customerWaiting(int ary[])
{
    int i = 0;
    bool allVoid = true;
    
    for(i = 0; i < 3; i++)
    {
        allVoid *= (ary[i] == 0);
    }
    
    return !allVoid;
}

int loadCar(int numInLine[], int numBoard[])
{
  int numIdealSeats[3] = {6,6,8};
  int i = 0;
  int summedNumBoard = 0;
  int percentFilled = 0;
  int numSeats = 20;
  
  if(numInLine[0] < numIdealSeats[0])
  {
    if(numInLine[1] < 
      (numIdealSeats[0] + numIdealSeats[1] 
      - numInLine[0]))
    {
      if(numInLine[2] <
        (numSeats - numInLine[0] - numInLine[1]))
      {
        for(i = 0; i < 3; i++)
        {
          numBoard[i] = numInLine[i];
        }
      }
      else
      {
        numBoard[0] = numInLine[0];
        numBoard[1] = numInLine[1];
        numBoard[2] = numIdealSeats[2];
      } 
    }
    else
    {
      if(numInLine[2] < numIdealSeats[2])
      {
        numBoard[0] = numInLine[0];
        numBoard[1] = numIdealSeats[0] + 
          numIdealSeats[1] - numInLine[0];
        numBoard[2] = numInLine[2];
      }
      else
      {
        numBoard[0] = numInLine[0];
        numBoard[1] = numIdealSeats[0] + 
          numIdealSeats[1] - numInLine[0];
        numBoard[2] = numIdealSeats[2];
      }    
    } 
  }
  else
  {
    if(numInLine[1] < numIdealSeats[1])
    {
      if(numInLine[2] < 
        (numIdealSeats[1] + numIdealSeats[2] 
        - numInLine[1]))
      {
        numBoard[0] = numIdealSeats[0];
        numBoard[1] = numInLine[1];
        numBoard[2] = numInLine[2];
      }
      else
      {
        numBoard[0] = numIdealSeats[0];
        numBoard[1] = numInLine[1];
        numBoard[2] = numIdealSeats[1] + 
          numIdealSeats[2] - numInLine[1];
      } 
    }
    else
    {
      if(numInLine[2] < numIdealSeats[2])
      {
        numBoard[0] = numIdealSeats[0];
        numBoard[1] = numIdealSeats[1];
        numBoard[2] = numInLine[2];
      }
      else
      {
        for(i = 0; i < 3; i++)
        {
          numBoard[i] = numIdealSeats[i];
        }
      }     
    }
  }  

  for(i = 0; i < 3; i++)
  {
    summedNumBoard += numBoard[i];
  }
    
  percentFilled = summedNumBoard * 100 / numSeats;
    
  return percentFilled;
}
