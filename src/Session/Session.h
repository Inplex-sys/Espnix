#ifndef SESSION_HP
#define SESSION_HP

class Session {
    public:
        int user;
        char* username;
        int creationDate;

        void SetUser(int user);
};

#endif