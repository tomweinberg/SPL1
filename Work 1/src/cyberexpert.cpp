#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberexpert.h"
#include "../include/cyberpc.h"

using namespace std;






 CyberExpert::CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_): cyber_expert_name_(cyber_expert_name_),cyber_expert_work_time_(cyber_expert_work_time_),cyber_expert_rest_time_(cyber_expert_rest_time_),cyber_expert_efficiency_(cyber_expert_efficiency_){
       number_of_days_rest=0;
       number_of_days_working=0;
}
    void CyberExpert::Clean(CyberPC & cyber_pc)
      {
	if(number_of_days_working<=cyber_expert_work_time_)//see if the expert work less then the work time
	  {
	    cyber_pc.Disinfect();//clean the pc with fun in the pc.
	  }
	  
      }
     bool CyberExpert:: WorkOrRest()//if the work can work "today" return true else he need to rest ,return false.
	  {
	      if(number_of_days_working<cyber_expert_work_time_){
		NumberOfDaysWorking();
		return true;
	      }
	      else{
		if(number_of_days_rest == cyber_expert_rest_time_-1){
		  cout<<"	"<< cyber_expert_name_<< " is back to work"<<endl;
		}
		NumberOfDaysRest();
		
		return false;
	      }
	   }
  

  
    void CyberExpert:: NumberOfDaysWorking()//add one day to the number of expert work
	  {
		number_of_days_working++;
	  }
  
 
  
    void CyberExpert:: NumberOfDaysRest()
	{
	    number_of_days_rest++;//add one to the number of the rest and that it
	    if(number_of_days_rest==cyber_expert_rest_time_)//if he finish to rest enter zero to the day rest the he did and the number of days he work.
		  {
			number_of_days_rest=0;
			number_of_days_working=0;
		   }
	}
    int CyberExpert:: GetExpertEffiency() const//return the expert Expert Effiency
	  {
		  return cyber_expert_efficiency_;
	   }
	   
    const int CyberExpert:: getWorkingDays() const{
      return number_of_days_working;
    }
    
    const int CyberExpert:: getExpertTime() const{
      return cyber_expert_work_time_;
    }
    
    const string CyberExpert::getName() const{
      return cyber_expert_name_;
    }
      
      
  
