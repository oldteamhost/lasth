#ifdef __cplusplus
extern "C" {
#endif

// lib curl
long standart_get_responce_code(const char* node, int proxy_on, const char* proxy);

// custom delay cross platform :)
void delay_ms(int milliseconds);

#ifdef __cplusplus
}
#endif
