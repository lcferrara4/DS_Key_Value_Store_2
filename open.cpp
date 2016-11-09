// open.cpp: Open Addressing Map

#include "map.h"

#include <stdexcept>

// Methods --------------------------------------------------------------------


void            OpenMap::insert(const std::string &key, const std::string &value) {
        
        if(curr_size + 1 / table_size >= load_factor || curr_size + 1 >= table_size){
            resize(table_size * (4/3)); 
        }
        size_t index = locate(key); 
        entries[index] = std::make_pair(key, value); 
        curr_size++; 
}

const Entry     OpenMap::search(const std::string &key) {
    
    for(auto i = 0; i<table_size; i++){
        if(entries[i].first == key){
            return entries[i]; 
        }
    }
    
    return NONE;
}

void            OpenMap::dump(std::ostream &os, DumpFlag flag) 
{

    for(auto i = 0; i<table_size; i++){
            switch (flag) {
                case DUMP_KEY:          os << entries[i].first  << std::endl; break;
                case DUMP_VALUE:        os << entries[i].second << std::endl; break;
                case DUMP_KEY_VALUE:    os << entries[i].first  << "\t" << entries[i].second << std::endl; break;
                case DUMP_VALUE_KEY:    os << entries[i].second << "\t" << entries[i].first  << std::endl; break;
            }
    }


}

size_t          OpenMap::locate(const std::string &key) {
    
    size_t index = hfunc(key) % table_size; 
    
    while(entries[index] != NONE && entries[index].first != key){
        index++; 
        if(index == table_size){
            index =0; 
        }
        
    }
    
return index;
}

void            OpenMap::resize(const size_t new_size) {

 
    size_t index; 
    size_t old_size = table_size; 
    table_size = new_size; 
    
    Entry * temp = entries;  
    
    entries = new Entry[new_size]; 
    
    for(auto i=0; i<old_size; i++){
        index = locate(temp[i].first); 
        entries[index] = std::make_pair(temp[i].first, temp[i].second); 
    }

    delete [] temp; 

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
