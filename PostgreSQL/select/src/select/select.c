#include <stdio.h>
#include <libpq-fe.h>

int main(void){

  PGconn *con;
  PGresult *result;
  int status;
  char *db_info;
  int i;
  int id;
  char *name;
  int age;
  char *address;

  con = PQconnectdb("dbname=test1_db user=test1");
  if (con == NULL){

    printf("PQconnectdb failed!\n");
    return -1;

  }

  printf("PQconnectdb success.\n");
  
  status = PQstatus(con);
  if (status == CONNECTION_OK){

    printf("PQstatus CONNECTION_OK\n");

  }
  else{

    db_info = PQerrorMessage(con);
    printf("PQerrrorMessage = %s\n", db_info);

    return -1;

  }

  result = PQexec(con, "select * from profile;");
  if (result == NULL){

    printf("PQexec failed!\n");
    return -1;

  }

  if (PQresultStatus(result) != PGRES_TUPLES_OK){

    printf("PQresultStatus is not tuples!\n");
    return -1;

  }

  printf("-----\n");

  for (i = 0; i < PQntuples(result); i++){

    id = atoi((char *)PQgetvalue(result, i, 0));
    name = (char *)PQgetvalue(result, i, 1);
    age = atoi((char *)PQgetvalue(result, i, 2));
    address = (char *)PQgetvalue(result, i, 3);

    printf("%d, %s, %d, %s\n", id, name, age, address);

  }

  printf("-----\n");

  PQclear(result);

  PQfinish(con);

  return 0;

}
