//
//  fileid.hpp
//  bach
//
//  Created by Andrea Agostini on 04/10/2019.
//

#ifndef fileid_h
#define fileid_h

#include <unordered_set>

struct t_fileid {
    short path;
    std::string name;
    
    t_fileid(const short path, const std::string& name) : path(path), name(name) { };
    t_fileid(const short path, const char* name) : path(path), name(name) { };
    t_fileid() { };
    
    inline bool operator==(const t_fileid& b) const {
        return path == b.path && name == b.name;
    };
    
    inline bool operator!=(const t_fileid& b) const {
        return !(*this == b);
    };
};

struct hash_fileid {
    size_t operator()(const t_fileid &fileid) const {
        return std::hash<std::string>()(fileid.name) ^ fileid.path;
    }
};

typedef std::unordered_set<t_fileid, hash_fileid> fileidSet;

#endif /* fileid_h */
