#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/netdevice.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>


char *get_publicip();
//char *get_localip();

extern char* g_publicip;

struct publicip_cache{
        int key;
        char *value;
};

extern struct publicip_cache pcache;
