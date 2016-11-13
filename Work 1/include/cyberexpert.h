#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"


class CyberExpert
{
private:
	const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    CyberExpert(); // Prevent the use of an empty constructor
	// Add your own variables here
    int number_of_days_rest;
    int number_of_days_working;
 
public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc); 
	// Add your own functions here
	bool WorkOrRest();
	void NumberOfDaysWorking();
	void NumberOfDaysRest();
	int GetExpertEffiency() const;
	const int getWorkingDays() const;
	const int getExpertTime() const;
	const std::string getName() const;
};


#endif