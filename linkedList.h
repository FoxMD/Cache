#pragma once
#include <iostream>
#include <string>

namespace SubType
{
    struct NodeContent
    {
        std::string m_Name;
        std::string m_USBID;
        std::string m_SpirtcomID;
        double m_Value;
        double m_DefaultValue;
        std::string m_DataType;
        float m_NewFloat;
    };
};