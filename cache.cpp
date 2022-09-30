#include "cache.h"
using namespace Cache;

MyCache::MyCache(/* args */)
{
}
    
MyCache::~MyCache()
{
}

void MyCache::AddEntry(const CacheData& cd)
{
    if (m_Cache.find(cd.category) == m_Cache.end()) {
        std::cout << "Key does'n exist" << std::endl;
    } else {
        std::cout << "Key does exist" << std::endl;
    }


    std::list<SubType::NodeContent> lnc;
    lnc.push_back(cd.nc); 
    std::pair<std::string, std::list<SubType::NodeContent>>temp{cd.subType, lnc}; 
    std::map<std::string, std::list<SubType::NodeContent>> tempValue{temp};
    std::pair<std::string, std::map<std::string, std::list<SubType::NodeContent>>> tmp{cd.category, tempValue};
    m_Cache.insert(tmp);
    std::cout << cd.nc.m_Name << std::endl;
    // std::pair<std::string, std::map<int, int>>(cd.subType, std::pair<int, int>(cd.nc.m_Value, cd.nc.m_DefaultValue))
    std::cout << cd.category << std::endl;
    std::cout << cd.nc.m_Name << std::endl;
    
    SubType::NodeContent* nc = new SubType::NodeContent;
    for(auto & [key, value] : m_Cache[cd.category])
    {
        for(std::list<SubType::NodeContent>::iterator it = value.begin(); it != value.end(); it++) {
            std::cout << "item: " << (it)->m_Value << " str: " << (it)->m_Name << std::endl;
        }
    }
}

void MyCache::GetKeysFromCategory(std::vector<std::string>& keys)
{
    for(auto const& [key, value] : m_Cache)
    {
        keys.emplace_back(key);
    }
}

void MyCache::GetKeysFromSubCategory(std::vector<std::string>& keys, const std::string key)
{
    for(auto const& [key, value] : m_Cache[key])
    {
        keys.emplace_back(key);
    }
}
/*
void MyCache::GetNodesFromSubCategory(std::vector<std::string>& keys, const std::string key, const std::string key2)
{
    for(auto const& [key, value] : m_Cache[key])
    {
        keys.emplace_back(value);
    }
}
*/