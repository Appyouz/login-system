#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <stdlib.h>


// global name and password 
std::string g_name;
std::string g_password;

class Admin{
private:
  std::string m_name{};
  std::string m_password{};

public:
  Admin() = default;
  Admin(std::string_view name, std::string_view password)
    :m_name {name}, m_password{password} {}

  std::string getName(){return m_name;}
  std::string getPassword(){return m_password;}

  void setName(std::string_view name){
    m_name = name;
  }

  void setPassword(std::string_view password){
    m_password = password;
  }
};

void userRegister(Admin& admin)
{
  std::cout << '\n';
  std::cout << "enter your name:";
  std::cin >> g_name;
  std::cout << "enter your password:";
  std::cin >> g_password;

  admin.setName(g_name);
  admin.setPassword(g_password);
 
  std::fstream myFile;
  myFile.open("file.txt", std::ios::out);
  if (myFile.is_open()) {
    myFile << admin.getName() << ", " << admin.getPassword();
    myFile.close();
  }
}

void validation(Admin admin){
  std::string name{};
  std::string password {};
  std::cout << "username:";
  std::cin >> name;
  std::cout << "password:";
  std::cin >> password;
 
  if (admin.getName() != name || admin.getPassword() != password) {
      std::cout << "invalid username or password, please try again!\n ";
  }else {
    std::cout << "\nvoila succeeded!\n";
  }
}


void menu(Admin& admin)
{
  
int option{};
 while(1){
  std::cout << "\nchoose:\n";
  std::cout << "1. login\n";
  std::cout << "2. register\n";
  std::cout << "3. exit\n";
  std::cout << "enter your choice:";
  std::cin >> option;
  switch (option) {
    case 1:
      validation(admin);
    break;
    case 2: 
      userRegister(admin);
      std::cout << "register successful!\n";
      menu(admin);
    break;
      case 3: 
        exit(0);
      break;
    default:
        std::cout << "\ninvalid option\n";
        menu(admin);
      break;
  }
}
}

int main (int argc, char *argv[])
{
  Admin admin{};
  menu(admin);
  
  return 0;
}
