#include "Person.h"

Person::Person(const std::string& strName, double dBalance, int nMobile, int nAccount)
    : IExercise(), m_strName{strName}, m_dBalance{dBalance}, m_nMobileNumber{nMobile},
      m_nAccountNumber{nAccount}
{
}

///
/// \brief Setters for Person.
/// \param name, balance, mobile number, account number.
///
void Person::SetName(const std::string& name) {m_strName = name;}

void Person::SetBalance(double dBalance) {m_dBalance = dBalance;}

void Person::SetMobileNumber(int nNewNumber) {m_nMobileNumber = nNewNumber;}

void Person::SetAccountNumber(int nAccountNumber) {m_nAccountNumber = nAccountNumber;}

///
/// \brief Getters for Person
///
const std::string& Person::GetName() const {return m_strName;}

double Person::GetBalance() const {return m_dBalance;}

int Person::GetMobileNumber() const {return m_nMobileNumber;}

int Person::GetAccountNumber() const {return m_nAccountNumber;}
///
///  End Getters and Setters
///

void Person::PrintName() {std::cout << "Hello, I am " << m_strName << "\n";}

void Person::RunExercise()
{
    std::string strFirstName, strLastName, strFullName;
    std::cout << "Insert your first name: \n";
    std::getline(std::cin, strFirstName);
    std::cout << "Insert your last name: \n";
    std::getline(std::cin, strLastName);
    strFullName = strFirstName + " " + strLastName;

    SetName(strFullName);
    PrintName();
    // std::cout<<"Your name is: " <<strFirstName <<" "<< strLastName<<"\n";
}


///
/// \brief Read XML file with Users and fill a vector with objects.
/// \return *true* if Users.xml is found, else *false*.
///
void Person::ParseXML(const pugi::xml_node& user)
{
    //this person (p)
    for (pugi::xml_attribute attr = user.first_attribute(); attr;
         attr = attr.next_attribute())
    {
        // std::cout << " " << attr.name() << " = " << attr.value() << "\n";
        m_strName = user.attribute("name").as_string();
        m_dBalance = user.attribute("balance").as_double();
        m_nMobileNumber = user.attribute("mobile").as_int();
        m_nAccountNumber = user.attribute("accountNumber").as_int();
    }
}
