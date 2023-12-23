#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TaskInterface {
public:
    virtual string Info() const = 0;
    virtual ~TaskInterface() = default;
};

class Task : public TaskInterface {
    string description;
    string status = "not start";
    string date;

public:
    string Status(string status) {
        if (status != "Done") {
            this->status = status;
            return this->status;
        }
    }

    string Info() const override {
        return "Task: " + description + "\nStatus: " + status + "\nDate: " + date;
    }

    void StatusEnd() { this->status = "Done"; }
    void BackStatus() { this->status = "Develop"; }
    string Status() const { return status; }
    string Date() const { return date; }

    Task(string description, string date) {
        this->status = "Develop";
        this->description = description;

        string str = "QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,/?><mnbvcxz:lkjhgfdsa}{poiuytrewq|`12345678900-=~!@#$%^&*()_+";

        bool trueDate = false;

        for (int i = 0; i < str.size(); i++) {
            for (int q = 0; q < date.size(); q++) {
                if (str[i] == date[q]) {
                    trueDate = true;
                    break;
                }
            }
            if (trueDate) break;
        }

        if (!trueDate)
            this->date = date;
        else
            this->date = "1.1.2023";
    }

    ~Task() = default;
};

class ProjectInterface {
public:
    virtual void AddTask(string description, string date) = 0;
    virtual void RemoveTask(int taskId) = 0;
    virtual string Info() const = 0;
    virtual string Info(int taskId) const = 0;
    virtual void SortTasksByStatus() = 0;
    virtual void SortTasksByDescription() = 0;
    virtual vector<TaskInterface*> GetTasks() const = 0;
    virtual ~ProjectInterface() = default;
};

class Project : public ProjectInterface {
    string name;
    string description;
    string dateStart;
    string dateEnd;
    vector<Task> task;
    string status;

public:
    void AddTask(string description, string date) override {
        this->task.push_back(Task(description, date));
    }

    void RemoveTask(int taskId) override {
        if (taskId >= 0 && taskId < this->task.size()) {
            this->task.erase(this->task.begin() + taskId);
        }
    }

    string Info() const override { return "Project: " + description; }
    string Info(int taskId) const override { return task[taskId].Info(); }

    string DateStart() const { return this->dateStart; }
    string DateEnd() const { return this->dateEnd; }
    void SetDateEnd(string date) { this->dateEnd = date; }

    vector<Task>& Tasks() { return task; }

    void SortTasksByStatus() override {
        sort(task.begin(), task.end(), [](const Task& a, const Task& b) {
            if (a.Status() == "Develop" && b.Status() != "Develop") {
                return true;
            }
            else if (a.Status() == "not start" && b.Status() == "Done") {
                return true;
            }
            else {
                return a.Status() < b.Status();
            }
            });
    }

    void SortTasksByDescription() override {
        sort(task.begin(), task.end(), [](const Task& a, const Task& b) {
            return a.Info() < b.Info();
            });
    }


    vector<TaskInterface*> GetTasks() const override {
        vector<TaskInterface*> tasks;
        for (const auto& t : task) {
            tasks.push_back(new Task(t));
        }
        return tasks;
    }

    Project(string name, string description, string dateStart, string dateEnd) {
        this->name = name;
        this->status = "Develop";
        this->description = description;

        string str = "QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,/?><mnbvcxz:lkjhgfdsa}{poiuytrewq|`12345678900-=~!@#$%^&*()_+";

        bool trueDate = false;

        for (int i = 0; i < str.size(); i++) {
            for (int q = 0; q < dateStart.size(); q++) {
                if (str[i] == dateStart[q]) {
                    trueDate = true;
                    break;
                }
            }
            if (trueDate) break;
        }

        if (!trueDate)
            this->dateStart = dateStart;
        else
            this->dateStart = "1.1.2023";

        trueDate = false;

        for (int i = 0; i < str.size(); i++) {
            for (int q = 0; q < dateEnd.size(); q++) {
                if (str[i] == dateEnd[q]) {
                    trueDate = true;
                    break;
                }
            }
            if (trueDate) break;
        }

        if (!trueDate)
            this->dateEnd = dateEnd;
        else
            this->dateEnd = "2.2.2023";

        if (this->dateStart == this->dateEnd) {
            this->dateStart = "1.1.2023";
            this->dateEnd = "2.2.2023";
        }
    }

    ~Project() {
        for (auto& t : task) {
            delete& t;
        }
    }
};

class ProjectManager {
    vector<ProjectInterface*> pm;

public:
    void AddProject(string name, string description, string dateStart, string dateEnd) {
        this->pm.push_back(new Project(name, description, dateStart, dateEnd));
    }

    void RemoveProject(int prjId) {
        if (prjId >= 0 && prjId < this->pm.size()) {
            delete this->pm[prjId];
            this->pm.erase(this->pm.begin() + prjId);
        }
    }

    void AddTask(int prjId, string description, string date) {
        this->pm[prjId]->AddTask(description, date);
    }

    void RemoveTask(int prjId, int taskId) {
        this->pm[prjId]->RemoveTask(taskId);
    }

    void Info(int prjId) const {
        cout << this->pm[prjId]->Info() << endl;
    }

    void Info(int prjId, int taskId) const {
        cout << this->pm[prjId]->Info(taskId) << endl;
    }

    void DisplaySortedAndFilteredTasksByStatus(int prjId, const string& targetStatus) const {
        ProjectInterface* project = this->pm[prjId];
        project->SortTasksByStatus();
        vector<TaskInterface*> filteredTasks = project->GetTasks();

        for (const auto& task : filteredTasks) {
            cout << task->Info() << endl;
            delete task;
        }
    }

    void DisplaySortedTasksByDescription(int prjId) const {
        ProjectInterface* project = this->pm[prjId];
        project->SortTasksByDescription();

        for (const auto& task : project->GetTasks()) {
            cout << task->Info() << endl;
            delete task;
        }
    }

    ~ProjectManager() {
        for (auto project : this->pm) {
            delete project;
        }
    }
};

int main() {
    ProjectManager projectManager;

    string projectName = "Project 1";
    string projectDescription = "Sample Project";
    string projectStartDate = "2023-01-01";
    string projectEndDate = "2023-02-01";

    projectManager.AddProject(projectName, projectDescription, projectStartDate, projectEndDate);

    int projectId = 0;

    projectManager.Info(projectId);

    cout << endl;

    string taskDescription1 = "Task 1";
    string taskDate1 = "2023-01-02";
    string taskDescription2 = "Task 2";
    string taskDate2 = "2023-01-01";

    projectManager.AddTask(projectId, taskDescription1, taskDate1);
    projectManager.AddTask(projectId, taskDescription2, taskDate2);

    projectManager.Info(projectId);

    cout << endl;

    projectManager.DisplaySortedTasksByDescription(projectId);

    cout << endl;

    projectManager.DisplaySortedAndFilteredTasksByStatus(projectId, "not start");

    return 0;
}
