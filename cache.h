#pragma once
#include "linkedList.h"
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

namespace Cache
{
    struct CacheData
    {
        std::string category;
        std::string subType;
        SubType::NodeContent nc;
    };

    class MyCache
    {
        private:
            /*Category, vector of subs*/ 
            //std::map<std::string, std::map<std::string, SubType::LinkedList>> m_Cache;     
            std::map<std::string, std::map<std::string, std::list<SubType::NodeContent>>> m_Cache;      
        public:
            MyCache(/* args */);
            ~MyCache();
            void AddEntry(const CacheData& cd);
            void GetKeysFromCategory(std::vector<std::string>& keys);
            void GetKeysFromSubCategory(std::vector<std::string>& keys, const std::string key);
            void GetNodesFromSubCategory(std::vector<std::string>& keys, const std::string key, const std::string key2);
    };
        
};