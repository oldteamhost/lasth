#ifdef __cplusplus
extern "C" {
#endif

// html
int download_page_html(const char* node, const char* html_path);

// main
int init_data_folder();
void init_main_folders();

// txt
int write_main_info_to_file(const char* path, const char* line);
int write_line_to_file(const char *path, const char *line);

#ifdef __cplusplus
}
#endif

