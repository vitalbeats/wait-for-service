#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char ** argv) {
    printf("Waiting for %s\n", argv[1]);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));

    while (getaddrinfo(argv[1], NULL, &hints, &result) != 0) {
        printf("%s not found, waiting ...\n", argv[1]);
        sleep(2);
    }
    printf("%s is available\n", argv[1]);
    return 0;
}
