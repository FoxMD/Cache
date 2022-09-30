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

    class Node
    {
        friend class LinkedList;
        private:
            NodeContent m_Content;   
            Node *next;
            Node *previous; 
            Node();
            ~Node();
    };

    class LinkedList
    {
        private:
            Node *pHead;
            Node *pTail;
            void prepareNext(Node *pNode);
            void destructNodes();
        public:
            LinkedList();
            LinkedList(const LinkedList &old_obj);
            LinkedList(LinkedList &&old_obj);
            ~LinkedList();
            LinkedList& operator=(const LinkedList&);
            LinkedList& operator=(LinkedList&&);
            void setValues(const NodeContent& nc);
            void addNode(NodeContent nc);
            void printForward(Node *head);
            void printBackwards(Node *tail);
            void removeLastNode();
            Node* start();
    }; 
};