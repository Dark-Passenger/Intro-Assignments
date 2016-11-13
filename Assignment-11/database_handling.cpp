#include <iostream>
#include <vector>
#include <string>
#include <mysql.h>

using namespace std;

class Db_Handler
{
private:
    MYSQL *connect = mysql_init(NULL);
    MYSQL_RES *result;
    MYSQL_ROW row;
    char *server = "server";
    char *user = "username";
    char *password = "password";
    char *database = "local";

string querybuilder(vector<int> val, string table_header)
{
    string query("INSERT INTO ");
    string.append(table_header);
     string.append("VALUES ");

    for( vector<int>::iterator itr = val.begin() ; itr != val.end(); ++itr)
    {
        query.append("(");
        query.append(itr);
        query.append(")");
        if(it+1 != values.end() )
            {
                query.append(",");
            }
    }
    query.append(";");

    return query;
}

void writetoDB( vector<int> numbers)
{
    mysql_real_connect(connect, server, user, password, database, 0, NULL, 0);
    cout << "writing to database...";
    mysql_query(connect, "(CREATE TABLE example_table (number INT);");
    query = querybuilder(numbers,"example_table(number)");
    query_state=mysql_query(connect, query.c_str() );
    cout << "Query status : " << query_state;
    result = mysql_use_result(connect);
    while ((row = mysql_fetch_row(result)) != NULL)
    {
        cout << row;        //todo: consider row[1] only
    }
    mysql_free_result(result);
    mysql_close(connect);
}

void readfromDB()
{
    mysql_real_connect(connect, server, user, password, database, 0, NULL, 0);
    cout << "reading from database ...";
    mysql_query(connect, "SELECT number FROM example_table");
    result = mysql_use_result(connect);
    vector<int> num;
    while ((row = mysql_fetch_row(result)) != NULL)
    {
        num.push_back(row[1]);
    }
    mysql_free_result(result);

    sort(num.begin(), num.end());
    mysql_query(connect, "(CREATE TABLE sorted_table (number INT);");
    query = querybuilder(num,"sorted_table(number)");
    query_state=mysql_query(connect, query.c_str() );
    cout << "Query status : " << query_state;
    mysql_close(connect);
}

};

int main()
{
    vector <int> input;
    for (int i = 1; i < argc; ++i)
    {
        input.push_back(argv[i]);
    }
    Db_Handler db;
    db.writetoDB(input);
    db.readfromDB();
    return 0;
}
