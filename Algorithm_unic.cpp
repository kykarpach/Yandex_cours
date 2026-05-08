    
template <typename Iter>
Iter Unique(Iter first, Iter last){
    
    if(first == last){
        return last;
    }

    Iter read = first;
    Iter write = first;
    
    ++read;
    ++write; 

    while(read != last){
        
        if(*read == *first){
            ++read;
        }
        else{
            *write = *read;
            first = write;
            ++read;
            ++write;
        }
    }

    return write;
}
