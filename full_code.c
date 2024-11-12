#include <stdio.h>
#include <string.h>
#define MAX_TASKS 100
struct Task{
    char descrip[100];
    int completed;
};
struct Task tasks[MAX_TASKS];
int taskcount=0;

void addtask(){
    if(taskcount>=MAX_TASKS){
        printf("The list is Full.\n");
    }
printf("Enter task description: ");
getchar();
fgets(tasks[taskcount].descrip,100,stdin);
tasks[taskcount].descrip[strcspn(tasks[taskcount].descrip, "\n")]=0;
tasks[taskcount].completed=0;
taskcount++;
}

void viewtask(){
    if(taskcount==0){
        printf("No tasks to show.\n");
    }
printf("Tasks :\n");
for(int i=0;i<taskcount;i++){
    printf("%d.%s %s\n",i+1, tasks[i].completed ? "(Done)":" ", tasks[i].descrip);
}    
}

void completetask(){
    int tasknum;
    printf("Enter the task number to mark as completed: ");
    scanf("%d",&tasknum);
    if(tasknum>0 && tasknum<=taskcount){
        tasks[tasknum-1].completed=1;
        printf("Task marked as completed.\n");
    }
    else{
        printf("Invalid task number.\n");
    }
}

void deletetask(){
    int tasknum;
    printf("Enter the number of task that you want to delete : ");
    scanf("%d",&tasknum);
    if(tasknum>0 && tasknum<=taskcount){
        for(int i=tasknum-1;i<taskcount-1;i++){
            tasks[i]=tasks[i+1];
        }
    taskcount--;
    printf("Task deleted successfully.\n");    
    }
    else{
        printf("Invalid task number.\n");
    }
}

int main(){
    int choice;
    do{
        printf("Welcome to To-Do-List !\n");
        printf("1. Add Task\n");
        printf("2. View Task\n");
        printf("3. Complete Task\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
            addtask();
            break;
        case 2:
            viewtask();
            break;
        case 3:
            completetask();
            break;
        case 4:
            deletetask();
            break;
        case 5:
            printf("Exited...\n");
            break;
        default:
            printf("Invalid choice! Try Again.\n");
    }    
    }
    while(choice!=5);
    return 0;
}
