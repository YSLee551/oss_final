#include <iostream>
#include <fstream>
#define TOTAL_TICKET 100
#define TICKET_PRICE 3500
using namespace std;

//Ticket Sales Management Program
class bst_node
{
public:
	string name;
	string s_id;
	string phone_num;
	char paid;
	int ticket;
	bst_node *left, *right;
	bst_node();
	void set_data(string n, string id, string p_num, char e, int t);
};
bst_node::bst_node()
{
	name = "No Data";
	s_id = "00000000";
	phone_num = "010-xxxx-xxxx";
	paid = 'x';
	left = NULL;
	right = NULL;
}
void bst_node::set_data(string n, string id, string p_num, char e, int t)
{
	name = n;
	s_id = id;
	phone_num = p_num;
	paid = e;
	ticket = t;
}

class bst_tree
{
	bst_node *root;
	int tsize;

public:
	bst_tree();
	void insert_node(bst_node tnode);
	void show_inorder();
	void file_out_inorder(string file);
	bst_node *search(string key_id);
	int ticket_sum();
	int sales_sum();
	int get_size();
};
bst_tree::bst_tree()
{
	root = NULL;
	tsize = 0;
}
int bst_tree::get_size()
{
	return tsize;
}
void bst_tree::insert_node(bst_node tnode)
{
	bst_node *p; //pointer to follow
	p = root;

	bst_node *new_node;
	new_node = new bst_node;
	*new_node = tnode;

	if (root == NULL)
	{
		root = new_node;
		tsize++;
		cout << "\n<" << new_node->name << "> added to the list!\n\n";
		return;
	}
	while (1)
	{
		if (p->s_id == new_node->s_id)
		{
			cout << "\n**Input Error**\n"
				 << new_node->s_id << " already exist.\n\n";
			return;
		}
		else if (p->s_id < new_node->s_id)
		{
			if (p->right == NULL)
			{
				p->right = new_node;
				tsize++;
				cout << "\n<" << new_node->name << "> added to the list!\n\n";
				return;
			}
			else
				p = p->right;
		}
		else
		{
			if (p->left == NULL)
			{
				p->left = new_node;
				tsize++;
				cout << "\n<" << new_node->name << "> added to the list!\n\n";
				return;
			}
			else
				p = p->left;
		}
	}
}
void inorder_traverse(bst_node *p)
{
	if (p == NULL)
		return;
	inorder_traverse(p->left);
	cout << p->name << " : " << p->s_id << " : " << p->phone_num << " : " << p->ticket << " : " << p->paid << endl;
	inorder_traverse(p->right);
}
void bst_tree::show_inorder()
{
	if (root == NULL)
	{
		cout << "The list is EMPTY.\n\n";
		return;
	}
	inorder_traverse(root);
	return;
}
void file_out_inorder_traverse(bst_node *p, ofstream &filestream)
{
	if (p == NULL)
		return;
	file_out_inorder_traverse(p->left, filestream);
	filestream << p->name << " " << p->s_id << " " << p->phone_num << " " << p->ticket << " " << p->paid << endl;
	file_out_inorder_traverse(p->right, filestream);
}
void bst_tree::file_out_inorder(string file)
{
	if (root == NULL)
	{
		cout << "The list is EMPTY.\n\n";
		return;
	}
	ofstream write_file;
	write_file.open(file);
	file_out_inorder_traverse(root, write_file);
	cout << "\nSave Completed in [" << file << "]\n\n";
	write_file.close();
	return;
}
bst_node *bst_tree::search(string key_id)
{
	bst_node *p;
	p = root;
	bst_node *empty = new bst_node;

	if (root == NULL)
	{
		cout << endl
			 << key_id << " doesn't exist.\n\n";
		return empty;
	}
	while (1)
	{
		if (p->s_id == key_id)
		{
			free(empty);
			return p;
		}
		else if (p->s_id < key_id)
		{
			if (p->right == NULL)
			{
				cout << endl
					 << key_id << " doesn't exist.\n\n";
				return empty;
			}
			else
				p = p->right;
		}
		else
		{
			if (p->left == NULL)
			{
				cout << endl
					 << key_id << " doesn't exist.\n\n";
				return empty;
			}
			else
				p = p->left;
		}
	}
}
int ticket_traverse_sum(bst_node *p)
{
	if (p == NULL)
		return 0;
	return ticket_traverse_sum(p->left) + p->ticket + ticket_traverse_sum(p->right);
}
int bst_tree::ticket_sum()
{
	if (root == NULL)
		return 0;
	return ticket_traverse_sum(root);
}
int sales_traverse_sum(bst_node *p)
{
	int price = 0;
	if (p == NULL)
		return 0;
	if (p->paid == 'x')
		price = 0;
	else
		price = ((p->ticket) * TICKET_PRICE);
	return sales_traverse_sum(p->left) + sales_traverse_sum(p->right) + price;
}
int bst_tree::sales_sum()
{
	if (root == NULL)
		return 0;
	return sales_traverse_sum(root);
}

