/*Author: Jorge Moreno
  Instructor: Professor Ryan Michaels
  Date: 3/8/18
  Description: This program is designed around the game dungeons and dragons. In my program i take 3 data files that contain various stats and descriptions of players. This program
  puts the information in those 3 files into 3 hash tables then combined them into one huge table. Afterwords a menu allows the user to list information.*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "tables.h"
#include "combined.h"
using namespace std;

int main()
{
  int size1=0;     //table 1 size
  int size2=0;    //table 2 size
  int size3=0;   //table 3 size
  int size4=0;  //combined table size4
  int choice;  //variable to hold the user's menu choice

  string temp1;    //temp variable to find the size of a file
  string temp2;   //temp variable to find the size of a file
  string temp3;  //temp variable to find the size of a file
  
  ifstream d1;   //to read in date1 file
  ifstream d2;  //to read in data2 file
  ifstream d3; //to red in data3 file
  
  playerSMap *data1;  //playerSMap class variable for data1 file
  spellLMap *data2;  //hashmap class variable for data2 file
  spellTMap *data3;  //hashmap class variable for data3 file
  combinedMap *data4;
  int i;  //counter variable
 cout << endl;
 cout << "====================================================================================================" << endl; 
 cout << "                        ____.//)" << endl;
 cout << "                         -._ \\          /:" << endl;
 cout << "                         _.-' \\        (\\___" << endl;
 cout << "                            ,' \\    .'`\\.) :^-._______" << endl;
 cout << "                      ,   ' .'/||    / /   _ `""`  ```  `,        _ _  ~ - _" << endl;
 cout << "                          .' / ||   / |   ( `.~v~v~v~v~v'  _  -- *     *  _ -" << endl;
 cout << "                         '  /  ||  |.\\    `. `.  __-  ~ -     ~         --   -" << endl;
 cout << "                           /   ||  | :  `----`. `.  -~ _  _ ~ *           *  -" << endl;
 cout << "                          /    ||  \\:_     /  `. `.  - *__   -    -       __" << endl;
 cout << "                          /    .'/    `.`----\\    `._;        --  _ *  -     _" << endl;
 cout << "                                ||      `,_    `                     - -__ -" << endl;
 cout << "                               ||       /  `---':" << endl;
 cout << "                               ||      /        ;" << endl;
 cout << "                               ||     /_       :" << endl;
 cout << "                               ||    /  `-----':" << endl;
 cout << "                               ||  .'         :" << endl;
 cout << "                               \\.'_         _::" << endl;
 cout << "                                \\__`-------'   `." << endl;
 cout << "                          Welcome to Dungeons and Dragons!" << endl;
 cout << "====================================================================================================" << endl;
    

  d1.open("data1.txt");  //open data1 fie
  if(d1.fail())
  {
    cout << "Unable to open data1 file." << endl;
    exit(EXIT_FAILURE);
  }
  d2.open("data2.txt");  //open data2 file
  {
    if(d2.fail())
    {
      cout << "Unable to open data2 file." << endl;
      exit(EXIT_FAILURE);
    }
  }
  d3.open("data3.txt");  //open data3 file
  {
    if(d3.fail())
    {
      cout << "Unable to open data3 file." << endl;
      exit(EXIT_FAILURE);
    }
  }
  while(!d1.eof())  //read in data1 file to get size
  {
    d1 >> temp1 >> temp2 >> temp3;
    size1++;
  }
  data1 = new playerSMap(size1);  //allocate table size 
  while(!d2.eof())  //read in data2 file to get size
  {
    d2 >> temp1 >> temp2 >> temp3;
    size2++;
  }
  data2 = new spellLMap(size2);  //allocate table size
  while(!d3.eof())  //read in data3 file to get size
  {
    d3 >> temp1 >> temp2;
    size3++;
  }
  data3 = new spellTMap(size3);  //allocate table size
  size4 = 800;  //size of the combined table
  data4 = new combinedMap(size4);
  
  d1.seekg(0,d1.beg);    //reset pointer to the first line
  d2.seekg(0,d2.beg);   //reset pointer to the first line
  d3.seekg(0,d3.beg);  //reset pointer to the first line
  
  d1 >> temp1 >> temp2 >> temp3;  //skip the first line
  while(!d1.eof())  //read in each string and insert into the table
  {
    d1 >> temp1 >> temp2 >> temp3;
    data1->insertValue(temp1,temp2,temp3,size1);
  }
  d2 >> temp1 >> temp2 >> temp3; //skip the first line
  while(!d2.eof()) //read in each string and insert into the table
  {
    d2 >> temp1 >> temp2 >> temp3;
    data2->insertValue(temp1,temp2,temp3,size2);
  }
  d3 >> temp1 >> temp2; //skip the first line
  while(!d3.eof()) //read in each string and insert into the table
  {
    d3 >> temp1 >> temp2;
    data3->insertValue(temp1,temp2,size3);
  }
 
  data4->combineInsert(data1,data2,data3,size1,size2,size3,size4);  //combine all other tables into 1
  
  while(1)  //menu loops until they choose exit
  {
    cout << "====================================================================================================" << endl;
    cout << "Pick an option in this menu." << endl;
    cout << "1. What type(s) are the highest level spells that a player knows." << endl;//Jovani and William know?" << endl;
    cout << "2. What are the names of the characters that can learn wish currently (at their given player level)?" << endl;
    cout << "3. What characters can learn wish in general?" << endl;
    cout << "4. What are the types of the highest level spells each cleric can cast?" << endl;
    cout << "5. What are the names of each character that can cast the highest level Illusion spells?" << endl;
    cout << "6. Print the table for data1.txt" << endl;
    cout << "7. Print the table for data2.txt" << endl;
    cout << "8. Print the table for data3.txt" << endl;
    cout << "9. Print the combined table" << endl;
    cout << "10. Exit the program." << endl;
    cout << "            ======= Enter a number =======" << endl;
    cout << "====================================================================================================" << endl;
    cin >> choice;
    cin.clear();  //need these two lines to avoid infinite loop when a user enters a character.
    cin.ignore(100,'\n');
  
    switch(choice)
    {
      case 1:
        {
        data4->option1(size4);
        }
      break;
      case 2:
        {
        data4->option2(size4);
        }
      break;
      case 3:
        {
        data4->option3(size4);
        }
      break;
      case 4:
        {
        data4->option4(size4);
        }
      break;
      case 5:
        {
        data4->option5(size4);
        }
      break;
      case 6:
        {
          data1->printTable(size1);
        }
      break;
      case 7:
        {
          data2->printTable(size2);
        }
      break;
      case 8:
        {
          data3->printTable(size3);
        }
      break;
      case 9:
        {
          data4->printTable(size4);
        }
      break;
      case 10:
        {
          cout << endl << "=======================" << endl;
          cout << "Have a nice day!" << endl;
          cout << "=======================" << endl;
          exit(1);
        }
      default:
        cout << endl << "What you entered is not an option, please enter a correct menu number." << endl;
    }
  }
  //close all the files
  d1.close();
  d2.close();
  d3.close();
  return 0;
}
