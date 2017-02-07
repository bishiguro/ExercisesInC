#include <stdio.h>
#include <string.h>

#define NUM_USERS 10

struct user
{
	char name[24];
	int age;
};

void display_user_list(struct user user_list[])
{
	
	printf("\nUSERS: \n");
	int i;
	for (i=0; i < NUM_USERS; i=i+1)
	{
		printf("Name: %-24s", user_list[i].name);
		printf("Age: %3i\n", user_list[i].age);
	}
}

void record_user(struct user user_list[]) 
{
	static int user_id = 0;
	struct user u;
	printf("Enter your name: ");
	scanf("%24s", u.name);
	printf("Enter your age: ");
	scanf("%3i", &u.age);
	
	int i;
	for (i=0; i < NUM_USERS; i=i+1) 
		user_list[user_id] = u; 
	user_id += 1;
}

int main() 
{
	struct user user_list[NUM_USERS];
	memset(user_list, 0, sizeof(user_list));
	while (1) 
	{
		record_user(user_list);
		display_user_list(user_list);
	}
	return 0;
}