#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

namespace Lexer
{	
	// ��token�����ǵ��ַ�����Ӧ��������ʾ���������ȷ�����Ч��
	// ���ܰ���ʹ���Ŵ�ϵͳ���ˡ�
	enum Token_value {
		NAME, NUMBER, END, PLUS = '+',
		MINUS = '-', MUL = '*', DIV = '/',
		PRINT = ';', ASSIGN = '=', LP = '(', RP = ')',
	};
	Token_value curr_tok = PRINT;//��get_token�����ã���expr��term��prim��ʹ�ã���ʾ��ǰ����ı�ǵ�����������Ʒ�������ֵ����������
	double number_value;//��get_token�����ã���prim��ʹ�ã���ʾ��ǰ�������ֵ����ֵ
	string string_value;//��get_token�����ã���prim��ʹ�ã���ʾ��ǰ����ķ�������������table�в��Ҷ�Ӧ��ֵ

	Token_value get_token();//���ϸ���curr_tok������״̬��Ҳ���ǵ�ǰ�������������״̬������ͨ�����״̬���ж���һ��Ӧ��ִ��ʲô���Ĳ���	
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
	int no_of_errors;//��error�����ã���main��ʹ�ã���ʾ�Ѿ������Ĵ�������

	double error(const string& s);

	using namespace Parser;
}

map<string, double> table;//��prim��ʹ�ã���ʾ�Ѿ�����ķ��������Ӧ��ֵ���������������ӣ���Ӧ��ֵͨ���������������ظ�ֵ

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
		cout << expr(false) << '\n';//ѭ�����ѭ�������������ָ�����쳣��Ҫ�������쳣�������ѭ����
	}
	return no_of_errors;
}

// ÿ������������һ��bool������ָ���ú����Ƿ���Ҫ����get_token()ȥȡ����һ������

//��������ַ��ͳ����Ĵ���,������ͨ��prim()�Ե�ǰ״̬�ķ����������һ�ε���������Ƿ��ظ�����ֵ��
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

// ����term����˳������õķ�ʽ��expr()������һ��
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

// expr����Ӽ���һֱ�����ǼӼ�����left
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
	


	char ch;//�ַ�ch��һ����ʱ������������¼�ӿ���̨��������֣��ַ���
	do { // �ͼ����룬�Ľ�����
		if (!cin.get(ch)) return curr_tok = END;
	} while (ch != '\n' && isspace(ch));
	switch (ch) {
	case 0:
		return curr_tok = END; //�����������־����ô����curr_tok��־ΪEND, ��������᷵�ص�mian��������ѭ���岢����
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
		return curr_tok = Token_value(ch);//������������������ô��ö���������ҵ���Ӧ��ö��������ö������ֵ����curr_tok
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		cin.putback(ch);
		cin >> number_value;
		return curr_tok = NUMBER; //������������֣������curr_tok������ǰ����״̬ΪNUMBER
	default:
		if (isalpha(ch)) {
			string_value = ch;
			while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
			cin.putback(ch);
			return curr_tok = NAME; //���������ַ�����ô������Ƿ��ǳ���e��pi���жϻ��߽�һ���ж��Ƿ����û��Լ�����ı���������,������curr_tok״̬ΪNAME��
		}
		error("bad token");
		return curr_tok = PRINT; //���綼������������������ôֻ��˵����������˴���ͨ����׼�������������ҽ�״̬����ΪPRINT.
	}
}

double Error::error(const string& s) {
	no_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}