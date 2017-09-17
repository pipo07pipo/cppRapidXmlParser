#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
    cout << "Parsing" << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile ("artist.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	
	doc.parse<0>(&buffer[0]);
	xml_node<>* root = doc.first_node();
	std::cout << "Root node is: " << doc.first_node()->name() << "\n";
    for(xml_node<>* iroot = root->first_node("Artist"); iroot ; iroot = iroot->next_sibling()){
        cout << "Artist" << "\n";
        for(xml_node<>* node = iroot->first_node("name"); node ; node = node->next_sibling()){
        if(node->name() == iroot->first_node("album")->name()){
            std::cout << "--------------------------\n";
            std::cout << "Tag : " << node->name()<< "\n";
            std::cout << "                          \n";
            for(xml_node<>* inode = node->first_node("song"); inode ; inode = inode->next_sibling()){
                std::cout << "Tag : " << inode->name()<< "\n";
                std::cout << "Song name :" << inode->first_attribute("name")->value() << "\n";
                std::cout << "Song id :" << inode->first_attribute("id")->value() << "\n";
                std::cout << "Song length :" << inode->first_attribute("length")->value() << "\n";
                std::cout << "Song melody :" << inode->first_attribute("melody")->value() << "\n";
                std::cout << "Song lyrics :" << inode->first_attribute("lyrics")->value() << "\n";
                std::cout << "                          \n";
            }
        }
        else if(node->name() == iroot->first_node("award")->name()){
            std::cout << "--------------------------\n";
            std::cout << "Tag : " << node->name()<< "\n";
        
            for(xml_node<>* inode = node->first_node("description"); inode ; inode = inode->next_sibling()){
                std::cout << "Tag : " << inode->name()<< "\n";
                std::cout << "Award Description :" << inode->value() << "\n";
            }
        }
        else{
            std::cout << "--------------------------\n";
            std::cout << "Tag : " << node->name()<< "\n";
            std::cout << "Tag Value : " << node->value() << "\n";
        }
        }
    }
}