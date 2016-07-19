#include "ExampleAIModule.h"
using namespace BWAPI;

bool analyzed;
bool analysis_just_finished;
BWTA::Region* home;
BWTA::Region* enemy_base;


#include <windows.h>
//���� �����
#include <stdlib.h>
#include <string.h>

FILE *fp;
/*
FILE *fp1;
FILE *fp_self;
FILE *fo;
FILE *fp_dps;
FILE *fp_dummy;
*/
int replay_num=0;

//�÷��̾� �������ֱ� self, enemy
std::set<Player*>::iterator p1;
std::set<Player*>::iterator p2;
//������ �Ǵ� �÷��̾� �������ֱ�
int Player_;

void ExampleAIModule::onStart()
{
//������ �Ǵ� �÷��̾� �������ֱ� - �����ٲ��ֱ�-
	Player_=1;

	//chc

	//~~!!!!!!���÷��� ��ȣ �������ֱ�~!!!!!!

	//chc ���²��� �ϸ� �ʿ����..-����-
	/*
	char pre_word[1024] = "maps\\replays\\";
	char last_word[1024] = ".rep";
	char center_word[1024];

	for(int i=1;i<=999;i++)
	{
		bool make_success = false;
		sprintf(center_word,"%d",i);
		strcat(pre_word,center_word);
		strcat(pre_word,last_word);


		//if(fopen(pre_word,"r") != NULL)//remove �����ϸ� 0 �����ϸ� -1
		if(remove(pre_word) == 0)
		{
			replay_num = i;
			break;
		}	

		strcpy(pre_word,"maps\\replays\\");

	}


	//���׷��̵� ���� �ʱ�ȭ
	Ground_Weapons_cnt = 1;

	//���������� ����. �ڵ����� 6000������ ���𰡴�. -����-  fclose���ֱ�?  
	char fileName[256];
	char fileName_self[256];
	char fileName_dps[256];



	sprintf(fileName,"cig2014\\%d.txt",replay_num);

	fp = fopen(fileName,"w");
	*/ //chc ���²��� �ϸ� �ʿ����..-��-

	fp=fopen("print\\output_temp.txt","w");
	

	/*
	sprintf(fileName_self,"self\\%d.txt",replay_num);
	fp_self = fopen(fileName_self,"w");


	sprintf(fileName_dps,"dps\\%d.txt",replay_num);
	fp_dps = fopen(fileName_dps,"w");
	*/


	//���������� ����. �ڵ����� 6000������ ���𰡴�. -��-


	Broodwar->setLocalSpeed(0);

	//chc


	//Broodwar->sendText("Hello world!");
	//Broodwar->printf("The map is %s, a %d player map",Broodwar->mapName().c_str(),Broodwar->getStartLocations().size());
	// Enable some cheat flags
	Broodwar->enableFlag(Flag::UserInput);
	// Uncomment to enable complete map information
	//Broodwar->enableFlag(Flag::CompleteMapInformation);

	//read map information into BWTA so terrain analysis can be done in another thread
	BWTA::readMap();
	analyzed=false;
	analysis_just_finished=false;

	show_bullets=false;
	show_visibility_data=false;

	if (Broodwar->isReplay())
	{
		Broodwar->printf("The following players are in this replay:");
		for(std::set<Player*>::iterator p=Broodwar->getPlayers().begin();p!=Broodwar->getPlayers().end();p++)
		{
			if (!(*p)->getUnits().empty() && !(*p)->isNeutral())
			{
				Broodwar->printf("%s, playing as a %s",(*p)->getName().c_str(),(*p)->getRace().getName().c_str());
			}
		}



		
	//�÷��̾� �������ֱ�--- ���� ---chc
if(Player_ == 1)
{
	for(std::set<Player*>::iterator p=Broodwar->getPlayers().begin();p!=Broodwar->getPlayers().end();p++)
	{
		if (!(*p)->getUnits().empty() && !(*p)->isNeutral())
		{
			//������ �ƴ��� �Ǵ� - ����3�� ���Ϸ� ������ �������� �Ǵ�
			//if((*p)->allUnitCount(BWAPI::UnitTypes::AllUnits)<=3)
			{
			p1=p;
			break;	
			}
		}
	}


	for(std::set<Player*>::iterator p=Broodwar->getPlayers().begin();p!=Broodwar->getPlayers().end();p++)
	{
		if (!(*p)->getUnits().empty() && !(*p)->isNeutral())
		{
			if(p1 != p)
			{
				
					//������ �ƴ��� �Ǵ� - ����4���̻� ������
				//if((*p)->allUnitCount(BWAPI::UnitTypes::AllUnits)<=3)
			{
				p2=p;		  
				break;
			}
			}
		}
	}
}

if(Player_ == 2)
{
	for(std::set<Player*>::iterator p=Broodwar->getPlayers().begin();p!=Broodwar->getPlayers().end();p++)
	{
		if (!(*p)->getUnits().empty() && !(*p)->isNeutral())
		{
			//������ �ƴ��� �Ǵ� - ����3�� ���Ϸ� ������ �������� �Ǵ�
			//if((*p)->allUnitCount(BWAPI::UnitTypes::AllUnits)<=3)
			{
			p2=p;
			break;	
			}
		}
	}


	for(std::set<Player*>::iterator p=Broodwar->getPlayers().begin();p!=Broodwar->getPlayers().end();p++)
	{
		if (!(*p)->getUnits().empty() && !(*p)->isNeutral())
		{
			if(p2 != p)
			{
				
					//������ �ƴ��� �Ǵ� - ����4���̻� ������
				//if((*p)->allUnitCount(BWAPI::UnitTypes::AllUnits)<=3)
			{
				p1=p;		  
				break;
			}
			}
		}
	}
}









	//�÷��̾� �������ֱ�--- �� --- chc

	
	//�׶��̳� �����̸� �������� �ϱ�// --����--
	
	if((*p1)->getRace() == Races::Zerg || (*p1)->getRace() == Races::Terran)
	{
			std::set<BWAPI::Unit *>::const_iterator en12 = (*p1)->getUnits().end();
			(*en12)->getID();
	}

	if((*p2)->getRace() == Races::Zerg || (*p2)->getRace() == Races::Terran)
	{
			std::set<BWAPI::Unit *>::const_iterator en12 = (*p2)->getUnits().end();
			(*en12)->getID();
	}

	//�׶��̳� �����̸� �������� �ϱ�// --��--

	






	}
	else
	{
		Broodwar->printf("The match up is %s v %s",
			Broodwar->self()->getRace().getName().c_str(),
			Broodwar->enemy()->getRace().getName().c_str());

		//send each worker to the mineral field that is closest to it
		for(std::set<Unit*>::const_iterator i=Broodwar->self()->getUnits().begin();i!=Broodwar->self()->getUnits().end();i++)
		{
			if ((*i)->getType().isWorker())
			{
				Unit* closestMineral=NULL;
				for(std::set<Unit*>::iterator m=Broodwar->getMinerals().begin();m!=Broodwar->getMinerals().end();m++)
				{
					if (closestMineral==NULL || (*i)->getDistance(*m)<(*i)->getDistance(closestMineral))
						closestMineral=*m;
				}
				if (closestMineral!=NULL)
					(*i)->rightClick(closestMineral);
			}
			else if ((*i)->getType().isResourceDepot())
			{
				//if this is a center, tell it to build the appropiate type of worker
				if ((*i)->getType().getRace()!=Races::Zerg)
				{
					(*i)->train(Broodwar->self()->getRace().getWorker());
				}
				else //if we are Zerg, we need to select a larva and morph it into a drone
				{
					std::set<Unit*> myLarva=(*i)->getLarva();
					if (myLarva.size()>0)
					{
						Unit* larva=*myLarva.begin();
						larva->morph(UnitTypes::Zerg_Drone);
					}
				}
			}
		}
	}
}

