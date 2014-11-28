/*
Author: Tyler Arseneault
Date: December 1, 2014
Lab Assignment 5
Purpose: This file is the driver file that will test out the Memory class created in Memory.cpp to simulate memory. Will test out the use of the overloaded operators.
*/

#include "memory.h"

using namespace std;

int main(void){

   Memory m(10);
   
   for(int i = 0; i < m.getSize(); i++) 
      m[i] = i; //loads first 10 locations with values increasing from 0 - 9
   cout << "Memory m:" << endl;
   cout << m; //dumps Memory m

   cout << endl << endl;

   m.block_copy(1,5,4);//copies memory block starting at location 1, to location 5, and copies 4 locations
   cout << "Memory m:" << endl;
   cout << m << endl; //dumps Memory m

   cout << endl << endl;
   cout << "Memory m:" << endl;
   m.dump(1,3);       //dumps specific block of Memory m

   cout << endl << endl;
   cout << "Integer retrieved:  ";
   cout << m.retrieve(5) << endl << endl; //get the value in location 5 in Memory m

   Memory a = m;  //Memory a is a copy of Memory m
   cout << "Memory a:" << endl;
   cout << a << endl << endl;  //dump Memory a
   
   /*check to see if Memory m and Memory a are equal*/ 
   if(m == a) 
      cout << "Memory m and Memory a are equal" << endl << endl;
   else if (m != a)
      cout << "Memory m and Memory a are not equal" << endl << endl;

   Memory b(10); //Memory b is a new Memory with 10 locations, all containing 0
   for(int i = 0; i < b.getSize(); i++)
      b[i] = i + 5;  //load b up with values from 5 - 15
   cout << "Memory b:" << endl;
   cout << b << endl << endl;  //dump Memory b
   
   /*check to see if Memory m is equal to Memory b*/
   if(m == b)
      cout << "Memory m and Memory b are equal" << endl << endl;
   else if (m != b)
      cout << "Memory m and Memory b are not equal" << endl << endl;

   Memory c = a + b;  //new Memory c contains the sum of each location of Memories m and a
   cout << "Memory c = a + b:" << endl;
   cout << c << endl << endl; //dump Memory c

   return 0;
}
