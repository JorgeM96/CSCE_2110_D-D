//This is the header file for the combined classes

class combinedOBJ  //class for the combined objects
{
	private:
		std::string player;  //player name variable
		std::string classT;  //class variable
		std::string mLevel;  //max lvl variable
		std::string sLevel;  //spell lvl variable
		std::string spell; //spell name variable
		std::string sType; //spell type variable
		int hashN;
	public:
		combinedOBJ(std::string tempPlayer,std::string tempClass,std::string tempMaxLvl,std::string tempSpell,std::string tempSLevel,std::string tempSType,int hnum)
		{
		player = tempPlayer;
	  classT = tempClass;
		mLevel = tempMaxLvl;
		spell = tempSpell;
		sLevel = tempSLevel;
		sType = tempSType;
		hashN = hnum;
		}
	int getValue()  //return key
	{
		return this->hashN;
	}
	std::string getplayer()  //return player
	{
		return this->player;
	}
	std::string getclassT()  //return class
	{
		return this->classT;
	}
	std::string getmLevel() //return max lvl
	{
		return this->mLevel;
	}
	std::string getspell()  //return spell name
	{
		return this->spell;
	}
	std::string getsLevel()  //return spell lvl
	{ 
		return this->sLevel;
	}
	std::string getsType()  //return spell type
	{
		return this->sType;
	}
};

class combinedMap  //class for the combined collections
{
	private:
		combinedOBJ **table4;  //table 4
		int numEntry;
		int cSize;
		
	public:
	
		combinedMap(int size4)  //allocate space
		{
			table4 = new combinedOBJ*[size4];
			for(int i=0;i<size4;i++)
			{
				table4[i] = NULL;
			}
			numEntry=0;
			cSize = size4;
		}
		
		void combineInsert(playerSMap *data1,spellLMap *data2,spellTMap *data3,int size1,int size2,int size3,int size4)
		{

			for(int i=0;i<size1;i++)
			{
				std::string tempPlayer = data1->getPlayer(i);
				std::string tempClass = data1->getClass(i);
				std::string tempMaxLvl = data1->getMaxLvl(i);
				//std::cout << tempPlayer << " " << tempClass << " " <<tempMaxLvl << std::endl;
				for(int j=0;j<size2;j++)
				{
					std::string tempSpell = data2->getSpell(j);
					std::string tempClass2 = data2->getClass2(j);
				  std::string tempSLevel = data2->getSLevel(j);
					//std::cout << tempSpell << " " << tempClass2 << " " << tempSLevel << std::endl;
					if(tempClass == tempClass2 && tempSLevel <= tempMaxLvl)
					{
						for(int k=0;k<size3;k++)
						{
							std::string tempSpell2 = data3->getSpell2(k);
							std::string tempSType = data3->getSType(k);
							//std::cout << tempSpell2 << " "
							if(tempSpell == tempSpell2)
							{
						
								int hnum = convert(tempPlayer,tempClass,tempMaxLvl,tempSpell,tempSLevel,tempSType);
								if(numEntry / size4 > 0.75)
								{
									resize(size4);
								}
      					int hash = hashFunction(hnum,size4);
      					int count =0;
      
								if(table4[hash] == NULL)
								{
									table4[hash] = new combinedOBJ(tempPlayer,tempClass,tempMaxLvl,tempSpell,tempSLevel,tempSType,hnum);
									numEntry++;
								}
								else
								{
								 int check =0;
								while(table4[hash]!= NULL)// && count <size4)
      					{
									if(tempPlayer == table4[hash]->getplayer() && tempClass == table4[hash]->getclassT() && tempMaxLvl == table4[hash]->getmLevel() && tempSpell == table4[hash]->getspell() && tempSLevel == table4[hash]->getsLevel() && tempSType == table4[hash]->getsType())
        					{
									//hash = hashFunction(hash+1,size4);
        					//count++;
									 check = 1;
								 	 break;
									}
									hash +=1;
									if(hash == size4)
									{
										hash = 0;
									}
      					}
								if(check == 0)
								{
      					table4[hash] = new combinedOBJ(tempPlayer,tempClass,tempMaxLvl,tempSpell,tempSLevel,tempSType,hnum);
								numEntry++;
								}
							}
							}
						}
					}	
				}
			}
		}
		int convert(std::string tempPlayer,std::string tempClass,std::string tempMaxLvl,std::string tempSpell,std::string tempSLevel,std::string tempSType)
		{
			int hnum = 0;
			int i;
			for(i = 0; i < tempPlayer.size(); i++)
			{
				hnum += tempPlayer[i];
			}
			for(i = 0; i < tempClass.size(); i++)
			{
				hnum += tempClass[i];
			}
			for(i = 0; i < tempMaxLvl.size(); i++)
			{
				hnum += tempMaxLvl[i];
			}
			for(i = 0; i < tempSpell.size(); i++)
			{
				hnum += tempSpell[i];
			}
			for(i = 0; i < tempSLevel.size(); i++)
			{
				hnum += tempSLevel[i];
			}
			for(i = 0; i < tempSType.size(); i++)
			{
				hnum += tempSType[i];
			}
			return hnum;
		}
		
