#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

//----------------------------------------------------------------------------
class Node
{
public:
	Node(int id);

	void Add_Node_To_Network(int count);
	void Add_Neighbor(int k);
	void Show_Network_Elements();
	void Show_Network_Size();
	void Show_Neighbor_Elements();
	void Update_Network();

	int Rand = rand();
	int Data, Id;

	static const int Nodes_Count;

private:
	deque<Node*> Neighbors;
	deque<Node*> Network;
};
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
bool Sort_Bool(const Node* n_1, const Node* n_2)
{
	return n_1->Id < n_2->Id;
}
//----------------------------------------------------------------------------




// Node
//----------------------------------------------------------------------------
Node::Node(int id)
{
	Id = id;
	Data = Rand;
}
//----------------------------------------------------------------------------
const int Node::Nodes_Count = 39;
//----------------------------------------------------------------------------
void Node::Add_Node_To_Network(int count)
{
	for (int i = 0; i < count; ++i)
	{
		Network.push_back(new Node(i));
	}
}
//----------------------------------------------------------------------------
void Node::Add_Neighbor(int k)
{
	Neighbors.push_back(Network.at(k));
}
//----------------------------------------------------------------------------
void Node::Show_Network_Elements()
{
	for (int i = 0; i < Network.size(); ++i)
	{
		cout << "Node " << Network[i]->Id << endl;
		cout << "Data = " << Network[i]->Data << endl << endl;
	}
}
//----------------------------------------------------------------------------
void Node::Show_Network_Size()
{
	cout << "Network Size = " << Network.size() << endl << endl;
}
//----------------------------------------------------------------------------
void Node::Show_Neighbor_Elements()
{
	for (int i = 0; i < Neighbors.size(); ++i)
	{
		cout << "Node " << Neighbors[i]->Id << endl;
		cout << "Data = " << Neighbors[i]->Data << endl << endl;
	}
}
//----------------------------------------------------------------------------
void Node::Update_Network()
{
	std::sort(Network.begin(), Network.end(), Sort_Bool);
	std::sort(Neighbors.begin(), Neighbors.end(), Sort_Bool);

	auto it = Network.begin();
	auto ne_it = Neighbors.begin();

	while (it != Network.end() && ne_it != Neighbors.end())
	{
		if ((*it)->Id < (*ne_it)->Id)
		{
			it = Network.erase(it);
		}
		else if ((*it)->Id > (*ne_it)->Id)
		{
			ne_it++;
		}
		else
		{
			it++;
			ne_it++;
		}
	}
	Network.erase(it, Network.end());
}
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
int main()
{
	Node node(1);

	node.Add_Node_To_Network(Node::Nodes_Count);
	node.Show_Network_Size();
	node.Show_Network_Elements();

	node.Add_Neighbor(17);
	node.Add_Neighbor(2);
	node.Add_Neighbor(12);
	node.Add_Neighbor(14);
	node.Add_Neighbor(0);
	node.Add_Neighbor(18);
	node.Add_Neighbor(11);
	node.Add_Neighbor(7);
	node.Add_Neighbor(20);
	node.Add_Neighbor(15);
	node.Add_Neighbor(24);
	node.Add_Neighbor(28);

	node.Show_Network_Size();

	node.Update_Network();

	node.Show_Network_Elements();
	node.Show_Network_Size();

	return 0;
}
//----------------------------------------------------------------------------


