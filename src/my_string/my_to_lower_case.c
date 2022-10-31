char* my_to_lower_case(char* str) {
    
    int index = 0;
    while(str[index] != '\0') { 
        if(str[index] >= 'A' && str[index] <= 'Z') {
            str[index] = str[index] + ' ';
        } 
        index += 1;
    }
    return str;
}