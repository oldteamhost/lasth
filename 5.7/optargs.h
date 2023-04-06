
struct opt_args{
    char* target; // target aka name
    const char* path_base; // path from base url
    const char* html_path;
    const char* proxy; // proxy
    const char* timeout; // timeout ms
    const char* txt_path;
    int code_custom; // custom valid code

    // ON or OFF
    int txt_active; 
    int html_active;
    int path_active;
    int proxy_active;
    int timeout_active;
    int fast_active;
    int code_active;
    int debug_active;
};
