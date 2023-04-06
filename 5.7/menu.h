#define VERSION "5.7" 

#ifdef __cplusplus
extern "C" {
#endif

char* version(void);
void waring_timeout(void);
void file_not_found(const char* file_name);
void no_net(void);
void no_proxy(void);

#ifdef __cplusplus
}
#endif
