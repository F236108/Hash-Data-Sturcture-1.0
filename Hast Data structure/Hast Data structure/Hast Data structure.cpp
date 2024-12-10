#include<iostream>
#include<iomanip>
using namespace std;
class Node {
public:
	string Name;
	string Address;
	int phone;
	int key;
	Node() {
		key = -1;
	}
};
class Hash_Data {
	int cap;
	int used_size;
	Node* ptr;
public:
	Hash_Data(int c) {
		cap = c;
		used_size = 0;
		ptr = new Node[cap];
	}
	int hash(int key)  {
		int i = (key) % cap;
		return i;
	}
	void insert(int k,string N, int p,string ad) {
		if (used_size == cap-1) {
			cout << "Contect Book are Full";
			return;
		}
		else {
			int i = this->hash(p);
			if (used_size == 0) {
				if (ptr[i].Name == N || ptr[i].Address == ad) {
					cout << "Contant already exist" << endl;
					return;
				}
				else {
					ptr[i].Name = N;
					ptr[i].phone = p;
					ptr[i].Address = ad;
					ptr[i].key = k;
				}
			}
			else {
				while (ptr[i].key != -1) {
					i = (i + 1) % cap;
				}
				if (ptr[i].Name == N || ptr[i].Address == ad) {
					cout << "Content already exist" << endl;
					return;
				}
				else {
					ptr[i].Name = N;
					ptr[i].phone = p;
					ptr[i].Address = ad;
					ptr[i].key = k;

				}
			}
			used_size++;
			cout << endl << ptr[i].Name << " & " << ptr[i].phone << " & " << ptr[i].Address << " are added in the index " << i << endl << endl;
		}
	}
	void show_hash() {
		if (used_size == 0) {
			cout << "Empty Hash " << endl;
		}
		else {
			cout << setw(15) << left << "key" << setw(15) << left << "Name" << setw(15) << left << "Phone" << setw(15) << left << "Address" << endl;
			for (int i = 0; i < cap; i++) {
				if (ptr[i].key != -1) {
					cout << setw(15) << left<<ptr[i].key << setw(15) << left << ptr[i].Name << setw(15) << left << ptr[i].phone << setw(15) << left << ptr[i].Address << endl;
				}
			}
		}
	}
	void delete_hash(int keys) {
		if (used_size == 0) {
			cout << "Empty Hash Data" << endl;
		}
		else {
			int i = this->hash(keys);
			while (ptr[i].key != keys || ptr[i].key == -1) {
				i = (i + 1)%cap;
			}
			cout << endl << ptr[i].Name << " & " << ptr[i].phone << " & " << ptr[i].Address << " are Remove in the index " << i << endl << endl;
			ptr[i].key = -1;
			used_size--;
		}
	}
	void search(int keys) {
		int i = this->hash(keys);
		int count = 0;
		if (used_size == 0) {
			cout << "Empty Hash " << endl;
		}
		else {
			while (ptr[i].key != keys || ptr[i].key == -1) {
				count++;
				i = (i + 1) % cap;
				if (count == cap - 1) {
					break;
				}
			}
			if (count == cap - 1) {
				cout << "Element are not fount at Key " << keys << endl;
			}
			else {
				cout << "Element with key " << keys << " are found at " << i << " index"<<" with the Name "<<ptr[i].Name<< endl;
			}
		}
	}
	void Update_Contact(int keys) {
		int i = this->hash(keys);
		cout << "Enter The new Name : ";
		cin >> ptr[i].Name;
		cout << "Enter the New Phone Number : ";
		cin >> ptr[i].phone;
		cout << "Enter the New Address : ";
		cin >> ptr[i].Address;
	}
};
int main() {
	Hash_Data obj(10);
	obj.show_hash();
	obj.insert(10,"Zain", 34640, "102 Burj Mandi");
	obj.show_hash();
	obj.insert(20,"Hammad", 32725, "Faisalabad");
	obj.show_hash();
	obj.insert(30, "Faizan Islam", 327725, "Allied");
	obj.show_hash();
	obj.delete_hash(30);
	obj.show_hash();
	obj.insert(60, "Faizan Islam", 327725, "Fsd");
	obj.search(20);
	obj.show_hash();
	obj.Update_Contact(10);
	obj.show_hash();
}