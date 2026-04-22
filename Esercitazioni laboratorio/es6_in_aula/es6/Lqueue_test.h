#ifndef TEST_H
#define TEST_H

#include <iostream>
using namespace std;

#include "lqueue.h"
#include "LQueueTest.h"

class Job {
private:
	int utente_id;
	int pagine_da_stampare;
	int timestamp;
	int job_id;
public:
	Job(int utente_id = 0, int pagine_da_stampare = 0, int timestamp = 0, int job_id = 0) {
		this->utente_id = utente_id;
		this->pagine_da_stampare = pagine_da_stampare;
		this->timestamp = timestamp;
		this->job_id = job_id;
	}

	int getUtenteId() const { return this->utente_id; }
	int getPagine() const { return this->pagine_da_stampare; }
	int getTimestamp() const { return this->timestamp; }
	int getJobId() const { return this->job_id; }
};

inline ostream& operator << (ostream& s, Job j) {
	return s << "User: " << j.getUtenteId() << ", pagine: " << j.getPagine() << ", timestamp: " << j.getTimestamp() << ", jobid: " << j.getJobId();
}


#endif