void ExampleAIModule::onEnd(bool isWinner)
{
	//fp_dummy = fopen("print\\output.txt","w");//���� ���α׷� ������ ����
		fclose(fp);
	rename("print\\output_temp.txt","print\\output.txt");

	//fclose(fp_dummy);
	if (isWinner)
	{
		//log win to file
	}
}





//*************�ð������ϱ�



//�ð������ϴ� �Լ�
LARGE_INTEGER start, end, Frequency;



void time_start()
{
	//1�ʿ� ��ȸ������ ���ļ�����
	QueryPerformanceFrequency(&Frequency);   
	//����ð� ��������
	QueryPerformanceCounter(&start); 
}
//�ð���������� ȭ�� ���
void time_end()
{
	//����ð� ��������
	QueryPerformanceCounter(&end);    

	//�Լ� �����ð� ���(�ʴ���)
	Broodwar->drawTextScreen(20,20,"self Probe : %f (sec)",(double)(end.QuadPart - start.QuadPart) / (double)Frequency.QuadPart);
	//  printf("%f(sec)\n", (double)(end.QuadPart - start.QuadPart) / (double)Frequency.QuadPart);
	//fprintf(fp,"%f(sec)\n",(double)(end.QuadPart - start.QuadPart) / (double)Frequency.QuadPart);

}





