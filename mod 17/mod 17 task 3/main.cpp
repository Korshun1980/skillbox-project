#include <iostream>
bool substr (char* a, char* x) {
    bool checkbox = false;
   for (int i = 0; *(a + i) != '\0' && !checkbox; ++i){
       if (*(a + i) == *x) {
           for (int j = 0; *(x + j) != '\0'; ++j) {
               if (*(a + (i + j)) != *(x + j)) {
                   checkbox = false;
                   break;
               }
               checkbox = true;
           }
       }
   } return checkbox;
}

int main() {
    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";

    std::cout << substr(a,b) << " " <<substr(a,c);
    return 0;
}