		int hashFunction(int hnum,int size4)
		{
			return(hnum % size4);
		}
		
		void printTable(int size4)
		{
			for(int i=0;i<size4;i++)
			{
				if(table4[i] != NULL)
				{
					std::cout << "The data found in slot " << i+1 << ": " << table4[i]->getplayer() << " " << table4[i]->getclassT() << " " << table4[i]->getmLevel();
					std::cout << " " << table4[i]->getspell() << " " << table4[i]->getsLevel() << " " << table4[i]->getsType() << std::endl;
				}
			}
			std::cout << "Number of entries in the table: " << numEntry << std::endl;
		}
		
	void option1(int size4) //function to find highest lvl spells for a player
	{
		int i;
		int namecheck=0;
		std::string playerName;
		std::cout << "Enter the player's name." << std::endl;
		std::cin >> playerName;
		std::cout << std::endl << "All the highest level spells that " << playerName << " knows." << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
		for(i=0;i<size4;i++)
		{
			if(table4[i] != NULL)
			{
				if(table4[i]->getplayer() == playerName)
				{
					namecheck =1;
					if(table4[i]->getsLevel() == table4[i]->getmLevel())
					{
						std::cout << "Spell: " << table4[i]->getspell() << " Type: " << table4[i]->getsType() << std::endl;
					}
				}
			}
		}
		if(namecheck == 0)
		{
			std::cout << "Player's name is not in the table." << std::endl;
		}
	}
	
	void option2(int size4)  //function to list the players that currently know wish
	{
	 int i;
	 std::cout << std::endl << "Name(s) of the character(s) who can learn wish (at their given level)." << std::endl;
	 std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;;
	 for(i=0;i<size4;i++)
	 {
	 	if(table4[i]!=NULL)
		{
			if(table4[i]->getclassT() == "Sorcerer" || table4[i]->getclassT() == "Wizard")
			{
				if(table4[i]->getmLevel() == "9")
				{
					if(table4[i]->getspell() == "Wish")
					{
						std::cout << "Player: " << table4[i]->getplayer() << " knows the spell 'Wish'" << std::endl;
					}
				}
			}
		}
	 }
	}
		
	void option3(int size4)  //function to list the players that can learn wish in general
	{
		int i;
		int j;
		int check;
		std::cout << std::endl << "Name(s) of the character(s) who can learn wish in general." << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
		std::string chr[size4];
		for(i=0;i<size4;i++)
		{
			check=0;
			if(table4[i]!=NULL)
			{
				for(j=0;j<size4;j++)
				{
					if(chr[j] == table4[i]->getplayer())
					{
						check = 1;
						break;
					}
				}
			}
			if(table4[i]!=NULL && check == 0)
			{
				if(table4[i]->getclassT() == "Sorcerer" || table4[i]->getclassT() == "Wizard")
				{
					if(table4[i]->getplayer() == "Mathias")  //The player mathias is at a level to already know wish
					{
						std::cout << "Player: " << table4[i]->getplayer() << " already knows wish" << std::endl;
						chr[i] = table4[i]->getplayer();
					}
					else
					{
						std::cout << "Player: " << table4[i]->getplayer() << " can learn wish in general." << std::endl;
						chr[i] = table4[i]->getplayer();
					}
				}
			}
		}
	
	}
	
	void option4(int size4)  //function to list high lvl spells clerics can cast
	{
		int i;
		std::cout << std::endl << "The types of the highest level spells each cleric can cast." << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
		for(i=0;i<size4;i++)
		{
			if(table4[i]!=NULL)
			{
				if(table4[i]->getclassT() == "Cleric")
				{
					if(table4[i]->getsLevel() == table4[i]->getmLevel())
					{
						std::cout << "Player: " << table4[i]->getplayer() <<"'s highest level spell(s) that they can cast : " << table4[i]->getspell() << " Type: " << table4[i]->getsType() << std::endl;
					}
				}
			}
		}
	}
	
