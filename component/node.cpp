#include "node.h"

Node::Node(Node* predecessor, string name): m_name(name), m_predecessor(predecessor){

}

Node::~Node(){
	for(int i= 0; i<m_node.size(); i++){
		delete m_node[i];
	}	
}

void Node::add_Node(string name){
	bool dont_exist = true;
	for(int i = 0; i<m_node.size(); i++){
		if(name == m_node[i]->get_name()){
			dont_exist = false;
		}
	}
	if(dont_exist){
		m_node.push_back(new Node(this, name));
	}
}

string Node::get_name(){
	return m_name;
}

Node* Node::get_predecessor(){
	return m_predecessor;
}

std::vector<string> Node::get_list_name(){
	std::vector<string> name_list;
	for(int i = 0; i<m_node.size(); i++){
		name_list.push_back(m_node[i]->get_name());
	}
	return name_list;
}
