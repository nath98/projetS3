#ifndef NODE_H
#define NODE_H

#include "component.h"
#include <vector>
#include <string>

class Node : public Component{
	public :
		Node(Node* predecessor, string name);
		~Node();
		void add_Node(string name);
		Node* get_node_list(string name);
		std::vector<string> get_list_name();
		string get_name();
		Node* get_predecessor();

	
	private:
		std::string m_name;
		Node* m_predecessor;
		std::vector<Node*> m_node;
		std::vector<File*> m_file;
};


#endif //NODE_FILE_H
