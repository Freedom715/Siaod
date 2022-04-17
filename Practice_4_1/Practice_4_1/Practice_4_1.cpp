#include <iostream>
#include <string>
using namespace std;



struct Worker {
	int worker_numb, worker_code;
	string worker_name, date;
};
struct Organization {
	int size = 0;
	static const int max_size = 99;
	Worker arr_of_workers[max_size + 1] = {0};
};
struct WorkerCode {
	int codeNumb = 0;
	string codeName;
};


bool fillWorkers(Organization* workers);
int fillPositions(WorkerCode* empty_positions);
void InsertWorker(Organization* workers);
void ReplaceWorkerCode(Organization* workers);
void DeleteWorker(Organization* workers);
void PrintWorkers(Organization* workers);


WorkerCode positions[5];

int main() {
	Organization workers;
	while (true) {
		cout << "Worker " << workers.size + 1 << "\n";
		if (!fillWorkers(&workers)) break;
		if (workers.size > workers.max_size - 1) break;
		workers.size++;
	};
	PrintWorkers(&workers);
	InsertWorker(&workers);
	PrintWorkers(&workers);
	ReplaceWorkerCode(&workers);
	PrintWorkers(&workers);
	DeleteWorker(&workers);
	PrintWorkers(&workers);

	return 0;
};

bool fillWorkers(Organization* workers) {
	int flag = 0;
	string temp;
	while (!(100 <= flag and flag < 1000)) {
		cout << "Enter the worker's number in [100, 999] (enter -1 if u want to end input)^ ";
		cin >> flag;
		if (flag == -1) return false;
	}
	workers->arr_of_workers[workers->size].worker_numb = flag;
	cout << "Enter name and secondname of employer: ";
	cin >> temp;
	workers->arr_of_workers[workers->size].worker_name = temp;
	workers->arr_of_workers[workers->size].worker_code = fillPositions(positions);
	cout << "Enter the date: ";
	cin >> temp;
	workers->arr_of_workers[workers->size].date = temp;
	return true;
}

int fillPositions(WorkerCode* empty_positions) {
	int flag = 0;
	string temp;
	WorkerCode code;
	while (!(10 <= flag and flag < 100)) {
		cout << "Enter number of worker's position: ";
		cin >> flag;
	}
	for (int i = 0; i < 5; i++) {
		if (empty_positions[i].codeNumb == 0) {
			code.codeNumb = flag;
			cout << "Enter the name of position: ";
			cin >> temp;
			code.codeName = temp;
			empty_positions[i] = code;
			return code.codeNumb;
		}
		else if (empty_positions[i].codeNumb == flag) {
			return empty_positions[i].codeNumb;
		}
	}
	return flag;
}

void InsertWorker(Organization* workers) {
	int flag = 0;
	string temp;
	Worker temp_worker, temp_perem;
	while (!(100 <= flag and flag < 1000)) {
		cout << "Enter the worker's number in [100, 999]# ";
		cin >> flag;
	}
	temp_worker.worker_numb = flag;
	cout << "Enter name and secondname of employer: ";
	cin >> temp;
	temp_worker.worker_name = temp;
	temp_worker.worker_code = fillPositions(positions);
	cout << "Enter the date: ";
	cin >> temp;
	temp_worker.date = temp;
	for (int i = workers->size - 1; i > 0; i--) {
		if (workers->arr_of_workers[i].worker_code == temp_worker.worker_code) {
			cout << i << endl;
			for (int j = workers->size; j > i; j--) {
				if (j == i + 1) {
					workers->arr_of_workers[j] = temp_worker;
				}
				else {
					temp_perem = workers->arr_of_workers[j - 1];
					workers->arr_of_workers[j] = temp_perem;
					cout << workers->arr_of_workers[j].worker_name << " " << workers->arr_of_workers[j - 1].worker_name << endl;
				}
				
			}
			workers->size++;
			return;
		}
	}
}

void ReplaceWorkerCode(Organization* workers) {
	int code, new_code;
	cout << "Enter the old code ";
	cin >> code;
	cout << "Enter the new code ";
	cin >> new_code;
	for (int i = 0; i < workers->size; i++) {
		if (workers->arr_of_workers[i].worker_code == code) {
			workers->arr_of_workers[i].worker_code = new_code;
		}
	}

}

void DeleteWorker(Organization* workers) {
	int code;
	cout << "Enter the code";
	cin >> code;
	for (int i = 0; i < workers->size; i++) {
		if (workers->arr_of_workers[i].worker_code == code) {
			workers->arr_of_workers[i].worker_code = -1;
		}
	}
}

void PrintWorkers(Organization* workers) {
	for (int i = 0; i < workers->size; i++) {
		if (!(workers->arr_of_workers[i].worker_code == -1)) {
			cout << workers->arr_of_workers[i].worker_name << endl;
			cout << workers->arr_of_workers[i].worker_numb << endl;
			cout << workers->arr_of_workers[i].worker_code << endl;
			cout << workers->arr_of_workers[i].date << endl;
		}
	}
}