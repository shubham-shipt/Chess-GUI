#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>
#include <string>

int pipin_w[2], pipin_r[2], pipout_w[2], pipout_r[2];
pid_t pid;
char buffer[2048];

void ConnectToEngine(char* path)
{
    pipe(pipin_w);
    pipe(pipin_r);
    pipe(pipout_w);
    pipe(pipout_r);

    pid = fork();
    if (pid == 0) {
        dup2(pipin_w[0], STDIN_FILENO);
        dup2(pipout_r[1], STDOUT_FILENO);
        dup2(pipout_r[1], STDERR_FILENO);

        execl(path, path, NULL);
        exit(0);
    }
}

std::string getNextMove(std::string position)
{
    std::string str;
    position = "position startpos moves " + position + "\ngo\n";

    write(pipin_w[1], position.c_str(), position.length());
    usleep(500000); // 500ms delay

    while (true) {
        int bytesRead = read(pipout_r[0], buffer, sizeof(buffer));
        if (bytesRead <= 0) break;
        buffer[bytesRead] = 0;
        str += buffer;
    }

    int n = str.find("bestmove");
    if (n != -1) return str.substr(n + 9, 4);

    return "error";
}

void CloseConnection()
{
    write(pipin_w[1], "quit\n", 5);
    close(pipin_w[1]);
    close(pipin_r[0]);
    close(pipout_w[1]);
    close(pipout_r[0]);
    waitpid(pid, NULL, 0);
}

#endif
