/*
Author: Tyler Arseneault
Date: December 1, 2014
Lab Assignment 5
Purpose: Contains the class definition for the class Memory created in memory.cpp.
*/

#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Memory {

   private:
   int *m;
   int size;
   
   public:
   Memory(int);
   Memory();
   Memory(const Memory&);
   ~Memory();
   int getSize();
   void insert(int, int);
   int retrieve(int)const;
   void block_copy(int, int, int);
   void copy(const Memory &);
   void dump()const;
   void dump(int, int)const;
   int &operator[](int);
   const int &operator[](int)const;
   Memory &operator=(const Memory &);
   bool operator==(const Memory &);
   bool operator!=(const Memory &);
   friend Memory operator+(const Memory &, const Memory &);
};


ostream& operator<<(ostream &, const Memory &);


#endif
