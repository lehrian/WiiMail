#ifndef _POP3_H_
#define _POP3_H_

#define READ_BUFFER_SIZE 2024
#define SEND_BUFFER_SIZE 512
#define DATA_BUFFER_SIZE 10000

#include "server.h"
#include "email.h"
#include "internet.h"

class POP3 : public Server{
public:
	POP3(Internet* _internet, char* _address, int _port, char* _username, char* _password, int _ssl);
	~POP3();
	//Retrieves new messages and adds to sqlite database
	bool getMail();
	char** list;
	int numMessages;
	int numOctets;

private:
	bool write(char* input);
	bool read();
	bool parse();

	bool connect();
	bool hello();
	bool startTLS();
	bool authorize();
	bool listMessages();
	bool retrieveMessage(int num);
	bool updateDB();
	bool quit();

	email_t* email;
	char* response;
	char* message;
	char* data;
	bool error;
};

#endif