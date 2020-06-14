#ifndef PROTO_H
#define PROTO_H

#include <stdint.h>
// 客户端和服务端协议
#define RGS_SERVER_IP "192.168.1.101"
#define RGS_SERVER_PORT 1100
#define CNTSIZE 20
#define PWDSIZE 128

enum {
    RGS_OK,
    RGS_EXISTS,
    RGS_ERROR
};

typedef struct{
    char cnt[CNTSIZE];
    char pwd[PWDSIZE];
    int8_t reg_state;

}reg_t;
#endif // PROTO_H
