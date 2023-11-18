# WELCOME TO MSKN! ✨

### MENU

When the application runs, you will be greeted with a menu:

![](https://github.com/MertGursimsir/mskn/blob/main/MEDIA/image.png)

From this menu you can make 17 selections for the current version. These choices and the commands running in the background are as follows:

| Choice | Command |
| ------ | ------ |
| 1 | apt-get update && apt-get upgrade |
| 2 | apt-get install <packageName> |
| 3 | lsblk |
| 4 | lsblk -o PATH,SIZE,RO,TYPE,MOUNTPOINT,UUID,MODEL |
| 5 | df -h |
| 6 | df -h \| grep ^/dev |
| 7 | df -h --output=source,fstype,size,used,avail,pcent,target -x tmpfs -x devtmpfs |
| 8 | du -a |
| 9 | stat . |
| 10 | ip -h a | awk '/inet/ {printf \"%-15s %s\\n\", $NF, $2}' |
| 11 | ss -tlpn | awk '/LISTEN/ {split($4, a, \":\"); print a[1] \":\" a[2]}' |
| 12 | whatis <command> |
| 13 | getfacl <fileName> |
| 14 | cat /var/log/faillog |
| 15 | find . -type f -mtime -<day> |
| 16 | echo $(curl -s https://api.openai.com/v1/chat/completions -H 'Content-Type: application/json' -H 'Authorization: Bearer %s' -d '{\"model\":\"gpt-3.5-turbo-16k\",\"messages\":[{\"role\":\"user\",\"content\":\"%s\"}]}' | jq '.choices[]'.message.content) |
| 17 | Exits the program. |

You can use the commands in a more understandable way with the user-friendly application that makes these tasks easier.