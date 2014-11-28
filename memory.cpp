/*
Author: Tyler Arseneault
Date: December 1, 2014
Lab Assignment 5
Purpose: This file is the class Memory used to simulate computer memory. It wil store integers up to any desired amount, or a default of 100. Contains overloaded operators, such as +, =, ==, !=, [], and <<, so that they know how to operate on Memory.
*/


#include "memory.h"

   extern int *m;
   extern int size;

   Memory::Memory(int s){
   /*constructs instance of Memory using parameter s as the size of the memory*/
   
      size = s;
      m = new int[size];
   }
   
   Memory::Memory(){
   /*constructs instance of Memory, initializing size to 100*/
   
      size = 100;
      m = new int[size];
   }

   Memory::Memory(const Memory &mem){

      copy(mem);
   }
   
   Memory::~Memory(){
   /*destroys instance of Memory*/

      delete [] m;
   }
   
   int Memory::getSize(){
   /*returns the size of the memory allocated*/

      return size;
   }

   void Memory::insert(int data, int location){
   /*Inserts an integer into a specific location*/
      m[location] = data;

   }

   int Memory::retrieve(int location)const{
   /*Returns an integer at a specific location within the memory*/   
   
      //int data = m[location];
      return m[location];

   }

   void Memory::block_copy(int start, int destination, int elements){
   /*copies memory locations into different locations from starting location to
     ending location, including ending location*/

      int tmp[elements];
    
      for(int i = start; i < (start+elements); i++){

         tmp[i - start] = m[i];

      }

      for(int i = destination; i < (destination+elements); i++){

         m[i] = tmp[i - destination];

      }
   
   }

   void Memory::copy(const Memory &mem) {

      m = new int[mem.size];
      size = mem.size;

      for (int i = 0; i < size; i++)
         m[i] = mem.m[i];
   }

   void Memory::dump()const{
   /*dumps all of the values stored in memory*/
   
      dump(0, size);

   }

   void Memory::dump(int start, int end)const{
   /*dumps values stored in memory from location start to location end, including end*/

      printf("Memory Location: ");

      for(int i = start; i < end; i++) 
         printf("%5d ", i);

      printf("\n");
      
      printf("          Value: ");

      for(int i = start; i < end; i++) 
         printf("%05d ", retrieve(i));

   }   

   int &Memory::operator[](int location){
  
      return m[location];
   }

   const int &Memory::operator[](int location)const{

      return m[location];
   }

   Memory & Memory::operator=(const Memory & mem) {
      if (this != & mem) {
         delete [] m;
         copy(mem);
      }
      return *this;
   }

   bool Memory::operator==(const Memory &a){

      if(a.size != size) return false;
      
      for(int i = 0; i < size; i++){
   
         if (m[i] != a[i]) return false;
   
      }
      
      return true;

   }

   bool Memory::operator!=(const Memory &a){

      return !(*this == a);
   }

   Memory operator+(const Memory &a, const Memory &b){

      Memory c(a.size);
 
      for(int i = 0; i < a.size; i++){
         c[i] = a[i] + b[i];

      }

      return c;

   }
   

  ostream& operator<<(ostream & s, const Memory & m ){
     
      m.dump();
      return s;

   }

   

