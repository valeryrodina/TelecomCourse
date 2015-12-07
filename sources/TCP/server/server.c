#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char name[10][10];
char messages[10][200];
int message_counter = 0;

int main()

{
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(6312);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    const int on = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) {
           perror("setsockopt");
           exit(2);
       }
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(3);
    }

    listen(listener, 1);

    while(1)
    {
        sock = accept(listener, 0,0 );
        if(sock < 0)
        {
            perror("accept");
            exit(4);
        }

        while(1)
        {
            memset(buf, 0, 1024);
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break;
            printf("%s", buf);
            if(buf[0] == 's'){
                puts("отправляю сообщение");
                strncpy(name[message_counter], buf+1, 10);
                strncpy(messages[message_counter], buf+11, 200);
                message_counter++;
            }
            else if(buf[0] == 'r'){
                puts("читаем сообщения");
                int i;
                for(i = 0; i< 10; i++){
                    if(strncmp(buf+1, name[i], 10) == 0){
                        printf("Для ", name[i], messages[i]); //????? вывести, кому письмо
                        send(sock, messages[i], 200, 0);
                    }
                }
            }
            else if(buf[0] == 'i'){
                puts("хотим получить информацию о почтовом ящике");
                int i,j;
                for(i = 0; i< 10; i++){
                    for (j = 0; j < 10; j++) {
                    if(strncmp(buf+1, name[i], 10) == 0){
                        printf("В вашем почтовом ящике: ", i, " писем" ); //?
                        printf(j+1 ,"письмо: ", messages[i]);
                        j++;
                        send(sock, messages[i], 200, 0);
            }
                }
            }
                    }
            else
                puts("команда не распознана");


        }

        close(sock);

    }

    return 0;
}

