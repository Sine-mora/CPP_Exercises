#include "ATM.h"



ATM::ATM() : m_user{}
{
    std::cout << "\nATM()\n";
    Test = [& /*this = &*/](int a, int b)
    {
        m_user.GetName();
        std::cout << "This is number: " <<a+b<<"\n";
        return a+b;
    };

    m_Comparator = [](const Person& a, const Person& b)
    {
        return a.GetBalance() > b.GetBalance();
    };
}

void ATM::Initialize()
{
    std::vector<std::function<int(int a, int b)>> vecTest={};
    vecTest.push_back(Test);
    std::cout <<"Result "<<vecTest.at(0)(5,2) <<"\n";

    FillVectorOfUsers();
    std::cout << "\n ATM Users Initializing..\n";
    std::sort(m_vUsers.begin(), m_vUsers.end(), m_Comparator);
    PrintUsers();
}

void ATM::RunExercise()
{
    std::cout << "\nATM Run Exercise\n";
    Initialize();
}

void ATM::ATMMenu()
{
    //Initialize;
    // std::vector<std::shared_ptr<void(*)()>>vFunctions={};
    // vFunctions.push_back();
}

void CheckBalance()
{
}

void CashWithDraw()
{
}

void ATM::FillVectorOfUsers()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("../src/xml/Users.xml");

    if (!result)
    {
        std::cerr << "\nFailed to load Users.xml\n";
        return;
    }

    const pugi::xml_node& users = doc.child("Users");

    std::cout << "Load result: " << result.description();

    for (pugi::xml_node user = users.first_child(); user; user = user.next_sibling())
    {
        Person p;
        p.ParseXML(user);
        m_vUsers.emplace_back(p);
    }
    std::cout << "\nFinished parsing.\n";
}

void ATM::PrintUsers()
{
    for (auto& m_vUser : m_vUsers)
    {
        std::cout << "\nUser:\nName: " << m_vUser.GetName();
        std::cout << "\nBalance: " << m_vUser.GetBalance();
        std::cout << "\nMobile: " << m_vUser.GetMobileNumber();
        std::cout << "\nAccount: " << m_vUser.GetAccountNumber() << "\n";
    }
}