void ExampleAIModule::onFrame()
{


	  // isattacking �� �׽�Ʈ
	
	/*
	for (std::set<BWAPI::Unit *>::const_iterator en = (*p1)->getUnits().begin(); en != (*p1)->getUnits().end(); ++en)
		{
			if ((*en)->getType() == BWAPI::UnitTypes::Protoss_Dragoon && (*en)->isCompleted())//�츮���������
			{

				Broodwar->drawTextScreen(200,10,"isAttackFrame : %d ",(*en)->isAttackFrame()); //������ �� ������
				Broodwar->drawTextScreen(200,20,"isAttacking : %d ",(*en)->isAttacking());   //���� �����ϰ� �ִ� ����(�̵�x, �ƿ� ���缭 �����ϴ»�Ȳ, ���� �����Ÿ� ���� �ִ� ��Ȳ)  
				Broodwar->drawTextScreen(200,30,"getGroundWeaponCooldown : %d ",(*en)->getGroundWeaponCooldown()); //���� �� �ϸ� ������� ���� 0�̵Ǹ� �ٽ� ���ݰ���
				Broodwar->drawTextScreen(200,40,"isUnderAttack : %d ",(*en)->isUnderAttack());  
				Broodwar->drawTextScreen(200,50,"isStartingAttack : %d ",(*en)->isStartingAttack()); //isattackframe�� ����
				Broodwar->drawTextScreen(200,60,"hp (hp + shield) in protoss : %d ",(*en)->getHitPoints() + (*en)->getShields()); //shield�� 0�϶��� shield�� 1�� ǥ�õ�
				
				Broodwar->drawTextScreen(200,70,"X number : %d, Y number ; %d", (*en)->getPosition().x(), (*en)->getPosition().y());
				break;
				
			}
	}
	*/
	
	




	//chc ���÷��̿��� ��ó���ϱ� - ���� - 

	time_start(); //�ð� ����
	//�츮�� ���� ����ϱ�(����,��󱺸�).  
	//�١١ٿ츮�� ���ֵ� ���Ϸ� ����ϴ¼ҽ�.
	static int frametesttest_self=Broodwar->getFrameCount();
	int en_id;
	if(Broodwar->getFrameCount() == frametesttest_self)  
	{
		//1�ʸ��� ���
		frametesttest_self = frametesttest_self + 3; //���߿� �������ֱ�.

		
		//**���÷��̿����� ������ ����((*p1)->getUnits().end())���� ������ ���� ������ �� ������ ���ְ� ��.. �׽�Ʈ�غ��� �� ������ �������� �ʴ� ������..**/
		
		//������ ����ߴ��� ���� ���� ���� 
		int printed_num_self=0;
		int ae=0;
		for (std::set<BWAPI::Unit *>::const_iterator en = (*p1)->getUnits().begin(); en != (*p1)->getUnits().end(); ++en)
		{
			

			/*
			(Unit_ID, Type, X, Y), ..., Time  // Type -> �츮��: ���:-1, ���� : -2, ���� :��� -3, ���� -4,�츮�� = 36��, ���� = 36��, ���ֻ��̿��� -100�� ǥ����
			����, ��� ���ַ� �̰�, (�������÷�, ��Ʋ, ����, ������, ��ũ��)�� ������� ġȯ���� ����.
			*/

			if ((*en)->getType() == BWAPI::UnitTypes::Protoss_Dragoon && (*en)->isCompleted())//�츮�������
			{		
				fprintf(fp," %d %d %d %d %d %d -100",(*en)->getID(),-1,(*en)->getPosition().x(),(*en)->getPosition().y(),(*en)->getHitPoints() + (*en)->getShields(),(*en)->getOrder().getID());
				printed_num_self++;
			}
			if ((*en)->getType() == BWAPI::UnitTypes::Protoss_Zealot && (*en)->isCompleted())//�츮���������
			{
				fprintf(fp," %d %d %d %d %d %d -100",(*en)->getID(),-2,(*en)->getPosition().x(),(*en)->getPosition().y(),(*en)->getHitPoints() + (*en)->getShields(),(*en)->getOrder().getID());
				printed_num_self++;
			}





		}

		/*
		//36����� ����� ���� �ʾ����� ������ �͵��� 0���� ä���ֱ�
		while(printed_num_self<36)
		{
			fprintf(fp," 0 0 0 0 0 0 -100");		
			printed_num_self++;
		}
		*/

	}

	/* ������ �١١�
	if ((*en)->getType() == BWAPI::UnitTypes::Protoss_Nexus) { en_id = (*en)->getID(); fprintf(fp,"%d Protoss_Nexus %d\n",(Broodwar->getFrameCount()/24),en_id);}
	else if ((*en)->getType() == BWAPI::UnitTypes::Protoss_Assimilator) { en_id = (*en)->getID(); fprintf(fp,"%d Protoss_Assimilator %d\n",(Broodwar->getFrameCount()/24),en_id);}



	/*
	ProtossRange  - singularity charge
	ProtossGroundWeapons1
	ProtossGroundArmor1
	ProtossShields1 
	ProtossGroundWeapons2 
	ProtossGroundArmor2
	ProtossShields2
	ProtossLegs - leg enhancements
	ProtossStorm - psionic
	ProtossMaelstorm    ����
	ProtossShuttleSpeed - gravitic drive
	ProtossReavorDamage - scrab damage    ����
	ProtossReavorCapacity  - increase reaver capacity  ����
	ProtossDisruptionWeb  ����
	ProtossCarrierCapacity  increase carrier capacity
	ProtossStatis   
	ProtossRecall 
	ProtossAirWeapons1 
	ProtossAirArmor1 
	ProtossAirWeapons2 
	ProtossAirArmor2 
	*/


	//������ �ڡ�


	//�� ���ֵ� ����ϱ�(����, ��󱺸�).
	//�١١��� ���ֵ� ���Ϸ� ����ϴ¼ҽ�.
	static int frametesttest=Broodwar->getFrameCount();
	//int en_id;
	if(Broodwar->getFrameCount() == frametesttest)  
	{
		//1�ʸ��� ���
		frametesttest = frametesttest + 3; //���߿� �������ֱ�.
		//������ ����ߴ��� ���� ���� ���� 
		int printed_num_enemy=0;
		for (std::set<BWAPI::Unit *>::const_iterator en = (*p2)->getUnits().begin(); en != (*p2)->getUnits().end(); ++en)
		{
			
			//�þ߿� ���̴� �͸� üũ�ϱ�����.
			if((*en)->isVisible(*p1) == false)
				continue;

			/*
			(Unit_ID, Type, X, Y), ..., Time  // Type -> �츮��: ���:-1, ���� : -2, ���� :��� -3, ���� -4,�츮�� = 36��, ���� = 36��, ���ֻ��̿��� -100�� ǥ����
			����, ��� ���ַ� �̰�, (�������÷�, ��Ʋ, ����, ������, ��ũ��)�� ������� ġȯ���� ����.
			*/

			if ((*en)->getType() == BWAPI::UnitTypes::Protoss_Dragoon && (*en)->isCompleted())//���������
			{
				fprintf(fp," %d %d %d %d %d %d -100",(*en)->getID(),-3,(*en)->getPosition().x(),(*en)->getPosition().y(),(*en)->getHitPoints() + (*en)->getShields(),(*en)->getOrder().getID());
				printed_num_enemy++;
			}
			if ((*en)->getType() == BWAPI::UnitTypes::Protoss_Zealot && (*en)->isCompleted())//�����������
			{				
				fprintf(fp," %d %d %d %d %d %d -100",(*en)->getID(),-4,(*en)->getPosition().x(),(*en)->getPosition().y(),(*en)->getHitPoints() + (*en)->getShields(),(*en)->getOrder().getID());
				printed_num_enemy++;
			}


			//Broodwar->getFrameCount()/24



		}
		/*
		//36����� ����� ���� �ʾ����� ������ �͵��� 0���� ä���ֱ�
		
		while(printed_num_enemy<36)
		{
			fprintf(fp," 0 0 0 0 0 0 -100");		
			printed_num_enemy++;
		}
		*/

		//�ð� ����ϱ�
		fprintf(fp," %d\n",Broodwar->getFrameCount());



	}



	//test
	//Broodwar->drawTextScreen(255,320,"%s", (double)(end.QuadPart - start.QuadPart) / (double)Frequency.QuadPart);










	//**����ϱ� ��...




	// �ð� ���� ���� ȭ�� ǥ�� ����--------------




	time_end(); 








	//chc ���÷��̿��� ��ó���ϱ� - �� - 


	if (show_visibility_data)
		drawVisibilityData();

	if (show_bullets)
		drawBullets();

	if (Broodwar->isReplay())
		return;

	drawStats();
	if (analyzed && Broodwar->getFrameCount()%30==0)
	{
		//order one of our workers to guard our chokepoint.
		for(std::set<Unit*>::const_iterator i=Broodwar->self()->getUnits().begin();i!=Broodwar->self()->getUnits().end();i++)
		{
			if ((*i)->getType().isWorker())
			{
				//get the chokepoints linked to our home region
				std::set<BWTA::Chokepoint*> chokepoints= home->getChokepoints();
				double min_length=10000;
				BWTA::Chokepoint* choke=NULL;

				//iterate through all chokepoints and look for the one with the smallest gap (least width)
				for(std::set<BWTA::Chokepoint*>::iterator c=chokepoints.begin();c!=chokepoints.end();c++)
				{
					double length=(*c)->getWidth();
					if (length<min_length || choke==NULL)
					{
						min_length=length;
						choke=*c;
					}
				}

				//order the worker to move to the center of the gap
				(*i)->rightClick(choke->getCenter());
				break;
			}
		}
	}
	if (analyzed)
		drawTerrainData();

	if (analysis_just_finished)
	{
		Broodwar->printf("Finished analyzing map.");
		analysis_just_finished=false;
	}
}

