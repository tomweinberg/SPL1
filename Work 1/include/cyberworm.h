#ifndef CYBER_WORM
#define CYBER_WORM
#include <iostream>
#include <string>
#include <vector>


class CyberWorm
{
private:
    const std::string 	cyber_worm_os_;
    const std::string 	cyber_worm_name_;
    const int 	cyber_worm_dormancy_time_;
    CyberWorm(); // Prevent the use of an empty constructor
	// Add your variables here
 
public:
    CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time);
	CyberWorm(const CyberWorm& other); //copy constructor;
	// Add your own functions here
	const int getDT() const;
	const std::string getOS() const;
	const std::string getName() const;
};


#endif