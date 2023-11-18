#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLENGTH 128
#define MAXINPUT 1024

void clearScreen() {
	system("clear");
}

void executeCommand(const char *command) {
	system(command);
}

int main() {
	clearScreen();
	char savedAPI[STRLENGTH];
	int flag = 0;

	printf("\x1b[31m");
	printf("                      ████╗      ████╗    ████████╗    ██╗   ██╗    ████╗     ██╗           \x1b[0mv1.0\x1b[31m \n");
	printf("                      ██╔██╗    ██╔██║    ██══════╝    ██║ ██╔═╝    ██╔██╗    ██║           \x1b[0mby \x1b[31mMert Gursimsir \n");
	printf("                      ██║ ██╗  ██╔╝██║    ████████╗    ████══╝      ██║  ██╗  ██║  \n");
	printf("                      ██║  ██╗██╔╝ ██║    ╚═════██║    ██║ ██       ██║    ██╗██║  \n");
	printf("                      ██║   ██╔═╝  ██║    ████████║    ██║   ██╗    ██║     ████║  \n");
	printf("                      ╚═╝   ╚═╝    ╚═╝    ╚═══════╝    ╚═╝   ╚═╝    ╚═╝     ╚═══╝  \n");
	printf("================================================================================================================\n");

	while(1){
		printf("\n\n\x1b[34m 1) Update.\n");
		printf(" 2) Install.\n");
		printf("\x1b[32m 3) Lists out all the storage blocks.\n"); //lsblk
		printf(" 4) Display all information about storage devices with columns.\n"); //lsblk -o PATH,SIZE,RO,TYPE,MOUNTPOINT,UUID,MODEL
		printf(" 5) Display details about mounted file systems.\n"); //df -h
		printf(" 6) Display actual mounted file system devices or partitions.\n"); //df -h | grep ^/dev
		printf(" 7) Display only real disk partitions along with type.\n"); //df -h --output=source,fstype,size,used,avail,pcent,target -x tmpfs -x devtmpfs
		printf(" 8) Display the usage of disk.\n"); //du -a
		printf(" 9) Display the statistics of current directory.\n"); //stat .
		printf("\x1b[35m10) Display IP addresses.\n");
		printf("11) Display used ports.\n");
		printf("12) Explain command.\n");
		printf("13) Display access permissions of a file.\n");
		printf("14) Display unsuccessful logins.\n");
        printf("15) Check modified file less than n days ago.\n");
		printf("\x1b[33m16) Use AI.\n");
		printf("\x1b[31m 0) EXIT\n\n");

		int choice;
		printf("\x1b[0m>>> ");
		scanf("%d", &choice);

		while (getchar() != '\n');

		switch (choice) {
			case 1:
				executeCommand("apt-get update && apt-get upgrade");
				break;
			case 2:
				printf("Package: ");
				char packageName[STRLENGTH];
				fgets(packageName, sizeof(packageName), stdin);
				if (packageName[strlen(packageName) - 1] == '\n') packageName[strlen(packageName) - 1] = '\0';
				char installation[STRLENGTH] = "apt-get install ";
				strcat(installation, packageName);
				executeCommand(installation);
				break;
			case 3:
				executeCommand("lsblk");
				break;
			case 4:
				executeCommand("lsblk -o PATH,SIZE,RO,TYPE,MOUNTPOINT,UUID,MODEL");
				break;
			case 5:
				executeCommand("df -h");
				break;
			case 6:
				executeCommand("df -h | grep ^/dev");
				break;
			case 7:
				executeCommand("df -h --output=source,fstype,size,used,avail,pcent,target -x tmpfs -x devtmpfs");
				break;
			case 8:
				executeCommand("du -a");
				break;
			case 9:
				executeCommand("stat .");
				break;
			case 10:
				executeCommand("ip -h a | awk '/inet/ {printf \"%-15s %s\\n\", $NF, $2}'");
				break;
			case 11:
				executeCommand("ss -tlpn | awk '/LISTEN/ {split($4, a, \":\"); print a[1] \":\" a[2]}'");
				break;
			case 12:
				printf("Command: ");
				char commandName[STRLENGTH];
				fgets(commandName, sizeof(commandName), stdin);
				if (commandName[strlen(commandName) - 1] == '\n') commandName[strlen(commandName) - 1] = '\0';
				char fullCommand[STRLENGTH] = "whatis ";
				strcat(fullCommand, commandName);
				executeCommand(fullCommand);
				break;
			case 13:
				printf("File: ");
				char filename[STRLENGTH];
				fgets(filename, sizeof(filename), stdin);
				if (filename[strlen(filename) - 1] == '\n') filename[strlen(filename) - 1] = '\0';
				char getFileAccess[STRLENGTH] = "getfacl ";
				strcat(getFileAccess, filename);
				executeCommand(getFileAccess);
				break;
			case 14:
				executeCommand("cat /var/log/faillog");
				break;
            case 15:
                printf("Enter n: ");
                char n[STRLENGTH];
                fgets(n, sizeof(n), stdin);
				if (n[strlen(n) - 1] == '\n') n[strlen(n) - 1] = '\0';
                char finder[STRLENGTH] = "find . -type f -mtime -";
				strcat(finder, n);
                executeCommand(finder);
                break;
			case 16: ;
				char APIKEY[STRLENGTH];
				char question[MAXINPUT];
				char command[MAXINPUT*4];

				if (flag == 0){
					flag = 1;

					printf("Enter the API key: ");
					fgets(APIKEY, sizeof(APIKEY), stdin);
					if (APIKEY[strlen(APIKEY) - 1] == '\n') APIKEY[strlen(APIKEY) - 1] = '\0';

					strcpy(savedAPI, APIKEY);
				}
				else strcpy(APIKEY, savedAPI);

				printf("Enter the question: ");
				fgets(question, sizeof(question), stdin);
				if (question[strlen(question) - 1] == '\n') question[strlen(question) - 1] = '\0';
				
				snprintf(command, sizeof(command), "echo $(curl -s https://api.openai.com/v1/chat/completions -H 'Content-Type: application/json' -H 'Authorization: Bearer %s' -d '{\"model\":\"gpt-3.5-turbo-16k\",\"messages\":[{\"role\":\"user\",\"content\":\"%s\"}]}' | jq '.choices[]'.message.content)", APIKEY, question);
				
				executeCommand(command);
				break;

			case 0:
				printf("\n\x1b[31mG\x1b[32mO\x1b[33mO\x1b[34mD\x1b[35m-\x1b[36mB\x1b[0m\x1b[31mY\x1b[32mE\x1b[33m!\x1b[0m\n\n");
				return 0;

			default:
				printf("Invalid choice\n");
				break;
		}

		printf("\n\nPress enter to return to menu...");
		getchar();

		clearScreen();
	}

	return 0;
}
