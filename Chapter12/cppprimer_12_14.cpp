#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<utility>
#include<map>
#include<set>
#include<typeinfo>
#include<iterator>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include<memory>
using namespace std;
struct connection {
	string ip;
	int port;
	connection(string ip_, int port_) : ip(ip_), port(port_) {};
};
struct destination {
	string ip;
	int port;
	destination(string ip_, int port_) : ip(ip_), port(port_) {};
};
connection connect(destination* pDest) {
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	cout << "creating connection(" << pConn.use_count() << ")" << endl;
	return *pConn;
}
void disconnect(connection Conn) {
	cout << "connection close(" << Conn.ip << " " << Conn.port << ")" << endl;
}
void end_connection(connection* pConn) {
	disconnect(*pConn);
}
void f(destination& d) {
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
}
int main()
{
	destination dest("192.1.1.0", 2000);
	f(dest);
	return 0;
}