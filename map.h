// map.h

#pragma once

// Includes --------------------------------------------------------------------

#include <iostream>
#include <functional>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>

// Type definitions ------------------------------------------------------------

typedef enum {
    DUMP_KEY,
    DUMP_VALUE,
    DUMP_KEY_VALUE,
    DUMP_VALUE_KEY,
} DumpFlag;

typedef std::pair<std::string, std::string> Entry;
typedef std::hash<std::string>              StringHasher;

// Constants -------------------------------------------------------------------

extern const Entry  NONE;
extern const double DEFAULT_LOAD_FACTOR;
extern const size_t DEFAULT_TABLE_SIZE;

// Structures ------------------------------------------------------------------

struct Node {
    Entry entry;
    int   priority;
    Node *left;
    Node *right;

    ~Node() {
        delete left;
        delete right;
    }
};

// Classes ---------------------------------------------------------------------

class Map {
public:
    virtual void            insert(const std::string &key, const std::string &value) {}
    virtual const Entry     search(const std::string &key) { return NONE; }
    virtual void            dump(std::ostream &os, DumpFlag flag) {}
    virtual                ~Map() {}
};

class UnsortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::vector<Entry>    entries;
};

class SortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::vector<Entry>    entries;
};

class BSTMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
                           ~BSTMap() { delete root; }
private:
            Node    *root = nullptr;
};

class RBTreeMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::map<std::string, std::string> entries;
};

class TreapMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
                           ~TreapMap() { delete root; }
private:
            Node    *root = nullptr;
};

class UnorderedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::unordered_map<std::string, std::string> entries; 
};

class ChainedMap : public Map {
public:
            ChainedMap(double load_factor, size_t table_size){
                load_factor = load_factor; 
                table_size = table_size; 
                entries = new std::map<std::string, std::string> [table_size];   
                curr_size = 0; 
            } // nondefault
            ChainedMap(){
                load_factor = DEFAULT_LOAD_FACTOR; 
                table_size = DEFAULT_TABLE_SIZE; 
                entries = new std::map<std::string, std::string> [table_size]; 
                curr_size = 0; 
            }
            ~ChainedMap(){
                delete [] entries; 
            }
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);

private:
            void            resize(const size_t new_size);
            StringHasher    hfunc; 
            size_t table_size; 
            std::map<std::string, std::string> *entries;
            size_t curr_size; 
            double load_factor; 
};

class OpenMap : public Map {
public:
            OpenMap(double load_factor, size_t table_size){
                load_factor = load_factor; 
                table_size = table_size; 
                entries = new Entry[table_size]; 
                curr_size = 0; 
            } // nondefault
            OpenMap(){
                load_factor = DEFAULT_LOAD_FACTOR; 
                table_size = DEFAULT_TABLE_SIZE; 
                entries = new Entry[table_size]; 
                curr_size = 0; 
            }
            ~OpenMap(){
                delete [] entries; 
            }
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);


private:
            size_t table_size; 
            size_t curr_size; 
            double load_factor; 
            size_t          locate(const std::string &key);
            void            resize(const size_t new_size);
            StringHasher    hfunc; 
            Entry *entries; 
};

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