void ExampleAIModule::onSendText(std::string text)
{
	if (text=="/show bullets")
	{
		show_bullets = !show_bullets;
	} else if (text=="/show players")
	{
		showPlayers();
	} else if (text=="/show forces")
	{
		showForces();
	} else if (text=="/show visibility")
	{
		show_visibility_data=!show_visibility_data;
	} else if (text=="/analyze")
	{
		if (analyzed == false)
		{
			Broodwar->printf("Analyzing map... this may take a minute");
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AnalyzeThread, NULL, 0, NULL);
		}
	} else
	{
		Broodwar->printf("You typed '%s'!",text.c_str());
		//Broodwar->sendText("%s",text.c_str()); //chc
	}
}

void ExampleAIModule::onReceiveText(BWAPI::Player* player, std::string text)
{
	Broodwar->printf("%s said '%s'", player->getName().c_str(), text.c_str());
}

void ExampleAIModule::onPlayerLeft(BWAPI::Player* player)
{
	// Broodwar->sendText("%s left the game.",player->getName().c_str());
}

void ExampleAIModule::onNukeDetect(BWAPI::Position target)
{
	if (target!=Positions::Unknown)
		Broodwar->printf("Nuclear Launch Detected at (%d,%d)",target.x(),target.y());
	else
		Broodwar->printf("Nuclear Launch Detected");
}

