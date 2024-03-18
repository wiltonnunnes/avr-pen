#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int open_port(const char *portname) {
    int fd;
    fd = open(portname, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1)
        perror("open_port: Unable to open port - ");
    else
        fcntl(fd, F_SETFL, 0);
    return fd;
}

int main() {
    int port;
    port = open_port("/dev/ttyACM0");

    char buf[255];
    int n = read(port, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        return -1;
    }

    close(port);
    return 0;
}