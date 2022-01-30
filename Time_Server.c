#include<stdio.h>
#include<string.h>    // for strlen
#include<sys/socket.h>
#include<arpa/inet.h> // for inet_addr
#include<unistd.h>    // for write
#include<time.h>  
#include<ctype.h>  

int main(int argc, char *argv[])
{
    int socketDesc , newSocket , c;
    struct sockaddr_in server , client;
    char *message, request[1000], temp[1000], buf[1000];
    char *tok1, *tok2, *token;
    struct tm* tmPtr;
    time_t t;

    
    // Create socket
    socketDesc = socket(AF_INET, SOCK_STREAM, 0);
    
    if (socketDesc == -1)
    {
        puts("Could not create socket");
        return 1;
    }
     
    server.sin_family = AF_INET;  
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888); 
     
    
    if(bind(socketDesc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Binding failed");
        return 1;
    }
    puts("Socket is binded");
     
    // Listen
    listen(socketDesc, 1);
     
    // Accept and incoming connection
    puts("Waiting for incoming connections...");
    
    c = sizeof(struct sockaddr_in);
    newSocket= accept(socketDesc,(struct sockaddr *)&client,(socklen_t*)&c);

    if (newSocket<0)
    {
        puts("Accept failed");
        return 1;
    }
     
    puts("Connection accepted");
    int times = 5;                  //While loop 
    while(times >  0)
    {
        message = "Enter the request: \n";
        write(newSocket,message,strlen(message));       //Write to telnet console.
        read(newSocket,request,sizeof(request));        //Read from telnet console.  
        strcpy(temp,request);

        //https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
        
        token = strtok(temp, "  ");
        tok1 = token;
        
        while(token != NULL){
            token = strtok(NULL, "  ");
            if(token != NULL){
                tok2 = token;
            }
        }

        
        if(strcmp(tok1,"GET_DATE") == 0){

            
            if(strstr(tok2,"%%") != NULL){          //If token2 contains string.
                
                message = "1-Incorrect request.\n\n";
                write(newSocket,message,strlen(message));
            }
			t = time(NULL);
            tmPtr = localtime(&t);
            else if(strstr(tok2,"%Y/%m/%d-%H:%M:%S") != NULL){    
                
                strftime(buf,sizeof(buf),"%Y/%m/%d-%H:%M:%S", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%H:%M:%S") != NULL){    
               
                strftime(buf,sizeof(buf),"%H:%M:%S", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%a") != NULL){      
               
                strftime(buf,sizeof(buf),"%a", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%A") != NULL){      
                
                strftime(buf,sizeof(buf),"%A", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%b") != NULL){      
                
                strftime(buf,sizeof(buf),"%b", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%B") != NULL){      
                
                strftime(buf,sizeof(buf),"%B", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%c") != NULL){      
                
                message = asctime(tmPtr);
                write(newSocket,message,strlen(message));
            }
            else if(strstr(tok2,"%C") != NULL){      
                
                strftime(buf,sizeof(buf),"%C", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%d") != NULL){      
             
                strftime(buf,sizeof(buf),"%d", tmPtr);
                write(newSocket,buf,strlen(buf));
                
            }
            else if(strstr(tok2,"%D") != NULL){      
                
                strftime(buf,sizeof(buf),"%D", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%e") != NULL){      
                
                strftime(buf,sizeof(buf),"%e", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%F") != NULL){      
                
                strftime(buf,sizeof(buf),"%F", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%g") != NULL){      
                
                strftime(buf,sizeof(buf),"%g", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%G") != NULL){      
                
                strftime(buf,sizeof(buf),"%G", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%h") != NULL){      
                
                strftime(buf,sizeof(buf),"%h", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%H") != NULL){      
                
                strftime(buf,sizeof(buf),"%H", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%I") != NULL){      
                
                strftime(buf,sizeof(buf),"%I", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%j") != NULL){      
               
                strftime(buf,sizeof(buf),"%j", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%k") != NULL){      
                
                strftime(buf,sizeof(buf),"%k", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%l") != NULL){      
                
                strftime(buf,sizeof(buf),"%l", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%m") != NULL){      
                
                strftime(buf,sizeof(buf),"%m", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%M") != NULL){      
                
                strftime(buf,sizeof(buf),"%M", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%n") != NULL){      
                message = "\n";
                write(newSocket,message,strlen(message));
            }
            else if(strstr(tok2,"%N") != NULL){      
                
                strftime(buf,sizeof(buf),"%N", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%p") != NULL){      
                
                strftime(buf,sizeof(buf),"%p", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%P") != NULL){      
                
                strftime(buf,sizeof(buf),"%P", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%q") != NULL){      
                
                int m = tmPtr->tm_mon;
                m += 1;
                int q = 0;
                if(1 <= m && m <= 3){
                    q = 1;
                }
                else if(4 <= m && m <= 6){
                    q = 2;
                }
                else if(7 <= m && m <= 9){
                    q = 3;
                }
                else if(10 <= m && m <= 12){
                    q = 4;
                }
                snprintf(buf,sizeof(buf),"%d",q);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%r") != NULL){      
                
                strftime(buf,sizeof(buf),"%I:%M:%S %p", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%R") != NULL){      
                
                strftime(buf,sizeof(buf),"%H:%M", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%s") != NULL){      
                
                strftime(buf,sizeof(buf),"%s", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%S") != NULL){      
              
                strftime(buf,sizeof(buf),"%S", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%t") != NULL){      
                message = "\t";
                write(newSocket,message,strlen(message));
            }
            else if(strstr(tok2,"%T") != NULL){      
                
                strftime(buf,sizeof(buf),"%H:%M:%S", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%u") != NULL){      
                
                strftime(buf,sizeof(buf),"%u", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%U") != NULL){   
                
                strftime(buf,sizeof(buf),"%U", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%V") != NULL){      
                 
                strftime(buf,sizeof(buf),"%V", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%w") != NULL){      
                
                int w = tmPtr->tm_wday;
                snprintf(buf,sizeof(buf),"%d",w);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%W") != NULL){      
                  
                strftime(buf,sizeof(buf),"%W", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%x") != NULL){      
                   
                strftime(buf,sizeof(buf),"%m/%d/%y", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%X") != NULL){      
                   
                strftime(buf,sizeof(buf),"%H:%M:%S", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%y") != NULL){      
                 
                strftime(buf,sizeof(buf),"%y", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%Y") != NULL){      
                 
                strftime(buf,sizeof(buf),"%Y", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%z") != NULL){      
                  
                strftime(buf,sizeof(buf),"%z", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
             else if(strstr(tok2,"%:z") != NULL){      
                 
                strftime(buf,sizeof(buf),"%:z", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%::z") != NULL){      
                  
                strftime(buf,sizeof(buf),"%::z", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
              else if(strstr(tok2,"%:::z") != NULL){      
                  
                strftime(buf,sizeof(buf),"%:::z", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
            else if(strstr(tok2,"%Z") != NULL){      
                  
                strftime(buf,sizeof(buf),"%Z", tmPtr);
                write(newSocket,buf,strlen(buf));
            }
           
        }
        else{
            message = "Incorrect request.\n\n";
            write(newSocket,message,strlen(message));
        }
        
        message = "\n";
        write(newSocket,message,strlen(message));
        times -= 1;
        
    }  

    close(socketDesc);
    close(newSocket); 

    return 0;
}

