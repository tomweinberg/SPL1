#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "../include/cyberdns.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "../include/cyberpc.h"
#include <boost/foreach.hpp>
using namespace boost::property_tree;
using namespace std;

class CyberPC;

CyberDNS::CyberDNS(){                      //Constructor
    ptree pt;                              // Creates a new tree structure like variable
    read_xml("computers.xml", pt);         // Reading the xml file into the tree structure   
    BOOST_FOREACH(ptree::value_type &computer, pt){            // for each computer (tag)...
	CyberPC* comp= new CyberPC(computer.second.get<string>("os"), computer.second.get<string>("name"));  //create a new computer (on the heap) object using the name and the os from the xml (now inside the tree)
	cout<<"Adding to server: "<<computer.second.get<string>("name")<<endl;
	AddPC(*comp);  // adds the pc to the hash map
    }
    ptree pt2;
    read_xml("network.xml", pt2);
    BOOST_FOREACH(ptree::value_type &wire, pt2){
	cout <<"connecting " << wire.second.get<string>("pointA") << " to " << wire.second.get<string>("pointB") <<endl;    
	GetCyberPC(wire.second.get<string>("pointA")).AddConnection(wire.second.get<string>("pointB"));
	cout <<"	"<<wire.second.get<string>("pointA") <<" is now connected to "<<wire.second.get<string>("pointB")<<endl;               
	GetCyberPC(wire.second.get<string>("pointB")).AddConnection(wire.second.get<string>("pointA"));
	cout <<"	"<<wire.second.get<string>("pointB") <<" is now connected to "<<wire.second.get<string>("pointA")<< endl;                
    }
}

void CyberDNS::AddPC(CyberPC & cyber_pc_){
  cyber_DNS_.insert ( pair<string, CyberPC &>(cyber_pc_.getName(),cyber_pc_) );
  cout <<cyber_pc_.getName() <<" connectd to server" <<endl;                                                                  
}

CyberPC & CyberDNS::GetCyberPC(const string & cyber_pc_name) const{
    return (cyber_DNS_.find(cyber_pc_name))->second;
}

vector<string> CyberDNS::GetCyberPCList(){
  vector<string> ret;
  for (map<const string,CyberPC &>::iterator it=cyber_DNS_.begin(); it!=cyber_DNS_.end(); ++it){
    ret.insert(ret.begin(), it->first);
  }
  return ret;
}


CyberDNS::~CyberDNS(){                                                                                           //DESTRUCTOR
  for(map<string,CyberPC &>::iterator it=cyber_DNS_.begin(); it!=cyber_DNS_.end(); ++it){
    delete &(it->second);
  }
  cyber_DNS_.clear();
}
  