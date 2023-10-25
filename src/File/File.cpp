#include <File/File.hpp>

char* readFile(const char* path) {
    if(fileSize(path) == 0) return nullptr;

    // usendim amina koyim stacke koyup io islemlerini azaltmaya
    char* content = (char*)malloc(fileSize(path));

    FILE* fp = fopen(path, "r");

    fread(content, fileSize(path), 1, fp);
    
    fclose(fp);

    return content;
}

inline uint fileSize(const char* path) {
    FILE *fp = fopen(path, "r");

    if(!fp) {
        printf("fileSize() Error\n\r");
        return 0;
    }
    fseek(fp, 0, SEEK_END);

    uint returnSize = ftell(fp);
    fclose(fp);

    return returnSize;
}