void ExampleAIModule::onUnitDiscover(BWAPI::Unit* unit)
{
	if (!Broodwar->isReplay() && Broodwar->getFrameCount()>1)
		;
	// Broodwar->sendText("A %s [%x] has been discovered at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
}

void ExampleAIModule::onUnitEvade(BWAPI::Unit* unit)
{
	if (!Broodwar->isReplay() && Broodwar->getFrameCount()>1)
		;
	// Broodwar->sendText("A %s [%x] was last accessible at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
}

void ExampleAIModule::onUnitShow(BWAPI::Unit* unit)
{
	if (!Broodwar->isReplay() && Broodwar->getFrameCount()>1)
		;
	// Broodwar->sendText("A %s [%x] has been spotted at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
}

void ExampleAIModule::onUnitHide(BWAPI::Unit* unit)
{
	if (!Broodwar->isReplay() && Broodwar->getFrameCount()>1)
		;
	//Broodwar->sendText("A %s [%x] was last seen at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
}

void ExampleAIModule::onUnitCreate(BWAPI::Unit* unit)
{
	if (Broodwar->getFrameCount()>1)
	{
		if (!Broodwar->isReplay())
			;
		//  Broodwar->sendText("A %s [%x] has been created at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
		else
		{
			/*if we are in a replay, then we will print out the build order
			(just of the buildings, not the units).*/
			if (unit->getType().isBuilding() && unit->getPlayer()->isNeutral()==false)
			{
				int seconds=Broodwar->getFrameCount()/24;
				int minutes=seconds/60;
				seconds%=60;
				// Broodwar->sendText("%.2d:%.2d: %s creates a %s",minutes,seconds,unit->getPlayer()->getName().c_str(),unit->getType().getName().c_str());
			}
		}
	}
}

