#ifndef SESSION_HPP
#define SESSION_HPP

class Session {
    public:
        int user;
        char* username;
        int creationDate;

        void SetUser(int user);
};

#endif