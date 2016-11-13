#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberworm.h"
using namespace std;

 
 
CyberWorm::CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time): cyber_worm_os_(cyber_worm_os), cyber_worm_name_(cyber_worm_name), cyber_worm_dormancy_time_(cyber_worm_dormancy_time){}

CyberWorm::CyberWorm(const CyberWorm& other):cyber_worm_os_(other.cyber_worm_os_), cyber_worm_name_(other.cyber_worm_name_),cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_){}

const int CyberWorm::getDT() const{                              
  return cyber_worm_dormancy_time_;
}



const string CyberWorm::getOS() const{                          
  return cyber_worm_os_;
}

const string CyberWorm::getName() const{                           
  return cyber_worm_name_;
}



  