

int my_isalnum(char ch) {

    if((ch > 64 && ch < 91) || (ch > 96 && ch < 123) ||(ch > 47 && ch < 58)){
        return 1;
    }

    return 0 ;
}