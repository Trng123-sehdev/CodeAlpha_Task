#include<iostream>
#include<windows.h>
using namespace std;

void print_tasks(string tasks[], int task_count){
    cout<<"Tasks TO DO:"<<endl;
    cout<<"------------------------------------"<<endl;
    for(int i=0; i<task_count; i++){
        cout<<"Tasks"<<i<<":"<<tasks[i]<<endl;
    }
    cout<<"------------------------------------"<<endl;
}
int main(){
    string tasks[10]={""};
    int task_count=0;
    int option =-1;
    while(option != 0){
        cout<<"----TO DO LIST----"<<endl;
        cout<<"1- To Add New Task:"<<endl;
        cout<<"2= To View Tasks:"<<endl;
        cout<<"3- Delete The Tasks:"<<endl;
        cout<<"0- Terminate the programm"<<endl;
        cin>>option;

        switch(option)
        {
            case 1:
            {
                if(task_count > 9){
                    cout<<"'''Task List Is Full'''"<<endl;
                }
                else{
                    cout<<"Enter A New Task:";
                    cin.ignore();
                    getline(cin,tasks[task_count]);
                    task_count++;
                }
                break;
            }
            case 2:
            print_tasks(tasks,task_count);
            break;

            case 3:
            {
                int del_tasks=0;
                cout<<"Enter A Task TO Delete:"<<endl;
                cin>>del_tasks;

                if(del_tasks<0 || del_tasks>9){
                    cout<<"You entered wrong task no."<<endl;
                    break;
                }
                for(int i= del_tasks; i<task_count; i++){
                    tasks[i]=tasks[i+1];
                }
                task_count=task_count-1;
                break;
            }
        }
    }


    return 0;
}