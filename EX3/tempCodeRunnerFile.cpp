    char s[1000] = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";
    char *p = strtok(s, " ");
    do {
        for (int i = 0; i <= 35; i++) {
            if (!strcmp(p, morse[i])) {
                cout << "Ki tu p: " << p << endl ;
                // cout << " Ki tu: " << characters[i] << endl ;
                // cout <<  "Ma Morse:" << morse[i] << endl;
                cout << characters[i];
            } 
        }
        p = strtok(NULL, " ");
    } while (p != NULL); 