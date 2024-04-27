#include <iostream>
#include <vector>  
#include <string.h>
#include <map>



using namespace std;

class dataManager
{
    private:
    bool start = false;
    bool commited = false;

    map<string, int> storage;


    public:

    int get(string key);
    void begin_transaction();
    void put(string key,int value);
    void commit();
    void rollback();

};


void dataManager::begin_transaction()
{
    start = true;
    
}

void dataManager::put(string key,int value)
{
    if(start == true)
    {
        storage[key] = value;
        
    }
    else
    {
        cout<<"transaction is not in progress"<<endl;
    }
}

 int dataManager::get(string key)
 {
    if(commited == true){
    auto findElement = storage.find(key);
    
    if(findElement != storage.end())
    {
        return findElement->second;
    }
    
    }
    return -1;
    

 }

// will clear all changes 
 void dataManager::rollback()
 {
    if(start == true)
    {
    storage.clear();
    }
    else
    {
         cout<<"transaction is not in progress"<<endl;
    }

 }

  void dataManager::commit(){

    if(start == true)
    {
    commited = true;
    start = false;
    }
    else
    {

         cout<<"transaction is not in progress"<<endl;
    }
  }
int main()
{
    dataManager object;

    object.begin_transaction();

    object.put("transaction 1", 15);
    
    object.commit();
    cout<<object.get("transaction 1")<<endl;
    object.rollback();
    object.put("transaction 1", 7);
    cout<<object.get("transaction 1")<<endl;


    

   
    return 0;

}