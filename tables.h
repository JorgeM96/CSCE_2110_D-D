//This is the header file that includes all the classes needed for program2.

class playerStats  //class for the first table
{
  private:
  std::string player;  //player variable
  std::string sLevel;  //player's max spell lvl variable 
  int hashN;  //unique key variable
  
  public:
    playerStats(std::string temp1,std::string temp3,int hnum)  //set variable after insert
    {
      this->player = temp1;
      this->sLevel = temp3;
      this->hashN = hnum;
    }
    std::string getplayer()  //return the player's name
    {
      return this->player;
    }
    std::string getsLevel()  //return the max spell lvl
    {
      return this->sLevel;
    }
    int getValue()  //return the unique key
    {
      return this->hashN;
    }
  
};

class playerClass  //class for a players class
{
  private:
  std::string classT;  //player's class variable
  
  public:
    playerClass(std::string temp2)
    {
      this->classT = temp2;
    }
    std::string getclassT()  //return class
    {
      return this->classT;
    }
};

class playerSMap  //class for players collection
{
  private:
  playerStats **table1;  //table for first class
  playerClass **tableC;  //table for second class
  
  public:
	int pSize;
    playerSMap(int size1) //allocating size
    {
      table1 = new playerStats*[size1];
      for(int i=0;i<size1;i++)
      {
        table1[i] = NULL;
      }
      tableC = new playerClass*[size1];
      for(int i=0;i<size1;i++)
      {
        tableC[i] = NULL;
      }
			pSize = size1;
    }
    
    std::string getPlayer(int i)  //return player
    {
        if(table1[i] != NULL)
        {
          return(table1[i]->getplayer());
        }
        else
        {
          return "NULL";
        }
    }
    std::string getClass(int i)  //return calss
    {
        if(tableC[i] != NULL)
        {
          return(tableC[i]->getclassT());
        }
        else
        {
          return "NULL";
        }
    }
    std::string getMaxLvl(int i)  //return max lvl
    {
        if(table1[i] != NULL)
        {
          return(table1[i]->getsLevel());
        }
        else
        {
          return "NULL";
        }
    }
    void insertValue(std::string temp1, std::string temp2,std::string temp3,int size1)
    {
      int hnum = convert(temp1,temp2,temp3,size1);
      int hash = hashFunction(hnum,size1);
      int count=0;
 
      if(table1[hash] == NULL)
								{
									table1[hash] = new playerStats(temp1,temp3,hnum);
								}
								else
								{
                int check =0;
								while(table1[hash]!= NULL)// && count <size4)
      					{
									if(temp1 == table1[hash]->getplayer() &&  temp2 == table1[hash]->getsLevel())
        					{
									 check = 1;
								 	 break;
									}
									hash +=1;
									if(hash == size1)
									{
										hash = 0;
									}
      					}
								if(check == 0)
								{
      					  table1[hash] = new playerStats(temp1,temp3,hnum);
								}
              }  
              if(tableC[hash] == NULL)
								{
									tableC[hash] = new playerClass(temp2);
								}
								else
								{
                int check2 =0;
								while(tableC[hash]!= NULL)// && count <size4)
      					{
									if(temp2 == tableC[hash]->getclassT())
        					{
									 check2 = 1;
								 	 break;
									}
									hash +=1;
									if(hash == size1)
									{
										hash = 0;
									}
      					}
								if(check2 == 0)
								{
      					  tableC[hash] = new playerClass(temp2);
								}
               }
   }
   
   int convert(std::string temp1, std::string temp2,std::string temp3,int size1)
   {
    int hnum = 0;
    int i;
    for(i=0;i<temp1.size();i++)
    {
      hnum+= temp1[i];
    }
    for(i=0;i<temp2.size();i++)
    {
      hnum+= temp2[i];
    }
    for(i=0;i<temp3.size();i++)
    {
      hnum+= temp3[i];
    }
    return(hnum);
   }
   
   int hashFunction(int hnum,int size1)
   {
    return(hnum % size1);
   }
    
    void printTable(int size1)
    {
      for(int i=0;i<size1;i++)
      {
        if(table1[i] != NULL)
        {
         std::cout << "The data found in slot " << i+1 << ": " << table1[i]->getplayer() << " " << tableC[i]->getclassT() << " " << table1[i]->getsLevel() << std::endl;
        }
      }
    }
    ~playerSMap()  //deconstructor
      {
				int i;
        for(i=0;i<pSize;i++)
        {
          if(table1[i] != NULL)
          {
            delete table1[i];          }
        }
        delete[] table1;
				for(i=0;i<pSize;i++)
				{
					if(tableC[i] != NULL)
					{
						delete tableC[i];
					}
				}
				delete[] tableC;
      }
};
///////////////////////////////////////////////////////////////////////
class spellLVL  //class for second table
{
  private:
    std::string spell;  //spell name variable
    std::string classT;  //class that uses said spell
    std::string sLevel;  //spell lvl needed
    int hashN;  //unique key
    
  public:
    spellLVL(std::string temp1,std::string temp2,std::string temp3, int hnum)
    {
      this->spell = temp1;
      this->classT = temp2;
      this->sLevel = temp3;
      this->hashN = hnum;
     }
     std::string getspell()  //return spell
     {
      return this->spell;
     }
     std::string getclassT()  //return class
     {
      return this->classT;
     }
     std::string getsLevel()  //return spell lvl
     {  
      return this->sLevel;
     }
     int getValue()  //return unique key
     {
      return this->hashN;
     }
};

class spellLMap  //class for the spell collection
{
  private:
  spellLVL **table2;  //second table
  
