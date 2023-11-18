# MSKN'E HOŞGELDİNİZ! ✨

### MENÜ

Uygulama çalıştığında sizi bir menü karşılayacak:

![](https://github.com/MertGursimsir/mskn/blob/main/MEDIA/image.png)

Bu menüden güncel versiyon için 17 seçim yapabilirsiniz. Bu seçimler ve arka planda çalışan komutlar şu şekildedir:

| Seçim | Komut |
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
| 17 | Programı sonlandırır. |

Bu işleri kolaylaştıran kullanıcı dostu uygulama ile komutları daha anlaşılabilir bir şekilde kullanabilirsiniz.