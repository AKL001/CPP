#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact 
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _darkestsecret;
        std::string _phonenumber;
    
    public:
    /* Using  Constuctor for inialization , also using the inilization lists syntax */
        Contact(std::string firstname,std::string lastname,std::string nickname,std::string ds ,std::string phonenumber) : _firstname(firstname) , _lastname(lastname) ,_nickname(nickname) , _darkestsecret(ds) , _phonenumber(phonenumber)
        {}

    /* getters */
    std::string getFirstName() {return _firstname;}
    std::string getLastName() {return _lastname;}
    std::string getNickName() {return _nickname;}
    std::string getDarkestSecret() {return _darkestsecret;}
    std::string getPhoneNumber() {return _phonenumber;}

    /* setters */
    // first name setter
    void setFirstName(std::string firstname)
    {
        _firstname = firstname;
    }
    void setLastName(std::string lastname)
    {
        _lastname =  lastname;
    }
    void setNickName(std::string nickname)
    {
        _nickname = nickname;
    }
    void setDarkestSecret(std::string darkestsecret)
    {
        _darkestsecret = darkestsecret;
    }
    void setPhoneNumber(std::string phonenumber)
    {
        _phonenumber = phonenumber;
    }

    
};


#endif