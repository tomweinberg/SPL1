#include "../include/cyberpc.h"
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::property_tree;

class CyberDNS;
class CyberPC;
class CyberExpert;


void RunDay(CyberDNS& server);


vector<CyberExpert*> expertList;
                                             

//The Main
int main(){
  CyberDNS server;
  ptree pt;
  read_xml("events.xml", pt);
  
  int termination = pt.get<int>("termination.time");
  int dayCounter(0);
  

  BOOST_FOREACH(ptree::value_type &event, pt){
    if(dayCounter <= termination){
      cout<<"Day : "<<dayCounter<<endl;
      if(event.first == "hack"){
	string pcName = event.second.get<string>("computer");
	if(event.second.get<string>("wormOs") == (server.GetCyberPC(pcName).getOs())){   //checks if the wrom's OS is the same as the computer it wants to infect.
	  cout<< "	Hack occured on "<<pcName<<endl; 
	  CyberWorm worm(event.second.get<string>("wormOs"), event.second.get<string>("wormName"), event.second.get<int>("wormDormancy"));                //creates the worm. 
	  server.GetCyberPC(event.second.get<string>("computer")).Infect(worm);   //infects the computer.
	}
      }
  
      else if(event.first == "clock-in"){
	CyberExpert* ex= new CyberExpert(event.second.get<string>("name"), event.second.get<int>("workTime"), event.second.get<int>("restTime"), event.second.get<int>("efficiency"));   
	expertList.push_back(ex);
	cout<<"	-In: "<<event.second.get<string>("name")<<" clocked in"<<endl;
      }
    
      RunDay(server);
      dayCounter++;
    }
  }
  
   while(dayCounter <= termination){
     cout<<"Day : "<<dayCounter<<endl;
     RunDay(server);
     dayCounter++;
   }
  for (vector<CyberExpert*>::iterator it=expertList.begin(); it!=expertList.end(); ++it){                  //Deletes all of our experts   
     delete *(it);
  } 

  return 0;
}




//RunDay : Simulates a days' run.
void RunDay(CyberDNS& server){
  int currPc(0);
  vector<string> pcs=(server.GetCyberPCList());
  for(int i=0; (unsigned)i<expertList.size(); i++){    //Calls the experts to clean PCs
    bool possible = (expertList[i])->WorkOrRest();
    if(possible){
      for(int j=0; j<(expertList[i])->GetExpertEffiency(); j++){         //While the expert can work...
	if((unsigned)currPc<pcs.size()){                                 //and there are PCs left to check
	  cout<<"	"<<(expertList[i])->getName()<<" examining "<<pcs[currPc]<<endl;
	  expertList[i]->Clean(server.GetCyberPC(pcs[currPc]));           //check and if neccessery- clean them.
	  currPc++;
	}
	else{
	  break;
	}
      }
      if((expertList[i])->getWorkingDays() == (expertList[i])->getExpertTime()){
	 cout<<"	"<<(expertList[i])->getName()<<" is taking a break"<<endl;
      }
    }
  }
  for(int i(0); (unsigned)i<pcs.size(); i++){           //Runs the PCs
      (server.GetCyberPC(pcs[i])).Run(server);
  }
}
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  