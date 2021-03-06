#ifndef modConMan__h
#define modConMan__h
#include "module.h"


struct signalSlotKey{
  unsigned int ID = 0;
  std::string Name = "";
  bool operator == (const signalSlotKey& otherSignalSlotKey) const
  {
    return(
      this->ID        ==    otherSignalSlotKey.ID   &&
      this->Name  ==    otherSignalSlotKey.Name
    );
  }
  bool operator < (const signalSlotKey& otherSignalSlotKey) const
  {
    return(
      (this->ID <   otherSignalSlotKey.ID)    ||
      (this->ID ==  otherSignalSlotKey.ID   &&  this->Name  <  otherSignalSlotKey.Name)
    );
  }
};
class ModConMan{
public:
  ModConMan(std::string host, unsigned int port, std::string user, std::string pw, std::string db);
protected:
  //void getDelta();
  void putConnectionDataToCache();
  void createAllModules();
  void createModules(const std::map<unsigned int, unsigned int>& constructionMap);//first:ID, second:ModuleType
  void makeConnectionsFromCache();
  void makeConnection(mySqlSignal, signalSlotKey);
  void makeConnection(signalSlotKey, signalSlotKey);
  void makeConnection(signalSlotKey, mySqlSignal);
  void makeConnection(unsigned int, signalSlotKey);
  void makeConnection(signalSlotKey, unsigned int);
  void makeConnection(mySqlSignal, unsigned int);
  std::map<unsigned int, Module*> m_modulesMap;
  std::map<signalSlotKey, mySqlSignal> m_routingInMap;
  std::map<signalSlotKey, signalSlotKey> m_routingInternalMap;
  std::map<mySqlSignal, signalSlotKey> m_routingOutMap;
  std::map<signalSlotKey, unsigned int> m_routingSoftwareButtonsMap;
  std::map<unsigned int, signalSlotKey> m_routingSoftwareMonitorsInternalMap;
  std::map<unsigned int, mySqlSignal> m_routingSoftwareMonitorsIoMap;
  mysqlcon* mySqlConnection = nullptr;

};
#endif
