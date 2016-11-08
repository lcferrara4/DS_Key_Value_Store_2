// chained.cpp: Separate Chaining Map

#include "map.h"

#include <stdexcept>

// Methods --------------------------------------------------------------------

void            ChainedMap::insert(const std::string &key, const std::string &value) {
        
        if(curr_size + 1 / table_size == load_factor){
            resize(table_size * (4/3)); 
        }
        size_t index = hfunc(key) % table_size; 
        
        entries[index][key] = value; 
        curr_size++; 

}

const Entry     ChainedMap::search(const std::string &key) {
         
        size_t index = hfunc(key) % table_size; 
        for(auto it = entries[index].begin(); it != entries[index].end(); it++){
            if (it->first == key){
                return *it; 
            }
        }
    
        return NONE;
}

void            ChainedMap::dump(std::ostream &os, DumpFlag flag) {
    
    for(auto i = 0; i<table_size; i++){
        for (auto it = entries[i].begin(); it != entries[i].end(); it++) {
            switch (flag) {
                case DUMP_KEY:          os << it->first  << std::endl; break;
                case DUMP_VALUE:        os << it->second << std::endl; break;
                case DUMP_KEY_VALUE:    os << it->first  << "\t" << it->second << std::endl; break;
                case DUMP_VALUE_KEY:    os << it->second << "\t" << it->first  << std::endl; break;
            }
        }
    }
}

void            ChainedMap::resize(const size_t new_size) {
        
        size_t index; 
        std::map<std::string, std::string> * temp = new std::map<std::string, std::string> [new_size]; 
        
        for(auto i = 0; i<table_size; i++){
            for(auto it = entries[i].begin(); it != entries[i].end(); it++){
                index = hfunc(it->first) % new_size; 
                temp[index][it->first] = it->second;  
            }
        }
        delete [] entries; 
        entries = temp; 
        delete [] temp; 
        table_size = new_size; 

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
