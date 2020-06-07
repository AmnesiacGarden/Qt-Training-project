#ifndef PROTO_H
#define PROTO_H

#include <stdint.h>
// 客户端和服务端协议
#define RGS_SERVER_IP "192.168.137.1"
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

//登录协议
#define LOGIN_SERVER_IP "192.168.137.1"
#define LOGIN_SERVER_PORT 1101

enum {
    LOGIN_OK,
    LOGIN_NOTEXISTS,
    LOGIN_ERRORPW
};

typedef struct{
    char cnt[CNTSIZE];
    char pwd[PWDSIZE];
    int8_t login_state;

}login_t;
#endif // PROTO_H
