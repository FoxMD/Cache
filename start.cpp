#include <iostream>
#include "cache.h"
#include <vector>
#include <string>

int main()
{
    /* make it dynamic */
    Cache::CacheData SomeParsedData_1;
    Cache::CacheData SomeParsedData_2;
    Cache::CacheData SomeParsedData_3;

    SomeParsedData_1.category = "AI";
    SomeParsedData_1.subType = "Temperature";
    SomeParsedData_1.nc.m_Name = "Temperature 1";
    
    SomeParsedData_2.category = "AI";
    SomeParsedData_2.subType = "Temperature";
    SomeParsedData_2.nc.m_Name = "Temperature 2";

    SomeParsedData_3.category = "DI";
    SomeParsedData_3.subType = "Digital input";
    SomeParsedData_3.nc.m_Name = "DI1";

    /* then work with the dynamic Class */
    Cache::MyCache cache;
    cache.AddEntry(SomeParsedData_1);
    cache.AddEntry(SomeParsedData_2);
    cache.AddEntry(SomeParsedData_3);

    std::vector<std::string> keys{};
    cache.GetKeysFromCategory(keys);
    
    std::cout << std::endl << std::string{"//****** KEYS ******//"} << std::endl; 
    for(auto const& val : keys)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl << std::string{"//****** SUBKEYS in AI ******//"} << std::endl; 
    std::vector<std::string> subkeys{};
    cache.GetKeysFromSubCategory(subkeys, "AI");
    for(auto const& val : subkeys)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl << std::string{"//****** Nodes in AI/Temp ******//"} << std::endl; 
    std::vector<std::string> nodes{};
    cache.GetNodesFromSubCategory(nodes, "AI", "Temperature");
    for(auto const& val : nodes)
    {
        std::cout << val << std::endl;
    }
   
    return 0;
}