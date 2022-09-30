#include "linkedList.h"
using namespace SubType;

LinkedList::LinkedList()
{
    Node *pNode = new Node();
    pNode->m_Content.m_DataType = "i16";
    pNode->m_Content.m_DefaultValue = 0.0;
    pNode->m_Content.m_Value = 0.0;
    pNode->m_Content.m_Name = "None";
    pNode->m_Content.m_SpirtcomID = "0x0000";
    pNode->m_Content.m_USBID = "0x0000";
    
    pNode->next = nullptr;
    pNode->previous = nullptr;

    pHead = pNode;
    pTail = pNode;
}

void LinkedList::destructNodes()
{
    Node *pTravers = pTail;
    Node *pTemp = pTail;
    while(pTravers != nullptr)
    {
        pTravers->next = nullptr;
        pTemp = pTravers->previous;
        delete pTravers;
        pTravers = pTemp;
    }
    delete pTemp;
    std::cout << "Destructed temporary" << std::endl;
}

void LinkedList::removeLastNode()
{
    Node *pTravers = pTail->previous;
    std::cout << "Removed: " << pTail->m_Content.m_Name << std::endl;
    delete pTail;
    pTravers->next = nullptr;
    pTail = pTravers;
}

LinkedList::~LinkedList()
{
    destructNodes();
    std::cout << "Destructed List" << std::endl;
}

void LinkedList::prepareNext(Node *pNode)
{
    pNode->next = nullptr;
    pNode->previous = pTail;
    pTail->next = pNode;
    pTail = pNode;
}

Node *LinkedList::start()
{
    return pHead;
}

Node::Node(/* args */)
{
    std::cout << "Created node @" << this << std::endl;
}

Node::~Node()
{
    this->m_Content.m_DataType = "i16";
    this->m_Content.m_DefaultValue = 0.0;
    this->m_Content.m_Value = 0.0;
    this->m_Content.m_Name = "None";
    this->m_Content.m_SpirtcomID = "0x0000";
    this->m_Content.m_USBID = "0x0000";
    this->next = nullptr;
    std::cout << "Destructed Node @" << this << std::endl;
}


void LinkedList::setValues(const NodeContent& nc)
{
    pTail->m_Content.m_DataType = nc.m_DataType;
    pTail->m_Content.m_DefaultValue = nc.m_DefaultValue;
    pTail->m_Content.m_Value = nc.m_Value;
    pTail->m_Content.m_Name = nc.m_Name;
    pTail->m_Content.m_SpirtcomID = nc.m_SpirtcomID;
    pTail->m_Content.m_USBID = nc.m_USBID;
}

void LinkedList::addNode(NodeContent nc)
{
    Node *pNode = new Node();
    pNode->m_Content.m_DataType = nc.m_DataType;
    pNode->m_Content.m_DefaultValue = nc.m_DefaultValue;
    pNode->m_Content.m_Value = nc.m_Value;
    pNode->m_Content.m_Name = nc.m_Name;
    pNode->m_Content.m_SpirtcomID = nc.m_SpirtcomID;
    pNode->m_Content.m_USBID = nc.m_USBID;
    prepareNext(pNode);
} 

void LinkedList::printForward(Node *head)
{
    Node *pTravers = head;
    while(pTravers != nullptr)
    {
        std::cout << pTravers->m_Content.m_Name << std::endl;
        pTravers = pTravers->next;
    }
}

void LinkedList::printBackwards(Node *tail)
{
    Node *pTravers = tail;
    while(pTravers != nullptr)
    {
        std::cout << pTravers->m_Content.m_Name << std::endl;
        pTravers = pTravers->previous;
    }
}