  public:
	int sSize;
    spellLMap(int size2)  //allocate space
    {
      table2 = new spellLVL*[size2];
      for(int i=0;i<size2;i++)
      {
        table2[i] = NULL;
      }
			sSize = size2;
    }
    
    std::string getSpell(int j)  //retun spell
    {
      if(table2[j] != NULL)
      {
      return(table2[j]->getspell());
      }
      else
      {
        return "NULL";
      }
    }
    std::string getClass2(int j)  //return class
    {
      if(table2[j] != NULL)
      {
      return(table2[j]->getclassT());
      }
      else
      {
        return "NULL";
      }
    }
    std::string getSLevel(int j)  //return spell level
    {
      if(table2[j] != NULL)
      {
      return(table2[j]->getsLevel());
      }
      else
      {
        return "NULL";
      }
    }
    void insertValue(std::string temp1,std::string temp2,std::string temp3,int size2)
    {
      int hnum = convert(temp1,temp2,temp3,size2);
      int hash = hashFunction(hnum,size2);
      int count =0;
      
    
    if(table2[hash] == NULL)
								{
									table2[hash] = new spellLVL(temp1,temp2,temp3,hnum);
								}
								else
								{
                int check3 =0;
								while(table2[hash]!= NULL)// && count <size4)
      					{
									if(temp1 == table2[hash]->getspell() && temp2 == table2[hash]->getclassT() && temp3 == table2[hash]->getsLevel())
        					{
									 check3 = 1;
								 	 break;
									}
									hash +=1;
									if(hash == size2)
									{
										hash = 0;
									}
      					}
								if(check3 == 0)
								{
      					  table2[hash] = new spellLVL(temp1,temp2,temp3,hnum);
								}
              }
             }
    
    int convert(std::string temp1,std::string temp2,std::string temp3,int size2)
    {
     int hnum = 0;
     int i;
     for(i=0;i<temp1.size();i++)
     {
       hnum+= temp1[i];
     }
     for(i=0;i<temp2.size();i++)
     {
       hnum+= temp2[i];
     }
     for(i=0;i<temp3.size();i++)
     {
       hnum+= temp3[i];
     }
     return(hnum);
    }
    
   int hashFunction(int hnum,int size2)
   {
    return(hnum % size2);
   }
   
   void printTable(int size2)
    {
      for(int i=0;i<size2;i++)
      {
        if(table2[i] != NULL)
        {
          std::cout << "The data found in slot " << i+1 << ": " << table2[i]->getspell() << " " << table2[i]->getclassT() << " " << table2[i]->getsLevel() << std::endl;
        }
      }
    }
		~spellLMap()  //deconstructor
      {
        for(int i=0;i<sSize;i++)
        {
          if(table2[i] != NULL)
          {
            delete table2[i];          }
        }
        delete[] table2;
      }
};
//////////////////////////////////////////////////////////////////////
class spellType  //class for the spell types
{
  private:
    std::string spell;  //spell name variable
    std::string sType;  //spell type variable
    int hashN;
    
  public:
    spellType(std::string temp1,std::string temp2,int hnum)
    {
      this->spell = temp1;
      this->sType = temp2;
      this->hashN = hnum;
    }
    std::string getspell()  //return spell
    {
      return this->spell;
    }
    std::string getsType()  //return type
    {
      return this->sType;
    }
    int getValue()  //return key
    {
      return this->hashN;
    }  
};

class spellTMap //class for collection of spell types
{
  private:
  spellType **table3; //table 3
  
  public:
	int sSize2;
    spellTMap(int size3) //allocate space
    {
      table3 = new spellType*[size3];
      for(int i=0;i<size3;i++)
      {
        table3[i] = NULL;
      }
			sSize2 = size3;
    }
    
    std::string getSpell2(int k) //return spell name
    {
      if(table3[k]!=NULL)
      {
        return(table3[k]->getspell());
      }
      else
      {
        return "NULL";
      }
    }
     std::string getSType(int k)  //return spell type
    {
      if(table3[k]!=NULL)
      {
        return(table3[k]->getsType());
      }
      else
      {
        return "NULL";
      }
    }
    void insertValue(std::string temp1, std::string temp2,int size3)
    {
      int hnum = convert(temp1,temp2,size3);
      int hash = hashFunction(hnum,size3);
      int count =0;
 
    if(table3[hash] == NULL)
								{
									table3[hash] = new spellType(temp1,temp2,hnum);
								}
								else
								{
                int check4 =0;
								while(table3[hash]!= NULL)// && count <size4)
      					{
									if(temp1 == table3[hash]->getspell() && temp2 == table3[hash]->getsType())
        					{
									 check4 = 1;
								 	 break;
									}
									hash +=1;
									if(hash == size3)
									{
										hash = 0;
									}
      					}
								if(check4 == 0)
								{
      					  table3[hash] = new spellType(temp1,temp2,hnum);
								}
              }
             }
    
    int convert(std::string temp1,std::string temp2,int size3)
    {
     int hnum = 0;
     int i;
     for(i=0;i<temp1.size();i++)
     {
       hnum+= temp1[i];
     }
     for(i=0;i<temp2.size();i++)
     {
       hnum+= temp2[i];
     }
     return(hnum);
    }
    
   int hashFunction(int hnum,int size3)
   {
    return(hnum % size3);
   }
   
   void printTable(int size3)
    {
      for(int i=0;i<size3;i++)
      {
        if(table3[i] != NULL)
        {
          std::cout << "The data found in slot " << i+1 << ": " << table3[i]->getspell() << " " << table3[i]->getsType() << std::endl;
        }
      }
    } 
		~spellTMap()  //deconstructor
      {
        for(int i=0;i<sSize2;i++)
        {
          if(table3[i] != NULL)
          {
            delete table3[i];          
				  }
        }
        delete[] table3;
      }
};
