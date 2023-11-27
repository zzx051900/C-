#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// ��Ʒ��
class Product {
public:
	string name;
	double price;

	Product(string n, double p) : name(n), price(p) {}
};

// �û�����
class User {
public:
	string username;
	string password;  // ���������ֶ�

	User(string name, string pass) : username(name), password(pass) {}

	// �޸�����
	void changePassword(string newPass) {
		password = newPass;
		cout << "�����޸ĳɹ���" << endl;
	}

	// �麯������
	virtual void addToCart(const Product& product) {}
};

// �˿���
class Customer : public User {
public:
	vector<Product> cart;

	Customer(string name, string pass) : User(name, pass) {}

	// ��д�麯��
	void addToCart(const Product& product) override {
		cart.push_back(product);
		cout << "����� " << product.name << " �����ﳵ��" << endl;
	}

	// ��ʾ���ﳵ
	void displayCart() {
		cout << username << " �Ĺ��ﳵ��" << endl;
		for (const auto& product : cart) {
			cout << product.name << " - ��" << product.price << endl;
		}
	}
};

// ����Ա��
class Admin : public User {
public:
	Admin(string name, string pass) : User(name, pass) {}

	// �����Ʒ
	void addProduct(vector<Product>& products, string name, double price) {
		products.push_back(Product(name, price));
		cout << "�������Ʒ��" << name << " - ��" << price << endl;
	}
};

// ����ϵͳ��
class ShoppingSystem {
public:
	vector<Product> products;
	vector<Customer> customers;
	Admin admin;  // ��һ����Ա�������
	User* currentUser = nullptr;  // ��ǰ��¼�û�

	// ���캯�����ļ����ع˿���Ϣ
	ShoppingSystem() : admin("admin", "adminpass") {
		loadCustomersFromFile();
		loadProductsFromFile();
	}

	// ���ļ����ع˿���Ϣ
	void loadCustomersFromFile() {
		ifstream file("customers.txt");
		if (file.is_open()) {
			string username, password;
			while (file >> username >> password) {
				customers.push_back(Customer(username, password));
			}
			file.close();
		}
	}

	// ����˿���Ϣ���ļ�
	void saveCustomersToFile() {
		ofstream file("customers.txt");
		for (const auto& customer : customers) {
			file << customer.username << " " << customer.password << "\n";
		}
		file.close();
	}

	// ���ļ�������Ʒ��Ϣ
	void loadProductsFromFile() {
		ifstream file("products.txt");
		if (file.is_open()) {
			string name;
			double price;
			while (file >> name >> price) {
				products.push_back(Product(name, price));
			}
			file.close();
		}
	}

	// ������Ʒ��Ϣ���ļ�
	void saveProductsToFile() {
		ofstream file("products.txt");
		for (const auto& product : products) {
			file << product.name << " " << product.price << "\n";
		}
		file.close();
	}

	// �û�ע��
	void registerUser() {
		string username, password;
		cout << "�������µ��û�����";
		cin >> username;

		// ����û����Ƿ��Ѵ���
		for (const auto& customer : customers) {
			if (customer.username == username) {
				cout << "�û����Ѵ��ڣ���ѡ�������û�����" << endl;
				return;
			}
		}

		cout << "���������룺";
		cin >> password;

		customers.push_back(Customer(username, password));
		cout << "�û�ע��ɹ���" << username << endl;
		saveCustomersToFile();  // ������º�Ĺ˿���Ϣ���ļ�
	}

	// �û���¼
	void loginUser() {
		string username, password;
		cout << "�������û�����";
		cin >> username;
		cout << "���������룺";
		cin >> password;

		for (auto& customer : customers) {
			if (customer.username == username && customer.password == password) {
				currentUser = &customer;
				cout << "�û���¼�ɹ���" << username << endl;
				return;
			}
		}

		// �����¼ʧ�ܣ�����ǰ�û���Ϊ��
		currentUser = nullptr;
		cout << "�û���¼ʧ�ܣ��û������������" << username << endl;
	}

	// �˿��޸�����
	void changeCustomerPassword() {
		if (currentUser != nullptr && currentUser != &admin) {
			string newPassword;
			cout << "�����������룺";
			cin >> newPassword;
			currentUser->changePassword(newPassword);
			saveCustomersToFile();  // ������º�Ĺ˿���Ϣ���ļ�
		}
		else {
			cout << "��Ч�Ĳ�����ֻ�й˿Ϳ����޸����롣" << endl;
		}
	}

	// ����Ա��¼
	void loginAdmin() {
		string username, password;
		cout << "���������Ա�û�����";
		cin >> username;
		cout << "���������Ա���룺";
		cin >> password;

		if (admin.username == username && admin.password == password) {
			currentUser = &admin;
			cout << "����Ա��¼�ɹ���" << username << endl;
		}
		else {
			// �����¼ʧ�ܣ�����ǰ�û���Ϊ��
			currentUser = nullptr;
			cout << "����Ա��¼ʧ�ܣ�����Ա�˻����������" << username << endl;
		}
	}

	// �˳���¼
	void logout() {
		currentUser = nullptr;
		cout << "���˳���¼��" << endl;
	}

	// ��ʾ��Ʒ�б�
	void displayProducts() {
		cout << "��Ʒ�б�" << endl;
		for (const auto& product : products) {
			cout << product.name << " - ��" << product.price << endl;
		}
	}

	// ������Ʒ
	void purchaseProduct() {
		if (currentUser == nullptr) {
			cout << "���ȵ�¼ϵͳ�ٹ�����Ʒ��" << endl;
			return;
		}

		displayProducts();

		int productIndex;
		cout << "������Ҫ�������Ʒ��ţ�";
		cin >> productIndex;

		if (productIndex >= 0 && productIndex < products.size()) {
			// �˿͹�����Ʒ
			if (currentUser != &admin) {
				currentUser->addToCart(products[productIndex]);
				cout << "����ɹ�������ӵ����ﳵ��" << endl;
			}
			else {
				cout << "����Ա���ܹ�����Ʒ��" << endl;
			}
		}
		else {
			cout << "��Ч����Ʒ��š�" << endl;
		}
	}
};

int main() {
	ShoppingSystem shoppingSystem;

	int choice;

	do {
		cout << "\n----- ����ϵͳ�˵� -----" << endl;
		cout << "1. �û�ע��" << endl;
		cout << "2. �û���¼" << endl;
		cout << "3. ����Ա��¼" << endl;
		cout << "4. �˳���¼" << endl;
		cout << "5. ��ʾ��Ʒ�б�" << endl;
		cout << "6. ������Ʒ" << endl;
		cout << "7. �޸�����" << endl;
		cout << "8. �˳�ϵͳ" << endl;
		cout << "��ѡ�������";
		cin >> choice;

		switch (choice) {
		case 1:
			shoppingSystem.registerUser();
			break;
		case 2:
			shoppingSystem.loginUser();
			break;
		case 3:
			shoppingSystem.loginAdmin();
			break;
		case 4:
			shoppingSystem.logout();
			break;
		case 5:
			shoppingSystem.displayProducts();
			break;
		case 6:
			shoppingSystem.purchaseProduct();
			break;
		case 7:
			shoppingSystem.changeCustomerPassword();
			break;
		case 8:
			cout << "��лʹ�ù���ϵͳ���ټ���" << endl;
			break;
		default:
			cout << "��Ч��ѡ�������ѡ��" << endl;
		}
	} while (choice != 8);

	return 0;
}