void ExampleAIModule::onUnitDestroy(BWAPI::Unit* unit)
{
	if (!Broodwar->isReplay() && Broodwar->getFrameCount()>1)
		Broodwar->sendText("A %s [%x] has been destroyed at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
}

void ExampleAIModule::onUnitMorph(BWAPI::Unit* unit)
{
	if (!Broodwar->isReplay())
		Broodwar->sendText("A %s [%x] has been morphed at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
	else
	{
		/*if we are in a replay, then we will print out the build order
		(just of the buildings, not the units).*/
		if (unit->getType().isBuilding() && unit->getPlayer()->isNeutral()==false)
		{
			int seconds=Broodwar->getFrameCount()/24;
			int minutes=seconds/60;
			seconds%=60;
			//Broodwar->sendText("%.2d:%.2d: %s morphs a %s",minutes,seconds,unit->getPlayer()->getName().c_str(),unit->getType().getName().c_str()); //chc
		}
	}
}

void ExampleAIModule::onUnitRenegade(BWAPI::Unit* unit)
{
	if (!Broodwar->isReplay())
		Broodwar->sendText("A %s [%x] is now owned by %s",unit->getType().getName().c_str(),unit,unit->getPlayer()->getName().c_str());
}

void ExampleAIModule::onSaveGame(std::string gameName)
{
	Broodwar->printf("The game was saved to \"%s\".", gameName.c_str());
}

DWORD WINAPI AnalyzeThread()
{
	BWTA::analyze();

	//self start location only available if the map has base locations
	if (BWTA::getStartLocation(BWAPI::Broodwar->self())!=NULL)
	{
		home       = BWTA::getStartLocation(BWAPI::Broodwar->self())->getRegion();
	}
	//enemy start location only available if Complete Map Information is enabled.
	if (BWTA::getStartLocation(BWAPI::Broodwar->enemy())!=NULL)
	{
		enemy_base = BWTA::getStartLocation(BWAPI::Broodwar->enemy())->getRegion();
	}
	analyzed   = true;
	analysis_just_finished = true;
	return 0;
}

void ExampleAIModule::drawStats()
{
	std::set<Unit*> myUnits = Broodwar->self()->getUnits();
	//Broodwar->drawTextScreen(5,0,"I have %d units:",myUnits.size());
	std::map<UnitType, int> unitTypeCounts;
	for(std::set<Unit*>::iterator i=myUnits.begin();i!=myUnits.end();i++)
	{
		if (unitTypeCounts.find((*i)->getType())==unitTypeCounts.end())
		{
			unitTypeCounts.insert(std::make_pair((*i)->getType(),0));
		}
		unitTypeCounts.find((*i)->getType())->second++;
	}
	int line=1;
	for(std::map<UnitType,int>::iterator i=unitTypeCounts.begin();i!=unitTypeCounts.end();i++)
	{
		// Broodwar->drawTextScreen(5,16*line,"- %d %ss",(*i).second, (*i).first.getName().c_str());
		line++;
	}
}

void ExampleAIModule::drawBullets()
{
	std::set<Bullet*> bullets = Broodwar->getBullets();
	for(std::set<Bullet*>::iterator i=bullets.begin();i!=bullets.end();i++)
	{
		Position p=(*i)->getPosition();
		double velocityX = (*i)->getVelocityX();
		double velocityY = (*i)->getVelocityY();
		if ((*i)->getPlayer()==Broodwar->self())
		{
			Broodwar->drawLineMap(p.x(),p.y(),p.x()+(int)velocityX,p.y()+(int)velocityY,Colors::Green);
			Broodwar->drawTextMap(p.x(),p.y(),"\x07%s",(*i)->getType().getName().c_str());
		}
		else
		{
			Broodwar->drawLineMap(p.x(),p.y(),p.x()+(int)velocityX,p.y()+(int)velocityY,Colors::Red);
			Broodwar->drawTextMap(p.x(),p.y(),"\x06%s",(*i)->getType().getName().c_str());
		}
	}
}

void ExampleAIModule::drawVisibilityData()
{
	for(int x=0;x<Broodwar->mapWidth();x++)
	{
		for(int y=0;y<Broodwar->mapHeight();y++)
		{
			if (Broodwar->isExplored(x,y))
			{
				if (Broodwar->isVisible(x,y))
					Broodwar->drawDotMap(x*32+16,y*32+16,Colors::Green);
				else
					Broodwar->drawDotMap(x*32+16,y*32+16,Colors::Blue);
			}
			else
				Broodwar->drawDotMap(x*32+16,y*32+16,Colors::Red);
		}
	}
}

void ExampleAIModule::drawTerrainData()
{
	//we will iterate through all the base locations, and draw their outlines.
	for(std::set<BWTA::BaseLocation*>::const_iterator i=BWTA::getBaseLocations().begin();i!=BWTA::getBaseLocations().end();i++)
	{
		TilePosition p=(*i)->getTilePosition();
		Position c=(*i)->getPosition();

		//draw outline of center location
		Broodwar->drawBox(CoordinateType::Map,p.x()*32,p.y()*32,p.x()*32+4*32,p.y()*32+3*32,Colors::Blue,false);

		//draw a circle at each mineral patch
		for(std::set<BWAPI::Unit*>::const_iterator j=(*i)->getStaticMinerals().begin();j!=(*i)->getStaticMinerals().end();j++)
		{
			Position q=(*j)->getInitialPosition();
			Broodwar->drawCircle(CoordinateType::Map,q.x(),q.y(),30,Colors::Cyan,false);
		}

		//draw the outlines of vespene geysers
		for(std::set<BWAPI::Unit*>::const_iterator j=(*i)->getGeysers().begin();j!=(*i)->getGeysers().end();j++)
		{
			TilePosition q=(*j)->getInitialTilePosition();
			Broodwar->drawBox(CoordinateType::Map,q.x()*32,q.y()*32,q.x()*32+4*32,q.y()*32+2*32,Colors::Orange,false);
		}

		//if this is an island expansion, draw a yellow circle around the base location
		if ((*i)->isIsland())
			Broodwar->drawCircle(CoordinateType::Map,c.x(),c.y(),80,Colors::Yellow,false);
	}

	//we will iterate through all the regions and draw the polygon outline of it in green.
	for(std::set<BWTA::Region*>::const_iterator r=BWTA::getRegions().begin();r!=BWTA::getRegions().end();r++)
	{
		BWTA::Polygon p=(*r)->getPolygon();
		for(int j=0;j<(int)p.size();j++)
		{
			Position point1=p[j];
			Position point2=p[(j+1) % p.size()];
			Broodwar->drawLine(CoordinateType::Map,point1.x(),point1.y(),point2.x(),point2.y(),Colors::Green);
		}
	}

	//we will visualize the chokepoints with red lines
	for(std::set<BWTA::Region*>::const_iterator r=BWTA::getRegions().begin();r!=BWTA::getRegions().end();r++)
	{
		for(std::set<BWTA::Chokepoint*>::const_iterator c=(*r)->getChokepoints().begin();c!=(*r)->getChokepoints().end();c++)
		{
			Position point1=(*c)->getSides().first;
			Position point2=(*c)->getSides().second;
			Broodwar->drawLine(CoordinateType::Map,point1.x(),point1.y(),point2.x(),point2.y(),Colors::Red);
		}
	}
}

void ExampleAIModule::showPlayers()
{
	std::set<Player*> players=Broodwar->getPlayers();
	for(std::set<Player*>::iterator i=players.begin();i!=players.end();i++)
	{
		Broodwar->printf("Player [%d]: %s is in force: %s",(*i)->getID(),(*i)->getName().c_str(), (*i)->getForce()->getName().c_str());
	}
}

void ExampleAIModule::showForces()
{
	std::set<Force*> forces=Broodwar->getForces();
	for(std::set<Force*>::iterator i=forces.begin();i!=forces.end();i++)
	{
		std::set<Player*> players=(*i)->getPlayers();
		Broodwar->printf("Force %s has the following players:",(*i)->getName().c_str());
		for(std::set<Player*>::iterator j=players.begin();j!=players.end();j++)
		{
			Broodwar->printf("  - Player [%d]: %s",(*j)->getID(),(*j)->getName().c_str());
		}
	}
}

void ExampleAIModule::onUnitComplete(BWAPI::Unit *unit)
{
	if (!Broodwar->isReplay() && Broodwar->getFrameCount()>1)
		Broodwar->sendText("A %s [%x] has been completed at (%d,%d)",unit->getType().getName().c_str(),unit,unit->getPosition().x(),unit->getPosition().y());
}
