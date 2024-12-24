#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <pwd.h>


void sigusr1_handler(int signo) {
    pid_t sender_pid = getpid();  
    uid_t sender_uid = getuid();  
    struct passwd* pw = getpwuid(sender_uid);
    const char* sender_user = pw ? pw->pw_name : "Unknown";

    std::cout << "Received a SIGUSR1 signal from process " << sender_pid
        << " executed by " << sender_uid << " (" << sender_user << ").\n";
}

int main() {
    pid_t pid = getpid();
    std::cout << "PID of this process: " << pid << std::endl;

    
    signal(SIGUSR1, sigusr1_handler);  

    
    while (true) {
        sleep(10);  
    }

    return 0;
}