int main()
{
	int input;
	bst_node temp;
	bst_tree tree;
	char blank;

	string filename = "ticket_list.txt";

	cout << "[[Ticket Sales Management Program]]\nMade by. Yongseok Lee\n\n";

	cout << "Enter the name of your list file >> ";
	cin >> filename;

	ifstream read_file(filename);
	if (read_file.is_open())
	{

		while (!read_file.eof())
		{
			if ((read_file >> temp.name).fail())
				break;
			read_file >> temp.s_id >> temp.phone_num >> temp.ticket >> temp.paid;
			tree.insert_node(temp);
		}
		read_file.close();
	}
	else
		cout << "Unable to open file. Starting the program without data.\n\n";

	while (1)
	{
		cout << "=============[Menu]=============\n"
			 << "1. View List\n"
			 << "2. Add New Reservation\n"
			 << "3. Search With ID\n"
			 << "4. Edit Reservation Info\n"
			 << "5. Sales Status\n"
			 << "6. Last Update\n"
			 << "7. Save\n"
			 << "8. Exit\n"
			 << "================================\n"
			 << "Enter a number >> ";
		cin >> input;
		cout << endl;

		if (input == 1)
		{ //View List

			cout << "[View List]\n"
				 << "    Name    :    ID    :     Phone #     : # of T : Paid\n"
				 << "--------------------------------------------------------\n";
			tree.show_inorder();
			cout << endl
				 << "# of total sold tickets: " << tree.ticket_sum() << endl
				 << endl;
			continue;
		}
		if (input == 2)
		{ //Add New Reservation
			string input_name = "No Data";
			string input_id = "00000000";
			string input_pnum = "010-xxxx-xxxx";
			char input_paid = 'x';
			int input_ticket = 0;

			cout << "[Add New Reservation]\n";
			cout << "Name >> ";
			cin >> input_name;
			cout << "Student ID (8 digits) >> ";
			cin >> input_id;
			cout << "Phone number (010-xxxx-xxxx) >> ";
			cin >> input_pnum;
			cout << "Number of Tickets >> ";
			cin >> input_ticket;
			cout << "Paid (o/x) >> ";
			cin >> input_paid;

			temp.set_data(input_name, input_id, input_pnum, input_paid, input_ticket);

			tree.insert_node(temp);

			continue;
		}
		if (input == 3)
		{ //Search With ID
			bst_node *search_node;
			string search_id;

			if (tree.get_size() == 0)
				cout << "\nThe list is EMPTY.\n\n";
			else
			{
				cout << "[Search With ID]\n"
					 << "Enter ID you want to search >> ";
				cin >> search_id;
				search_node = tree.search(search_id);
				if (search_node->s_id != "00000000")
					cout << "    Name    :    ID    :     Phone #     : # of T : Paid\n"
						 << "--------------------------------------------------------\n"
						 << search_node->name << " : " << search_node->s_id << " : " << search_node->phone_num << " : " << search_node->ticket << " : " << search_node->paid << "\n\n";
				else
					free(search_node);
			}
			continue;
		}
		if (input == 4)
		{ //Edit Reservation Info
			bst_node *search_node;
			string search_id;

			if (tree.get_size() == 0)
				cout << "\nThe list is EMPTY.\n\n";
			else
			{
				cout << "[Edit Reservation Info]\n"
					 << "Enter ID you want to edit >> ";
				cin >> search_id;
				search_node = tree.search(search_id);
				if (search_node->s_id != "00000000")
				{
					string input_name = "No Data";
					string input_id = "00000000";
					string input_pnum = "010-xxxx-xxxx";
					char input_paid = 'x';
					int input_ticket = 0;

					cout << "Please enter new information.\n";
					cout << "Name >> ";
					cin >> input_name;
					cout << "Student ID (8 digits) >> ";
					cin >> input_id;
					cout << "Phone number (010-xxxx-xxxx) >> ";
					cin >> input_pnum;
					cout << "Number of Tickets >> ";
					cin >> input_ticket;
					cout << "Paid (o/x) >> ";
					cin >> input_paid;

					temp.set_data(input_name, input_id, input_pnum, input_paid, input_ticket);

					string searched_name = search_node->name;
					temp.left = search_node->left;
					temp.right = search_node->right;
					*search_node = temp;
					cout << "\n<" << searched_name << "> has been updated!\n\n";
					continue;
				}
				else
					free(search_node);
			}
			continue;
		}
		if (input == 5)
		{ //Sales Status
			if (tree.get_size() > 0)
			{
				cout << "[Sales Status]\n"
					 << "# of Reservation: " << tree.get_size() << endl
					 << "# of Total Sold Tickets: " << tree.ticket_sum() << endl
					 << "# of Available Tickets: " << TOTAL_TICKET - tree.ticket_sum() << endl
					 << "Total Sales: " << tree.sales_sum() << endl
					 << endl;
			}
			else
				cout << "\nThe list is EMPTY.\n\n";
			continue;
		}
		if (input == 6)
		{ //Last Update
			cout << "[Last Update]\n"
				 << "    Name    :    ID    :     Phone #     : # of T : Paid\n"
				 << "--------------------------------------------------------\n"
				 << temp.name << " : " << temp.s_id << " : " << temp.phone_num << " : " << temp.ticket << " : " << temp.paid << "\n\n";
			continue;
		}
		if (input == 7)
		{
			char check = 'n';
			cout << "[Save]\n"
				 << "Enter filename >> ";
			cin >> filename;
			cout << "If the file already exixts, the contents will be replaced. Are you sure you want to proceed? (y/n) >> ";
			cin >> check;

			if (check == 'y')
				tree.file_out_inorder(filename);
			else
				cout << "Save Canceled\n\n";
			continue;
		}
		if (input == 8)
		{ //Exit
			char check = 'n';

			cout << "Make sure you save your data. Are you sure you want to close program? (y/n) >> ";
			cin >> check;
			cout << endl;
			if (check == 'y')
				break;
			else
				continue;
		}

		cout << "Wrong input. Please enter a number between 1 and 8.\n\n";
	}

	cout << "***Exit Program***\n";
}