	void option5(int size4)  //function to list characters that can cast highest lvl illusion spells
	{
		int i;
		int j;
		int k;
		std::string chr[size4];
		int check = 0;
		std::string lvl1 = "0";
		std::string lvl2 = "0";
		std::string playerN;
		std::string highlvl;
		std::cout << lvl1 << std::endl;
		std::cout << std::endl << "The names of each character that can cast the highest level Illusion spells" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
		for(i=0;i<size4;i++)
		{
			check = 0;
			for(k=0;k<size4;k++)
			{
				if(table4[i]!=NULL && table4[i]->getplayer() == chr[k])
				{
					check = 1;
				}
			}
			if(table4[i]!=NULL && table4[i]->getsType() == "Illusion" && check == 0)
			{
		  	playerN = table4[i]->getplayer();
				lvl1 = table4[i]->getsLevel();
				highlvl = lvl1;
				for(j=0;j<size4;j++)
				{
					if(table4[j]!=NULL && table4[j]->getplayer() == playerN && table4[j]->getsType() == "Illusion")
					{
						lvl2 = table4[j]->getsLevel();
						if(lvl2 > lvl1)
						{
							lvl1 = lvl2;
							highlvl = lvl2;
						}
					}
				}
			std::cout << "Player: " << table4[i]->getplayer() <<" can cast " << table4[i]->getspell() <<" which is an illusion spell of high level "; 
			std::cout << highlvl << std::endl;
			chr[i] = table4[i]->getplayer();
			}
		}
	}
	void resize(int size4)  //resize function every time table is almost full ( !! DOES NOT WORK !! )
	{
			combinedOBJ **temp = new combinedOBJ*[size4];
			for(int i=0;i<size4;i++)
			{
				if(table4[i] != NULL)
				{
					temp[i] = new combinedOBJ(table4[i]->getplayer(),table4[i]->getclassT(),table4[i]->getmLevel(),table4[i]->getspell(),table4[i]->getsLevel(),table4[i]->getsType(),table4[i]->getValue());	
				}
				else
				{
					temp[i] = NULL;
				}
			}
			const int prev_size = size4;
			size4 *= 2;
			cSize = size4;
			table4 = new combinedOBJ * [size4];
			for (int i = 0; i < size4; i++)
			{
				table4[i] = NULL;
			}
			numEntry =0;
			for(int i = 0; i < prev_size; i++)
			{
				if(temp[i] != NULL)
				{
					resizeInsert(temp[i]->getplayer(),temp[i]->getclassT(),temp[i]->getmLevel(),temp[i]->getspell(),temp[i]->getsLevel(),temp[i]->getsType(),size4);
				}
			}
		}
		
		void resizeInsert(std::string tempP,std::string tempC,std::string tempM,std::string tempS,std::string tempL,std::string tempT,int size4)
		{
			int hnum = convert(tempP,tempC,tempM,tempS,tempL,tempT);
      int hash = hashFunction(hnum,size4);
      int count =0;
			if(table4[hash] == NULL)
			{
				table4[hash] = new combinedOBJ(tempP,tempC,tempM,tempS,tempL,tempS,hnum);
				numEntry++;
			}
			else
			{
			 int check =0;
			 while(table4[hash]!= NULL)// && count <size4)
       {
			 	if(tempP == table4[hash]->getplayer() && tempC == table4[hash]->getclassT() && tempM == table4[hash]->getmLevel() && tempS == table4[hash]->getspell() && tempL == table4[hash]->getsLevel() && tempT == table4[hash]->getsType())
        {
				 check = 1;
				 break;
				}
				hash +=1;
				if(hash == size4)
				{
					hash = 0;
			  }
       }
			 if(check == 0)
			 {
      	table4[hash] = new combinedOBJ(tempP,tempC,tempM,tempS,tempL,tempT,hnum);
				numEntry++;
        }
			}
		}
		
		~combinedMap()  //deconstructor
      {
        for(int i=0;i<cSize;i++)
        {
          if(table4[i] != NULL)
          {
            delete table4[i];          
					}
        }
        delete[] table4;
      }
	};