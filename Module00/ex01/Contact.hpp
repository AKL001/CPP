#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

/* Using  Constuctor for inialization , also using the 
inilization lists syntax */
class Contact 
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _darkestsecret;
        std::string _phonenumber;
    
    public:
    // defining default Constuctor . dont make the implementation here  cuase the linker wont know that , this means its defined but the linker need to look for it in the (.cpp) file.
    // need inline for the compiler (linker to indentify it)
    Contact()
    {

    };

    Contact(const std::string& firstname, const std::string& lastname,
            const std::string& nickname, const std::string& ds,
            const std::string& phonenumber)
        : _firstname(firstname), _lastname(lastname), _nickname(nickname),
          _darkestsecret(ds), _phonenumber(phonenumber)
    {}
    // Destructor definition 
    ~Contact();

    /* getters */
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickName() const;
    const std::string &getDarkestSecret() const;
    const std::string &getPhoneNumber() const;

    /* setters */
    // first name setter
    void setFirstName(std::string firstname);
    void setLastName(std::string lastname);
    void setNickName(std::string nickname);
    void setDarkestSecret(std::string darkestsecret);
    void setPhoneNumber(std::string phonenumber);


    void display() const;


};


#endif