//q1
// hint - USE T CAUSE ITS MULTIPLE TYPES 
template <typename T>
vector<T> checking_ints(const string& file_of_ints,const vector<double> & nums_to_ignore){ 
    vector<T> wout_ignored_ints;
    T file_num
    bool continue_read = true; 

    string file_info;
    ifstream input(file_of_ints);

    if(!file.is_open()){ 
        throw run_time("didnt open");
    }

    while(continue_read){
        file >> file_num; 

        if(file_of_ints.eof()){
            continue_read = false; 
            throw run_time("end of file in loop?");
        }
        
        if(file_of_ints.fail()){
            continue_read = false; 
            throw run_time("file sucks, it failed");
        }

        for(unsigned int i = 0; i < nums_to_ignore.size(); ++i){
            if(nums_to_ignore.at(i) != file_num){
                wout_ignored_ints.push_back(file_num);
            }
        }

        if(file_of_ints.eof()){
            continue_read = false; 
        }

        file.close();
    }
}

