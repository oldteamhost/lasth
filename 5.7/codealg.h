#ifdef __cplusplus
extern "C" {
#endif

// lib curl
long standart_get_responce_code(const char* node, int proxy_on, const char* proxy);

// custom delay cross platform :)
void delay_ms(int milliseconds);

// check net
void check_net(void);
void check_proxy(const char* proxy);

#ifdef __cplusplus
}
#endif
