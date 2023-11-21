#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

namespace Lexer
{	
	// 将token用他们的字符所对应的整数表示，这样做既方便有效，
	// 又能帮助使用排错系统的人。
	enum Token_value {
		NAME, NUMBER, END, PLUS = '+',
		MINUS = '-', MUL = '*', DIV = '/',
		PRINT = ';', ASSIGN = '=', LP = '(', RP = ')',
	};
	Token_value curr_tok = PRINT;//在get_token中设置；在expr、term、prim中使用，表示当前读入的标记的类别，用来控制分类别的求值及其他处理
	double number_value;//在get_token中设置；在prim中使用，表示当前读入的数值字面值
	string string_value;//在get_token中设置；在prim中使用，表示当前读入的符号名，用来在table中查找对应的值

	Token_value get_token();//不断更新curr_tok变量的状态，也就是当前的输入所代表的状态，并且通过这个状态来判断下一步应该执行什么样的操作	
}

namespace Parser
{
	double expr(bool);
	double term(bool);
	double prim(bool);

	using namespace Lexer;
}

namespace Error
{
	int no_of_errors;//在error中设置；在main中使用，表示已经发生的错误数量

	double error(const string& s);

	using namespace Parser;
}

map<string, double> table;//在prim中使用，表示已经读入的符号名与对应数值，符号名可以增加，对应数值通过引用类型隐含地赋值

int main()

{
	using namespace Parser;
	using namespace Error;
	using namespace Lexer;
	
	table["pi"] = 3.1415924535;
	table["e"] = 2.178;

	while (cin) {
		get_token();
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
		cout << expr(false) << '\n';//循环体的循环条件是输入的指针无异常，要是输入异常则会跳出循环。
	}
	return no_of_errors;
}

// 每个分析器都有一个bool参数，指明该函数是否需要调用get_token()去取得下一个参数

//最基础的字符和常量的处理,常常是通过prim()对当前状态的分析来获得下一次的输入或者是返回负数的值等
double Parser::prim(bool get) {
	using namespace Error;
	using namespace Lexer;

	if (get) get_token();

	switch (curr_tok) {
	case NUMBER: {
					 double v = number_value;
					 get_token();
					 return v;
	}
	case NAME: {
				   double& v = table[string_value];
				   if (get_token() == ASSIGN) v = expr(true);
				   return v;
	}
	case MINUS:
		return -prim(true);
	case LP: {
				 double e = expr(true);
				 if (curr_tok != RP) return error(" ) expected");
				 get_token();
				 return e;
	}
	default:
		return error("primary expected");
	}
}

// 函数term处理乘除，采用的方式与expr()处理方法一样
double Parser::term(bool get) {
	using namespace Error;

	double left = prim(get);
	for (;;) {
		switch (curr_tok){
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true)) {
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
		}
	}
}

// expr处理加减，一直到不是加减返回left
double Parser::expr(bool get)
{
	double left = term(get);
	for (;;) {
		switch (curr_tok){
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left += term(true);
			break;
		default:
			return left;
		}
	}
}

using namespace Lexer;
Token_value Lexer::get_token() {
	using namespace Parser;
	using namespace Error;
	


	char ch;//字符ch是一个临时变量，用来记录从控制台输入的数字，字符等
	do { // 低级输入，改进输入
		if (!cin.get(ch)) return curr_tok = END;
	} while (ch != '\n' && isspace(ch));
	switch (ch) {
	case 0:
		return curr_tok = END; //若读入结束标志，那么更新curr_tok标志为END, 整个程序会返回到mian函数跳出循环体并结束
	case '\n':
		return curr_tok = PRINT;
	case '+':
	case '-':
	case '*':
	case '/':
	case ';':
	case '(':
	case ')':
	case '=':
		return curr_tok = Token_value(ch);//若读入的是运算符，那么在枚举类型中找到对应的枚举量，用枚举类型值更新curr_tok
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		cin.putback(ch);
		cin >> number_value;
		return curr_tok = NUMBER; //若读入的是数字，则更新curr_tok，即当前输入状态为NUMBER
	default:
		if (isalpha(ch)) {
			string_value = ch;
			while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
			cin.putback(ch);
			return curr_tok = NAME; //如读入的是字符，那么会进行是否是常量e和pi的判断或者进一步判断是否是用户自己定义的变量的名称,最后更新curr_tok状态为NAME。
		}
		error("bad token");
		return curr_tok = PRINT; //假如都不满足上面的情况，那么只能说明输入出现了错误，通过标准错误流报错，并且将状态更新为PRINT.
	}
}

double Error::error(const string& s) {
	no_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}