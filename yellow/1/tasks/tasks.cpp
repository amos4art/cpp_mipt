#include <map>
#include <iostream>

using namespace std;

/*
enum class TaskStatus {
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

using TasksInfo = map<TaskStatus, int>;
*/

class TeamTasks {
public:
	TeamTasks();

	const TasksInfo& GetPersonTasksInfo(const string& person) const;

	void AddNewTask(const string& person);

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const string& person, int task_count);

private:
	map<string, TasksInfo> m_tasklist;
	TasksInfo merge_tasks(const TasksInfo& tasks1, const TasksInfo& tasks2);

};

TeamTasks::TeamTasks() {
	m_tasklist = {};
}


const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
	return m_tasklist.at(person);
}


void TeamTasks::AddNewTask(const string& person) {
	m_tasklist[person][TaskStatus::NEW]++;
}

TasksInfo TeamTasks::merge_tasks(const TasksInfo& tasks1, const TasksInfo& tasks2) {
	TasksInfo res;
	res = tasks1;
	
	for (auto& t : tasks2) {
		res[t.first] += t.second;
	}

	return res;
}


tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string& person, int task_count) {
	TasksInfo updated, backlog;	

	int i = 0;
	
	for (auto& t : m_tasklist[person]) {
		
		while (i < task_count && t.second > 0) {

			if (t.first == TaskStatus::NEW) {
				updated[TaskStatus::IN_PROGRESS]++;
			}
			else if (t.first == TaskStatus::IN_PROGRESS) {
				updated[TaskStatus::TESTING]++;
			}
			else if (t.first == TaskStatus::TESTING) {
				updated[TaskStatus::DONE]++;
			}
			else {
				break;
			}
			t.second--;
			i++;
		}

		if (t.second > 0) {
			backlog[t.first] = t.second;
		}
	}
	
	m_tasklist[person] = TeamTasks::merge_tasks(updated, backlog);

	// fix: backlog should not contain DONE works
	backlog.erase(TaskStatus::DONE);

	return tie(updated, backlog);
}

void PrintTasksInfo(TasksInfo tasks_info) {
	std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
	TeamTasks tasks;
	tasks.AddNewTask("Ilia");
	for (int i = 0; i < 3; ++i) {
		tasks.AddNewTask("Ivan");
	}
	std::cout << "Ilia's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
	std::cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

	TasksInfo updated_tasks, untouched_tasks;

	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 4);
	std::cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	std::cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 2);
	std::cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	std::cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 3);
	std::cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	std::cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 3);
	std::cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	std::cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	return 0;

}