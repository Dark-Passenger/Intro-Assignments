#include <iostream>
#include <mysql.h>

using namespace std;

int main()
{
	MYSQL *connect;
	MYSQL_RES *result;
	MYSQL_ROW row;
	char *server = "server";
	char *user = "username";
	char *password = "password";
	char *database = "local";
	connect = mysql_init(NULL);
	mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);
	mysql_query(connect, "SELECT * FROM website");
	result = mysql_use_result(conn);
	printf("id \t date\t time \t comments\t\t user\n");
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		printf("%s \t %s\t %s\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4]);
	}
	mysql_free_result(result);
	mysql_close(connect);
	
	return 0;
}
