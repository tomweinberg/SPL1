#include "../include/cyberworm.h"
#include "../include/cyberdns.h"
#include "../include/cyberworm.h"
#include"../include/cyberpc.h"
#include <iostream>
#include <string>
using namespace std;


class CyberDNS; // Forward decleration
class CyberWorm;


	CyberPC::CyberPC(string cyber_pc_os, string cyber_pc_name): cyber_pc_os_(cyber_pc_os),cyber_pc_name_(cyber_pc_name), cyber_pc_time_to_infect_(0), printedDormant(false){} ////////////////////////////////////
	
	const string CyberPC::getName() 
	  {
	    return cyber_pc_name_;
	  }
	  
	  
	void CyberPC::AddConnection(string  second_pc)// Add a connection to this PC
	{
	  cyber_pc_connections_.push_back(second_pc);
	  
	}
	
	
	void CyberPC::Infect(CyberWorm & worm)	// Add a worm to this PC
	{
	  
	  if(cyber_pc_os_ == worm.getOS()){                //check if the OS is compitable with the worm (for PC infecting one another).
	    if(cyber_worm_ != NULL){
	      delete cyber_worm_;  
	    }
	    cyber_worm_= new CyberWorm(worm);  
	    cout<< "		"<<cyber_pc_name_<<" infected by "<<worm.getName()<<endl;
	    cyber_pc_time_to_infect_ = worm.getDT();
	    if(cyber_pc_time_to_infect_>0){
	      printedDormant=false;
	    }
	  }
	  else{
	    cout<<"		Worm "<<worm.getName()<<" is incompatible with "<< cyber_pc_name_<<endl;
	  }
	}
	
	
	void CyberPC::Run(const CyberDNS & server)// Activate PC and infect others if worm is active
	{
	  if(cyber_worm_!=NULL && cyber_pc_time_to_infect_==0)                                 
	  {
	   if(cyber_pc_connections_.size() > 0){                //if there are any pc connections
	     cout<<"	"<< cyber_pc_name_<< " infecting..."<<endl;
	    for(int i(0);(unsigned)i<(cyber_pc_connections_).size();i++)           //While there are still pc connections..
	    {
	      (server.GetCyberPC(cyber_pc_connections_[i])).Infect(*cyber_worm_);     //go to the server and find the pc and then infect the pc with the same worm
	    }
	   }
	  }
	  
	  else if(!printedDormant && cyber_pc_time_to_infect_ > 0){
	    
	      cout<<"	"<<cyber_pc_name_<<": Worm "<< (*cyber_worm_).getName()<<" is dormant"<<endl;
	      printedDormant=true;
	      if(cyber_pc_time_to_infect_ > 0){
		cyber_pc_time_to_infect_--;
	      }
	  }
	  
	}
	
	
	void CyberPC::Disinfect()// called by cyber expert, disinfect PC
	{
	  if(cyber_worm_ != NULL){
	    cout<< "		Worm "<< (*cyber_worm_).getName()<< " successfully removed from "<<cyber_pc_name_<<endl;
	    delete cyber_worm_;                                             
	    cyber_worm_=NULL;
	    cyber_pc_time_to_infect_=0;
	  }
	}
	
	const string CyberPC:: getOs() const{           //returns the OS of that computer
	  return cyber_pc_os_;
	}
	
	CyberPC::~CyberPC(){                    //DESTRUCTOR
	  delete cyber_worm_;                       
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	