#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 商品类
class Product {
public:
	string name;
	double price;

	Product(string n, double p) : name(n), price(p) {}
};

// 用户基类
class User {
public:
	string username;
	string password;  // 新增密码字段

	User(string name, string pass) : username(name), password(pass) {}

	// 修改密码
	void changePassword(string newPass) {
		password = newPass;
		cout << "密码修改成功。" << endl;
	}

	// 虚函数声明
	virtual void addToCart(const Product& product) {}
};

// 顾客类
class Customer : public User {
public:
	vector<Product> cart;

	Customer(string name, string pass) : User(name, pass) {}

	// 重写虚函数
	void addToCart(const Product& product) override {
		cart.push_back(product);
		cout << "已添加 " << product.name << " 到购物车。" << endl;
	}

	// 显示购物车
	void displayCart() {
		cout << username << " 的购物车：" << endl;
		for (const auto& product : cart) {
			cout << product.name << " - ￥" << product.price << endl;
		}
	}
};

// 管理员类
class Admin : public User {
public:
	Admin(string name, string pass) : User(name, pass) {}

	// 添加商品
	void addProduct(vector<Product>& products, string name, double price) {
		products.push_back(Product(name, price));
		cout << "已添加商品：" << name << " - ￥" << price << endl;
	}
};

// 购物系统类
class ShoppingSystem {
public:
	vector<Product> products;
	vector<Customer> customers;
	Admin admin;  // 单一管理员，简化设计
	User* currentUser = nullptr;  // 当前登录用户

	// 构造函数从文件加载顾客信息
	ShoppingSystem() : admin("admin", "adminpass") {
		loadCustomersFromFile();
		loadProductsFromFile();
	}

	// 从文件加载顾客信息
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

	// 保存顾客信息到文件
	void saveCustomersToFile() {
		ofstream file("customers.txt");
		for (const auto& customer : customers) {
			file << customer.username << " " << customer.password << "\n";
		}
		file.close();
	}

	// 从文件加载商品信息
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

	// 保存商品信息到文件
	void saveProductsToFile() {
		ofstream file("products.txt");
		for (const auto& product : products) {
			file << product.name << " " << product.price << "\n";
		}
		file.close();
	}

	// 用户注册
	void registerUser() {
		string username, password;
		cout << "请输入新的用户名：";
		cin >> username;

		// 检查用户名是否已存在
		for (const auto& customer : customers) {
			if (customer.username == username) {
				cout << "用户名已存在，请选择其他用户名。" << endl;
				return;
			}
		}

		cout << "请输入密码：";
		cin >> password;

		customers.push_back(Customer(username, password));
		cout << "用户注册成功：" << username << endl;
		saveCustomersToFile();  // 保存更新后的顾客信息到文件
	}

	// 用户登录
	void loginUser() {
		string username, password;
		cout << "请输入用户名：";
		cin >> username;
		cout << "请输入密码：";
		cin >> password;

		for (auto& customer : customers) {
			if (customer.username == username && customer.password == password) {
				currentUser = &customer;
				cout << "用户登录成功：" << username << endl;
				return;
			}
		}

		// 如果登录失败，将当前用户设为空
		currentUser = nullptr;
		cout << "用户登录失败，用户名或密码错误：" << username << endl;
	}

	// 顾客修改密码
	void changeCustomerPassword() {
		if (currentUser != nullptr && currentUser != &admin) {
			string newPassword;
			cout << "请输入新密码：";
			cin >> newPassword;
			currentUser->changePassword(newPassword);
			saveCustomersToFile();  // 保存更新后的顾客信息到文件
		}
		else {
			cout << "无效的操作，只有顾客可以修改密码。" << endl;
		}
	}

	// 管理员登录
	void loginAdmin() {
		string username, password;
		cout << "请输入管理员用户名：";
		cin >> username;
		cout << "请输入管理员密码：";
		cin >> password;

		if (admin.username == username && admin.password == password) {
			currentUser = &admin;
			cout << "管理员登录成功：" << username << endl;
		}
		else {
			// 如果登录失败，将当前用户设为空
			currentUser = nullptr;
			cout << "管理员登录失败，管理员账户或密码错误：" << username << endl;
		}
	}

	// 退出登录
	void logout() {
		currentUser = nullptr;
		cout << "已退出登录。" << endl;
	}

	// 显示商品列表
	void displayProducts() {
		cout << "商品列表：" << endl;
		for (const auto& product : products) {
			cout << product.name << " - ￥" << product.price << endl;
		}
	}

	// 购买商品
	void purchaseProduct() {
		if (currentUser == nullptr) {
			cout << "请先登录系统再购买商品。" << endl;
			return;
		}

		displayProducts();

		int productIndex;
		cout << "请输入要购买的商品序号：";
		cin >> productIndex;

		if (productIndex >= 0 && productIndex < products.size()) {
			// 顾客购买商品
			if (currentUser != &admin) {
				currentUser->addToCart(products[productIndex]);
				cout << "购买成功！已添加到购物车。" << endl;
			}
			else {
				cout << "管理员不能购买商品。" << endl;
			}
		}
		else {
			cout << "无效的商品序号。" << endl;
		}
	}
};

int main() {
	ShoppingSystem shoppingSystem;

	int choice;

	do {
		cout << "\n----- 购物系统菜单 -----" << endl;
		cout << "1. 用户注册" << endl;
		cout << "2. 用户登录" << endl;
		cout << "3. 管理员登录" << endl;
		cout << "4. 退出登录" << endl;
		cout << "5. 显示商品列表" << endl;
		cout << "6. 购买商品" << endl;
		cout << "7. 修改密码" << endl;
		cout << "8. 退出系统" << endl;
		cout << "请选择操作：";
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
			cout << "感谢使用购物系统，再见！" << endl;
			break;
		default:
			cout << "无效的选项，请重新选择。" << endl;
		}
	} while (choice != 8);

	return 0;
}
