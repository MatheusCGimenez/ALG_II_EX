#include <stdio.h>

int stringContem(const char *stringPrincipal, const char *substring) {
    const char *ptrPrincipal = stringPrincipal;
    const char *ptrSubstring = substring;

    if (*ptrSubstring == '\0') {
        return 1;
    }

    while (*ptrPrincipal != '\0') {
        const char *tempPrincipal = ptrPrincipal;
        const char *tempSubstring = ptrSubstring;

        while (*tempSubstring != '\0' && *tempPrincipal == *tempSubstring) {
            tempPrincipal++;
            tempSubstring++;
        }

        if (*tempSubstring == '\0') {
            return 1;
        }

        ptrPrincipal++;
    }

    return 0;
}

int main() {
    char str1[] = "programacao em c";
    char str2[] = "em c";
    char str3[] = "sla";
    char str4[] = "pro sla";

    printf("'%s' contem '%s'? %s\n", str1, str2, stringContem(str1, str2) ? "Sim" : "Nao");
    printf("'%s' contem '%s'? %s\n", str1, str3, stringContem(str1, str3) ? "Sim" : "Nao");
    printf("'%s' contem '%s'? %s\n", str1, str4, stringContem(str1, str4) ? "Sim" : "Nao");
    printf("'%s' contem '%s'? %s\n", str1, "", stringContem(str1, "") ? "Sim" : "Nao");
    printf("'' contem '%s'? %s\n", str2, stringContem("", str2) ? "Sim" : "Nao");

    return 0;
}