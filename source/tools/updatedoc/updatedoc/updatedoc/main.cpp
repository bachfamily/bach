//
//  main.cpp
//  updatedoc
//
//  Created by Daniele Ghisi on 07/10/2018.
//  Copyright © 2018 Daniele Ghisi. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <dirent.h>


bool replace_parenthesis(char *buf)
{
    long len = strlen(buf);
    bool replaced = false;
    for (long i = 0; i < len; i++) {
        if (buf[i] == '(') { buf[i] = '['; replaced = true; }
        else if (buf[i] == ')') { buf[i] = ']'; replaced = true; }
    }
    return replaced;
}

char *ltrim(char *buf)
{
    long offset = 0;
    char c = 0;
    while ((c = *(buf+offset)) != 0) {
        if (!(c == ' ' || c == '\t'))
            break;
        offset++;
    }
    return buf+offset;
}

long process_file(const char *path)
{
    long num_subs = 0;
    
    FILE *fp = fopen(path, "r+");
    if (fp == NULL) {
        printf("Unable to open file %s!\n", path);
        return 0;
    }
    
    int len = 2047;
    long position_in_file;
    // need malloc memory for line, if not, segmentation fault error will occurred.
    char *line = (char *)malloc(sizeof(char) * len);
    char in_message_or_textedit = false;
    
    while(fgets(line, len, fp) != NULL) {
        char *linetrim = ltrim(line);
        if (in_message_or_textedit) {
            if (!strcmp(linetrim, "}\n")) {
                in_message_or_textedit = false;
            } else if (!strncmp(linetrim, "\"text\" : ", 9)) {
                if (replace_parenthesis(line)) {
                    num_subs++;
                    fseek(fp,position_in_file,SEEK_SET);
                    fprintf(fp, "%s", line);
/*                    position_in_file = ftell(fp);
                    fseek(fp,position_in_file,SEEK_SET);*/
                }
            }
        } else {
            if (!strcmp(linetrim, "\"maxclass\" : \"message\",\n") || !strcmp(linetrim, "\"maxclass\" : \"textedit\",\n")) {
                in_message_or_textedit = true;
            }
        }
        position_in_file = ftell(fp);
    }
    
    free(line);
    fclose(fp);
    
    return num_subs;
}

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) return "";
    return dot + 1;
}

long process_folder(const char *path, const char *ext1, const char *ext2)
{
    long tot_num_subs = 0;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            if ((!ext1 || !strcmp(get_filename_ext(ent->d_name), ext1)) || (!ext2 || !strcmp(get_filename_ext(ent->d_name), ext2))) {
                char fullpath[PATH_MAX];
                sprintf(fullpath, "%s/%s", path, ent->d_name);
                long num_subs = process_file(fullpath);
                printf("Processed file %s: %ld message/textedit conversions.\n", ent->d_name, num_subs);
                tot_num_subs += num_subs;
            }
        }
        closedir (dir);
    } else {
        printf("Error opening folder %s.\n", path);
    }
    
    return tot_num_subs;
}

int main(int argc, const char * argv[])
{
    long tot_num_subs = 0;
    
//    tot_num_subs += process_folder("/Users/danieleghisi/Documents/Max 7/Packages/bach/help", "maxhelp", "maxpat");
//    tot_num_subs += process_folder("/Users/danieleghisi/Documents/Max 7/Packages/bach/docs/tutorial-patchers", "maxhelp", "maxpat");

//    tot_num_subs += process_folder("/Users/danieleghisi/Documents/Max 7/Packages/cage/docs/tutorial-patchers/cage-tut", "maxhelp", "maxpat");
//    tot_num_subs += process_folder("/Users/danieleghisi/Documents/Max 7/Packages/cage/help", "maxhelp", "maxpat");

    tot_num_subs += process_folder("/Users/danieleghisi/Documents/Max 7/Packages/dada/help", "maxhelp", "maxpat");

    
    printf("END OF JOB: %ld conversions performed.\n", tot_num_subs);
    
    return 0;
}
